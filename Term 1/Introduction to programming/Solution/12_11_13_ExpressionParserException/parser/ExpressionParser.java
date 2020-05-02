package expression.parser;

import expression.expression.*;

import java.util.Map;

public class ExpressionParser extends BaseParser implements Parser {
    private static final int topLevel = 3;
    private static final int primeLevel = 0;
    private String lastOperator;
    private static final Map<String, Integer> priorities = Map.of(
            "+", 2,
            "-", 2,
            "*", 1,
            "/", 1,
            "<<", 3,
            ">>", 3,
            "log2", 0,
            "pow2", 0,
            ")", 4
    );
    private static final Map<Character, String> firstCharToOperator = Map.of(
            '+', "+",
            '-', "-",
            '*', "*",
            '/', "/",
            ')', ")",
            '<', "<<",
            '>', ">>",
            'l', "log2",
            'p', "pow2"
    );

    @Override
    public TripleExpression parse(String expression) {
        setSource(new StringSource(expression + ")"));
        nextChar();
        skipWhitespaces();
        final TripleExpression tripleExpression = parseLevel(topLevel);
        if (ch != '\0') {
            throw error("Unexpected close bracket");
        }
        return tripleExpression;
    }

    private CommonExpression parseLevel(int level) {
        if (level == primeLevel) {
            CommonExpression primeExpression = getPrimeExpression();
            skipWhitespaces();
            if (!testOperator()) {
                throw error("Expected operator");
            }
            return primeExpression;
        }
        CommonExpression expression = parseLevel(level - 1);
        while (lastOperator != null && priorities.get(lastOperator) == level) {
            expression = makeExpression(lastOperator, expression, parseLevel(level - 1));
        }
        if (level == topLevel) {
            if (lastOperator == null || !lastOperator.equals(")")) {
                throw error("Expected close bracket");
            }
            lastOperator = null;
        }
        return expression;
    }

    private CommonExpression getPrimeExpression() {
        if (test('(')) {
            return parseLevel(topLevel);
        } else if (test('-')) {
            skipWhitespaces();
            if (between('0', '9')) {
                return getConstExpression(true);
            } else {
                return new CheckedNegate(getPrimeExpression());
            }
        } else if (testOperator()) {
            throw error("Unexpected operator");
        } else if (between('0', '9')) {
            return getConstExpression(false);
        } else {
            return getVariableExpression();
        }
    }

    private CommonExpression getVariableExpression() {
        StringBuilder stringBuilder = new StringBuilder();
        while (between('x', 'z')) {
            stringBuilder.append(ch);
            nextChar();
        }
        if (stringBuilder.length() == 0) {
            throw error("Unsupported variable " + ch);
        }
        return new Variable(stringBuilder.toString());
    }

    private CommonExpression getLog() {
        StringBuilder stringBuilder = new StringBuilder();
        while (between('l', 'l') || between('o', 'o') || between('g', 'g') || between('2', '2')) {
            stringBuilder.append(ch);
            nextChar();
        }
        StringBuilder sb = new StringBuilder();
        if (stringBuilder.equals("log2")) {
            skipWhitespaces();
            if (between('0', '9')) {
                while (between('0', '9')) {
                    sb = new StringBuilder();
                    sb.append(ch);
                    nextChar();
                }
                return new CheckedLog2(new Const(Integer.parseInt(sb.toString())));
            } else if (between('x', 'z')) {
                while (between('x', 'z')) {
                    sb = new StringBuilder();
                    sb.append(ch);
                    nextChar();
                }
                return new CheckedLog2(new Variable(sb.toString()));
            }
        }
        return new Const(Integer.parseInt(sb.toString()));
    }

    private CommonExpression getConstExpression(boolean isNegative) {
        StringBuilder stringBuilder = new StringBuilder(isNegative ? "-" : "");
        while (between('0', '9')) {
            stringBuilder.append(ch);
            nextChar();
        }
        return new Const(Integer.parseInt(stringBuilder.toString()));
    }

    private boolean testOperator() {
        if (!firstCharToOperator.containsKey(ch)) {
            return false;
        }
        getOperator();
        skipWhitespaces();
        return true;
    }

    private void getOperator() {
        String operator = firstCharToOperator.get(ch);
        if (operator.equals("log2")) {
            getLog();
        }
        expect(operator);
        lastOperator = operator;
    }

    private CommonExpression makeExpression(String operator, CommonExpression a, CommonExpression b) {
        if (operator.equals("+")) {
            return new CheckedAdd(a, b);
        }
        if (operator.equals("-")) {
            return new CheckedSubtract(a, b);
        }
        if (operator.equals("*")) {
            return new CheckedMultiply(a, b);
        }
        if (operator.equals("/")) {
            return new CheckedDivide(a, b);
        }
        if (operator.equals(">>")) {
            return new RightShift(a, b);
        }
        if (operator.equals("<<")) {
            return new LeftShift(a, b);
        }
        if (operator.equals("pow2")) {
            return new CheckedPow2(a);
        }
        if (operator.equals("log2")) {
            return new CheckedLog2(a);
        }
        throw error("Unsupported operator: " + operator);
    }

    private void skipWhitespaces() {
        while (Character.isWhitespace(ch)) {
            nextChar();
        }
    }
}

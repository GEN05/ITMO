package expression.expression;

import expression.exceptions.NegateOverflowException;

public class CheckedNegate implements CommonExpression {
    private CommonExpression expression;

    public CheckedNegate(CommonExpression expression) {
        this.expression = expression;
    }

    private static void checkException(int x) {
        if (x == Integer.MIN_VALUE) {
            throw new NegateOverflowException(x);
        }
    }

    @Override
    public String toString() {
        return "-(" + expression.toString() + ")";
    }

    @Override
    public String toMiniString() {
        boolean hasBrackets = expression instanceof Operation;
        return "-" + (hasBrackets ? "(" : "") + expression.toMiniString() + (hasBrackets ? ")" : "");
    }

    @Override
    public int evaluate(int x) {
        return calculate(expression.evaluate(x));
    }

    @Override
    public int evaluate(int x, int y, int z) {
        return calculate(expression.evaluate(x, y, z));
    }

    @Override
    public double evaluate(double x) {
        return Double.NaN;
    }

    protected int calculate(int x) {
        checkException(x);
        return -x;
    }
}

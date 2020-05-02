package expression.expression;

import expression.exceptions.Pow2OverflowException;

public class CheckedPow2 implements CommonExpression {
    private CommonExpression expression;

    public CheckedPow2(CommonExpression expression) {
        this.expression = expression;
    }

    @Override
    public int evaluate(int x) {
        return calculate(expression.evaluate(x));
    }

    @Override
    public int evaluate(int x, int y, int z) {
        return calculate(expression.evaluate(x, y, z));
    }

    private void checkException(int a) {
        if (a >= 31) {
            throw new Pow2OverflowException(a);
        }
    }

    protected int calculate(int a) {
        checkException(a);
        int res = 1;
        for (int i = 0; i < a; i++) {
            res *= 2;
        }
        return res;
    }

    @Override
    public double evaluate(double x) {
        return Double.NaN;
    }
}
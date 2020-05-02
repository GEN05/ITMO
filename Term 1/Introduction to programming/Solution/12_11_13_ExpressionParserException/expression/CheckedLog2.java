package expression.expression;

import expression.exceptions.Log2Exception;

public class CheckedLog2 implements CommonExpression {
    private CommonExpression expression;

    public CheckedLog2(CommonExpression expression) {
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
        if (a <= 0) {
            throw new Log2Exception(a);
        }
    }

    protected int calculate(int a) {
        checkException(a);
        int res = 1;
        for (int i = 0; i < a; i++) {
            res *= 2;
            if (res > a) {
                res = i;
                break;
            }
        }
        return res;
    }

    @Override
    public double evaluate(double x) {
        return Double.NaN;
    }
}
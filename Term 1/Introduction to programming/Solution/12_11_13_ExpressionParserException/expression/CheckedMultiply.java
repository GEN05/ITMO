package expression.expression;

import expression.exceptions.MultiplyOverflowException;

public class CheckedMultiply extends Operation {

    public CheckedMultiply(CommonExpression left, CommonExpression right) {
        super(left, right, "*");
    }

    private static int myabs(int t) {
        int abs = t >> 31;
        int x = abs ^ t;
        x -= abs;
        return x;
    }

    @Override
    public double evaluate(double x) {
        double res = 1;
        for (CommonExpression unit : innerUnits) {
            res *= unit.evaluate(x);
        }
        return res;
    }

    private void checkException(int a, int b) {
        if (a != 0 && b != 0) {
            if (a == Integer.MIN_VALUE && b == -1 || a == -1 && b == Integer.MIN_VALUE) {
                throw new MultiplyOverflowException(a, b);
            } else if (a * b == Integer.MIN_VALUE && Integer.MIN_VALUE / b == a) {
            } else if ((a == Integer.MIN_VALUE && b != 1) || (a != 1 && b == Integer.MIN_VALUE)) {
                throw new MultiplyOverflowException(a, b);
            } else if (Integer.MAX_VALUE / myabs(a) < myabs(b)) {
                throw new MultiplyOverflowException(a, b);
            }
        }
    }

    @Override
    protected int calculate(int a, int b) {
        checkException(a, b);
        return a * b;
    }
}
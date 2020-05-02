package expression.expression;

import expression.exceptions.DivideByZeroException;
import expression.exceptions.DivideOverflowException;

public class CheckedDivide extends Operation {

    public CheckedDivide(CommonExpression left, CommonExpression right) {
        super(left, right, "/");
    }

    @Override
    public double evaluate(double x) {
        if (!innerUnits.isEmpty()) {
            double res = innerUnits.get(0).evaluate(x);
            for (int i = 1; i < innerUnits.size(); i++) {
                res /= innerUnits.get(i).evaluate(x);
            }
            return res;
        } else {
            return 0;
        }
    }

    private void checkException(int a, int b) {
        if (a == Integer.MIN_VALUE && b == -1) {
            throw new DivideOverflowException(a, b);
        }
        if (b == 0) {
            throw new DivideByZeroException("Divide by zero: " + a + " / " + b);
        }
    }

    @Override
    protected int calculate(int a, int b) {
        checkException(a, b);
        return a / b;
    }
}
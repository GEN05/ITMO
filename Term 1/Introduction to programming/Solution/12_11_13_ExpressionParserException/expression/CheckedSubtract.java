package expression.expression;

import expression.exceptions.SubtractOverflowException;

public class CheckedSubtract extends Operation {

    public CheckedSubtract(CommonExpression left, CommonExpression right) {
        super(left, right, "-");
    }

    @Override
    public double evaluate(double x) {
        if (!innerUnits.isEmpty()) {
            double res = innerUnits.get(0).evaluate(x);
            for (int i = 1; i < innerUnits.size(); i++) {
                res -= innerUnits.get(i).evaluate(x);
            }
            return res;
        } else {
            return 0;
        }
    }

    private void checkException(int a, int b) {
        if (b > 0 && Integer.MIN_VALUE + b > a) {
            throw new SubtractOverflowException(a, b);
        } else if (b < 0 && Integer.MAX_VALUE + b < a) {
            throw new SubtractOverflowException(a, b);
        }
    }

    @Override
    protected int calculate(int a, int b) {
        checkException(a, b);
        return a - b;
    }
}
package expression.expression;

import expression.exceptions.AddOverflowException;

public class CheckedAdd extends Operation {

    public CheckedAdd(CommonExpression left, CommonExpression right) {
        super(left, right, "+");
    }

    @Override
    public double evaluate(double x) {
        double res = 0;
        for (CommonExpression unit : innerUnits) {
            res += unit.evaluate(x);
        }
        return res;
    }

    private void checkException(int a, int b) {
        if (b > 0 && Integer.MAX_VALUE - b < a) {
            throw new AddOverflowException(a, b);
        } else if (b < 0 && Integer.MIN_VALUE - b > a) {
            throw new AddOverflowException(a, b);
        }
    }

    @Override
    protected int calculate(int a, int b) {
        checkException(a, b);
        return a + b;
    }
}
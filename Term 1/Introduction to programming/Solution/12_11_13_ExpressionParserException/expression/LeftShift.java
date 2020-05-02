package expression.expression;

public class LeftShift extends Operation {
    public LeftShift(CommonExpression left, CommonExpression right) {
        super(left, right, "<<");
    }

    @Override
    public int evaluate(int x) {
        return evaluate(x, 0, 0);
    }

    @Override
    public double evaluate(double x) {
        return Double.NaN;
    }

    @Override
    public int evaluate(int x, int y, int z) {
        if (!innerUnits.isEmpty()) {
            int res = innerUnits.get(0).evaluate(x, y, z);
            for (int i = 1; i < innerUnits.size(); i++) {
                res <<= innerUnits.get(i).evaluate(x, y, z);
            }
            return res;
        } else {
            return 0;
        }
    }

    @Override
    protected int calculate(int a, int b) {
        return a << b;
    }
}

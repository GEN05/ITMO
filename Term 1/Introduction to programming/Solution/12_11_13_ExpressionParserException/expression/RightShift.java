package expression.expression;

public class RightShift extends Operation {
    public RightShift(CommonExpression left, CommonExpression right) {
        super(left, right, ">>");
    }

    @Override
    public double evaluate(double x) {
        return Double.NaN;
    }

    @Override
    protected int calculate(int a, int b) {
        return a >> b;
    }
}

package expression.expression;

public class Const implements CommonExpression {
    private final boolean flag;
    private double doubleValue;
    private int intValue;

    public Const(double value) {
        this.doubleValue = value;
        flag = true;
    }

    public Const(int value) {
        this.intValue = value;
        flag = false;
    }

    @Override
    public int evaluate(int x) {
        return evaluate(x, 0, 0);
    }

    @Override
    public int evaluate(int x, int y, int z) {
        return flag ? (int) doubleValue : intValue;
    }

    @Override
    public double evaluate(double x) {
        return flag ? doubleValue : intValue;
    }

    @Override
    public String toString() {
        return flag ? Double.toString(doubleValue) : Integer.toString(intValue);
    }

    @Override
    public int hashCode() {
        return flag ? (int) doubleValue : intValue;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj != null && this.getClass().equals(obj.getClass())) {
            Const other = (Const) obj;
            if (this.flag == other.flag) {
                return (flag) ? (this.doubleValue == other.doubleValue) : (this.intValue == other.intValue);
            } else {
                return false;
            }
        }
        return false;
    }
}
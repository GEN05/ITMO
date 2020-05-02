package expression;

import java.text.DecimalFormat;
import java.text.NumberFormat;

public class Const implements ExpressionModification {

    private static final NumberFormat FORMAT;

    static {
        FORMAT = DecimalFormat.getInstance();
        FORMAT.setGroupingUsed(false);
    }

    private double value;

    Const(int value) {
        this.value = value;
    }

    Const(double value) {
        this.value = value;
    }

    @Override
    public int evaluate(int x) {
        return (int) value;
    }

    @Override
    public double evaluate(double x) {
        return value;
    }

    @Override
    public String toString() {
        return FORMAT.format(value);
    }

    @Override
    public boolean equals(Object o) {
        if (o == this) {
            return true;
        }

        if (o == null || o.getClass() != this.getClass()) {
            return false;
        }

        Const c = (Const) o;
        return c.value == value;
    }

    @Override
    public int hashCode() {
        return Double.hashCode(value);
    }
}

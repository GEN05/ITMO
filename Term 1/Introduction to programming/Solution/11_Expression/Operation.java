package expression;

public abstract class Operation implements ExpressionModification {

    private ExpressionModification par1;
    private ExpressionModification par2;

    Operation(ExpressionModification par1, ExpressionModification par2) {
        this.par1 = par1;
        this.par2 = par2;
    }

    abstract char getOperation();

    @Override
    public String toString() {
        return "(" + par1 + ' ' + getOperation() + ' ' + par2 + ')';
    }

    @Override
    public boolean equals(Object o) {
        if (o == this) {
            return true;
        }
        if (o == null || o.getClass() != this.getClass()) {
            return false;
        }

        Operation bo = (Operation) o;

        return bo.par1.equals(this.par1) && bo.par2.equals(this.par2);
    }

    public int evaluate(int x) {
        return evaluate(par1.evaluate(x), par2.evaluate(x));
    }

    public double evaluate(double x) {
        return evaluate(par1.evaluate(x), par2.evaluate(x));
    }

    protected abstract int evaluate(int x, int y);

    protected abstract double evaluate(double x, double y);

    @Override
    public int hashCode() {
        return 3 * par1.hashCode() + 5 * par2.hashCode() + 7 * getClass().hashCode();
    }
}

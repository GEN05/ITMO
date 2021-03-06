package expression;

public class Multiply extends Operation {

    Multiply(ExpressionModification par1, ExpressionModification par2) {
        super(par1, par2);
    }

    @Override
    char getOperation() {
        return '*';
    }

    @Override
    public int evaluate(int x, int y) {
        return x * y;
    }

    @Override
    public double evaluate(double x, double y) {
        return x * y;
    }
}

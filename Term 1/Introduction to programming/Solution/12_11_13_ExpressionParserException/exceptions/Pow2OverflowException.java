package expression.exceptions;

public class Pow2OverflowException extends OperateOverflowException {
    public Pow2OverflowException(int x) {
        super("pow2", "pow2 " + x);
    }
}

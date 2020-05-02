package expression.exceptions;

public class Log2Exception extends OperateOverflowException {
    public Log2Exception(int x) {
        super("Log2", "log2" + x);
    }
}
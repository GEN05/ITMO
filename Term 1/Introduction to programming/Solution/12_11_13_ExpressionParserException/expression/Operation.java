package expression.expression;

import java.util.List;
import java.util.Objects;

public abstract class Operation implements CommonExpression {
    private final String type;
    List<CommonExpression> innerUnits;

    Operation(CommonExpression left, CommonExpression right, String type) {
        this.type = type;
        innerUnits = List.of(left, right);
    }

    @Override
    public int evaluate(int x) {
        return calculate(innerUnits.get(0).evaluate(x), innerUnits.get(1).evaluate(x));
    }

    @Override
    public int evaluate(int x, int y, int z) {
        return calculate(innerUnits.get(0).evaluate(x, y, z), innerUnits.get(1).evaluate(x, y, z));
    }

    protected abstract int calculate(int a, int b);

    @Override
    public String toString() {
        if (!innerUnits.isEmpty()) {
            StringBuilder toReturn = new StringBuilder();
            toReturn.append('(');
            toReturn.append(innerUnits.get(0).toString());
            for (int i = 1; i < innerUnits.size(); i++) {
                toReturn.append(" ").append(type).append(" ");
                toReturn.append(innerUnits.get(i).toString());
            }
            toReturn.append(')');
            return toReturn.toString();
        } else {
            return "";
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (obj != null && this.getClass().equals(obj.getClass())) {
            Operation other = (Operation) obj;
            return Objects.deepEquals(this.innerUnits, other.innerUnits);
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        for (CommonExpression unit : innerUnits) {
            hash *= 3;
            hash += unit.hashCode() * 5 + this.type.hashCode();
        }
        return hash;
    }
}
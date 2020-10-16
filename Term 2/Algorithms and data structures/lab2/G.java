import java.util.Random;
import java.util.Scanner;

public class G {
    public static void main(String[] args) {
        NODE root = null;
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        String operation;

        for (int i = 1; i <= n; i++) {
            root = insert(root, i, i);
        }
        long left, right;
        for (int i = 0; i < m; i++) {
            left = scanner.nextLong();
            right = scanner.nextLong();
            root = move(root, left, right);
        }
        write(root);
    }

    public static void resize(NODE root) {
        if (root != null) {
            root.size = 1 + size(root.left) + size(root.right);
        }
    }

    public static NODE merge(NODE A, NODE B) {
        if (A == null) {
            resize(B);
            return B;
        }
        if (B == null) {
            resize(A);
            return A;
        }
        if (A.priority > B.priority) {
            A.right = merge(A.right, B);
            resize(A);
            return A;
        } else {
            B.left = merge(A, B.left);
            resize(B);
            return B;
        }
    }

    public static long size(NODE root) {
        return root == null ? 0 : root.size;
    }

    public static Pair split(NODE root, long value) {
        if (root == null) return new Pair(null, null);

        if (size(root.left) < value) {
            Pair pair = split(root.right, value - size(root.left) - 1);
            root.right = pair.first;
            resize(root);
            return new Pair(root, pair.second);
        } else {
            Pair pair = split(root.left, value);
            root.left = pair.second;
            resize(root);
            return new Pair(pair.first, root);
        }
    }

    public static NODE insert(NODE root, long key, long pos) {
        Pair pair = split(root, pos);
        NODE temp = new NODE(key, null, null);
        temp = merge(pair.first, temp);
        return merge(temp, pair.second);
    }

    public static NODE remove(NODE root, long position) {
        Pair pair1 = split(root, position);
        Pair pair2 = split(pair1.first, position - 1);
        return merge(pair2.first, pair1.second);
    }

    public static NODE move(NODE root, long left, long right) {
        Pair pair1 = split(root, left - 1);
        Pair pair2 = split(pair1.second, right - left + 1);
        return merge(pair2.first, merge(pair1.first, pair2.second));
    }

    public static void write(NODE root) {
        if (root != null) {
            write(root.left);
            System.out.print(root.value + " ");
            write(root.right);
        }
    }

    public static class Pair {
        NODE first;
        NODE second;

        Pair(NODE first, NODE second) {
            this.first = first;
            this.second = second;
        }
    }

    public static class NODE {
        public long value;
        public long priority;
        public long size = 1;
        public NODE left;
        public NODE right;

        NODE(long value, NODE left, NODE right) {
            Random random = new Random();
            this.value = value;
            this.priority = random.nextInt();
            this.left = left;
            this.right = right;
        }
    }
}
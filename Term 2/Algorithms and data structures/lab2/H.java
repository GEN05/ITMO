import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

public class H {
    protected static void push(NODE root) {
        if (root == null)
            return;
        if (root.reverse) {
            NODE temp = root.right;
            root.right = root.left;
            root.left = temp;
            if (root.left != null) root.left.reverse = !root.left.reverse;
            if (root.right != null) root.right.reverse = !root.right.reverse;
        }
        root.reverse = false;
    }

    protected static NODE merge(NODE A, NODE B) {
        push(A);
        push(B);
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

    protected static Pair split(NODE root, long value) {
        if (root == null) return new Pair(null, null);
        push(root);
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

    protected static long size(NODE root) {
        return root == null ? 0 : root.size;
    }

    protected static void resize(NODE root) {
        if (root != null) root.size = 1 + size(root.left) + size(root.right);
    }

    protected static NODE reverse(NODE T, long left, long right) {
        Pair pair1 = split(T, left - 1);
        Pair pair2 = split(pair1.second, right - left + 1);
        pair2.first.reverse = !pair2.first.reverse;
        return merge(merge(pair1.first, pair2.first), pair2.second);
    }

    protected static NODE insert(NODE root, long key, long pos) {
        Pair pair = split(root, pos);
        NODE temp = new NODE(key, null, null);
        temp = merge(pair.first, temp);
        return merge(temp, pair.second);
    }

    protected static void write(NODE root) {
        if (root != null) {
            push(root);
            write(root.left);
            System.out.print(root.value + " ");
            write(root.right);
        }
    }

    public static void main(String[] args) {
        NODE root = null;
        MyScanner scanner = new MyScanner(System.in);
        long n = Long.parseLong(scanner.next());
        long m = Long.parseLong(scanner.next());
        for (int i = 1; i <= n; i++) root = insert(root, i, i);
        long left, right;
        for (int i = 0; i < m; i++) {
            left = Long.parseLong(scanner.next());
            right = Long.parseLong(scanner.next());
            root = reverse(root, left, right);
        }
        write(root);
    }

    protected static class NODE {
        protected long value;
        protected long priority;
        protected long size = 1;
        protected NODE left;
        protected NODE right;
        protected boolean reverse;

        NODE(long value, NODE left, NODE right) {
            Random random = new Random();
            this.value = value;
            this.priority = random.nextInt();
            this.left = left;
            this.right = right;
            this.reverse = false;
        }
    }

    protected static class Pair {
        NODE first;
        NODE second;

        Pair(NODE first, NODE second) {
            this.first = first;
            this.second = second;
        }
    }

    private static class MyScanner {
        BufferedReader bufferedReader;
        StringTokenizer stringTokenizer;

        MyScanner(InputStream input) {
            bufferedReader = new BufferedReader(new InputStreamReader(input));
        }

        String next() {
            while ((stringTokenizer == null) || !stringTokenizer.hasMoreElements()) try {
                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            } catch (Exception e) {
                return null;
            }
            return stringTokenizer.nextToken();
        }
    }
}
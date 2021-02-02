import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B {
    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        String string = scanner.next();
        ArrayList<Integer> prefixFunction = new ArrayList<>();
        for (int i = 0; i < string.length(); i++)
            prefixFunction.add(0);
        prefixFunction(string, prefixFunction);
        StringBuilder stringBuilder = new StringBuilder();
        for (int i : prefixFunction)
            stringBuilder.append(i).append(" ");
        System.out.print(stringBuilder);
    }

    private static void prefixFunction(String string, ArrayList<Integer> prefixFunction) {
        for (int i = 1; i < string.length(); i++) {
            int j = prefixFunction.get(i - 1);
            while (j > 0 && string.charAt(i) != string.charAt(j))
                j = prefixFunction.get(j - 1);
            if (string.charAt(i) == string.charAt(j))
                prefixFunction.set(i, ++j);
        }
    }
}

class FastReader {
    BufferedReader br;
    StringTokenizer st;

    FastReader(InputStream input) {
        br = new BufferedReader(new InputStreamReader(input));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

}

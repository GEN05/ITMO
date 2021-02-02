import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Math.min;


public class C {
    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        String string = scanner.next();
        ArrayList<Integer> zFunction = new ArrayList<>();
        for (int i = 0; i < string.length(); i++)
            zFunction.add(0);
        zFunction(zFunction, string);
        StringBuilder answer = new StringBuilder();
        for (int i = 1; i < string.length(); i++)
            answer.append(zFunction.get(i)).append(" ");
        System.out.print(answer);
    }

    private static void zFunction(ArrayList<Integer> zFunction, String string) {
        int left = 0;
        int right = 0;
        for (int i = 1; i < string.length(); i++) {
            zFunction.set(i, min(right - i, zFunction.get(i - left)));
            if (zFunction.get(i) < 0)
                zFunction.set(i, 0);
            while (zFunction.get(i) + i < string.length() && string.charAt(zFunction.get(i)) == string.charAt(i + zFunction.get(i)))
                zFunction.set(i, zFunction.get(i) + 1);
            if (i + zFunction.get(i) - 1 > right) {
                left = i;
                right = i + zFunction.get(i);
            }
        }
    }

    static class FastReader {
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
}


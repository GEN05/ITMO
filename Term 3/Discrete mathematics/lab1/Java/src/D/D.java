package D;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D {

    static String ZERO = "0";
    static String ONE = "1";

    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        int n = scanner.nextInt();
        int[][] graph = new int[n][n];
        try {
            read(n, graph, scanner);
        } catch (Exception e) {
            e.printStackTrace();
        }
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++)
            findTheRightLamp(i, result, graph);
        int i = n - 1;
        while (i > 0 && graph[result.get(i) - 1][result.get(0) - 1] == 0)
            i--;
        if (i != n - 1) {
            boolean isCycle = false;
            while (!isCycle) {
                isCycle = true;
                for (int j = i + 1; j < n; j++) {
                    for (int k = 1; k < i + 1; k++) {
                        if (graph[result.get(j) - 1][result.get(k) - 1] == 0)
                            continue;
                        ArrayList<Integer> resultCopy = new ArrayList<>(result.subList(i + 1, j + 1));
                        for (int l = 0; l >= k - i; l--)
                            result.set(l + j, result.get(l + i));
                        for (int l = 0; l < j - i; l++) {
                            result.set(l + k, resultCopy.get(l));
                        }
                        i = j;
                        isCycle = false;
                        break;
                    }
                    if (!isCycle) {
                        break;
                    }
                }
            }
        }
        for (Integer integer : result) System.out.print(integer + " ");
    }

    private static void findTheRightLamp(int nowLamp, ArrayList<Integer> lamps, int[][] graph) {    // from task C
        int left = 0;
        int right = nowLamp;
        while (left < right) {
            int middle = (left + right) / 2;
            if (graph[nowLamp][lamps.get(middle) - 1] == 1)
                right = middle;
            else
                left = middle + 1;
        }
        lamps.add(left, nowLamp + 1);
    }

    static void read(int n, int[][] graph, FastReader scanner) throws Exception {   // From task A
        //scanner.next();
        for (int i = 1; i < n; i++) {
            String string = scanner.next();
            for (int j = 0; j < string.length(); j++) {
                if (string.substring(j, j + 1).equals(ZERO)) {
                    graph[i][j] = 0;
                    graph[j][i] = 0;
                } else if (string.substring(j, j + 1).equals(ONE)) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                } else
                    throw new Exception("Illegal symbol");
            }
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
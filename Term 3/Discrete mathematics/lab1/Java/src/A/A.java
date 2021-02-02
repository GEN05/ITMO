package A;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {
    static String ZERO = "0";
    static String ONE = "1";

    static void at(ArrayDeque<Integer> deque, int index, int value) {
        ArrayDeque<Integer> temp = new ArrayDeque<>();
        for (int i = 0; i <= index; i++)
            temp.add(deque.removeFirst());
        deque.addFirst(value);
        for (int i = 0; i < temp.size(); i++)
            deque.addFirst(temp.removeFirst());
    }

    static int get(ArrayDeque<Integer> deque, int index) {
        ArrayDeque<Integer> temp = new ArrayDeque<>();
        int answer;
        for (int i = 0; i < index; i++)
            temp.add(deque.removeFirst());
        assert !deque.isEmpty();
        answer = deque.peekFirst();
        for (int i = 0; i < temp.size(); i++)
            deque.addFirst(temp.removeFirst());
        return answer;
    }

    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        int n = scanner.nextInt();
        int[][] graph = new int[n][n];
        try {
            read(n, graph, scanner);
        } catch (Exception e) {
            e.printStackTrace();
        }
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        for (int i = 0; i < n; i++)
            deque.add(i);
//        at(deque, 2, 228);
//        writeQueue(deque);
//        System.out.println(get(deque, 2));
        for (int i = 0; i < n * (n - 1); i++) {
            if (graph[deque.getFirst()][get(deque, 1)] == 0) {
                int j = 2;
                while (graph[deque.getFirst()][get(deque, j)] == 0 ||
                        graph[get(deque, 1)][get(deque, j + 1)] == 0)
                    j++;
                // Место для вашего скатывания (Таска В)
                reverse(deque, j);
            }
            deque.add(deque.removeFirst());
        }
        writeQueue(deque);
        //for (auto i : hui)
    }

    private static void reverse(ArrayDeque<Integer> deque, int end) {
        ArrayList<Integer> temp = new ArrayList<>();
        for (int i = 1; i <= end; i++)
            temp.add(get(deque, i));
        Collections.reverse(temp);
        for (int i = 1; i <= end; i++)
            at(deque, i, temp.remove(0));
    }

    static void read(int n, int[][] graph, FastReader scanner) throws Exception {
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

    @SuppressWarnings("unused")
    static void writeGraph(int[][] graph) {
        for (int[] i : graph) {
            for (int j : i)
                System.out.print(j + " ");
            System.out.println();
        }
    }

    static void writeQueue(ArrayDeque<Integer> deque) {
        StringBuilder answer = new StringBuilder();
        for (int j : deque)
            answer.append(j + 1).append(" ");
        System.out.print(answer);
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

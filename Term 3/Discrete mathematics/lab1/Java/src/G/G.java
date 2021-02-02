package G;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class G {
    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        int vertexCount = scanner.nextInt();
        int edgeCount = scanner.nextInt();
        boolean[] used = new boolean[vertexCount];
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        ArrayList<TreeSet<Integer>> notAvailableColor = new ArrayList<>();
        for (int i = 0; i < vertexCount; i++) {
            graph.add(new ArrayList<>());
            notAvailableColor.add(new TreeSet<>());
        }
        for (int i = 0; i < edgeCount; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(--to);
            graph.get(to).add(from);
        }
        int[] answer = new int[vertexCount];
        paint(graph, notAvailableColor, answer, used, 1);
        int max = 0;
        for (int i = 0; i < vertexCount; i++)
            if (max < answer[i])
                max = answer[i];
        if (max % 2 == 0)
            max++;
        PrintWriter printWriter = new PrintWriter(System.out);
        printWriter.println(max);
        for (int i : answer)
            printWriter.println(i);
        printWriter.close();
    }

    private static void paint(ArrayList<ArrayList<Integer>> graph, ArrayList<TreeSet<Integer>> notAvailableColor,
                              int[] answer, boolean[] used, int index) {
        used[index] = true;
        TreeSet<Integer> temp = new TreeSet<>();
        int color = getMinimumColor(notAvailableColor, index, temp);
        answer[index] = color;
        int size = graph.get(index).size();
        for (int i = 0; i < size; i++)
            notAvailableColor.get(graph.get(index).get(i)).add(color);
        for (int i = 0; i < size; i++) {
            int to = graph.get(index).get(i);
            if (!used[to])
                paint(graph, notAvailableColor, answer, used, to);
        }
    }

    static int getMinimumColor(ArrayList<TreeSet<Integer>> notAvailableColor, int index, TreeSet<Integer> temp) {
        if (notAvailableColor.get(index).isEmpty())
            return 1;
        else if (notAvailableColor.get(index).size() == 1) {
            if (notAvailableColor.get(index).first() == 1)
                return 2;
            else
                return 1;
        } else {
            int i = 1;
            while (!notAvailableColor.get(index).isEmpty()) {
                //noinspection ConstantConditions
                int first = notAvailableColor.get(index).pollFirst();
                temp.add(first);
                if (i != first) {
                    revert(notAvailableColor, temp, index);
                    return i;
                }
                if (notAvailableColor.get(index).isEmpty()) {
                    revert(notAvailableColor, temp, index);
                    return first + 1;
                }
                i++;
            }
        }
        revert(notAvailableColor, temp, index);
        return 1;
    }

    static void revert(ArrayList<TreeSet<Integer>> notAvailableColor, TreeSet<Integer> temp, int index) {
        while (!temp.isEmpty())
            notAvailableColor.get(index).add(temp.pollFirst());
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
/*

5 6
1 2
1 4
2 5
5 4
3 5
3 4

3

4


 */
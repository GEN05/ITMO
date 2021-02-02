package E;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E {

    static void treeToPrufer(ArrayList<ArrayList<Integer>> graph, ArrayList<Integer> prufer, TreeSet<Integer> leaf,
                             int[] sizes) {
        //noinspection ConstantConditions
        int now = leaf.pollFirst();
        int incidentVertex = -1;
        for (int i = 0; i < graph.get(now).size(); i++) {
            int temp = graph.get(now).get(i);
            if (sizes[temp] > 0) {
                incidentVertex = temp;
                break;
            }
        }
        prufer.add(incidentVertex);
        sizes[now] = 0;
        sizes[incidentVertex]--;
        if (sizes[incidentVertex] == 1)
            leaf.add(incidentVertex);
    }


    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        int n = scanner.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        TreeSet<Integer> leaf = new TreeSet<>();
        ArrayList<Integer> prufer = new ArrayList<>();
        int[] sizes = new int[n];
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<>());
        for (int i = 0; i < n - 1; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(--to);
            sizes[from]++;
            graph.get(to).add(from);
            sizes[to]++;
        }
        for (int i = 0; i < n; i++)
            if (graph.get(i).size() == 1)
                leaf.add(i);
        for (int i = 0; i < n - 2; i++) treeToPrufer(graph, prufer, leaf, sizes);
        StringBuilder answer = new StringBuilder();
        prufer.forEach(integer -> answer.append(integer + 1).append(" "));
        System.out.println(answer);
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

5
1 2
2 3
4 3
3 5

 */
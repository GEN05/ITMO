package F;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class F {

    static void pruferToTree(ArrayList<ArrayList<Integer>> graph, ArrayList<Integer> prufer, int graphSize) {
        ArrayList<Integer> powers = new ArrayList<>();
        for (int i = 0; i < graphSize; i++)
            powers.add(1);
        for (int i = 0; i < graphSize - 2; i++)
            powers.set(prufer.get(i), powers.get(prufer.get(i)) + 1);
        int iterator = 0;
        while (iterator < graphSize && powers.get(iterator) != 1)
            iterator++;
        int leaf = iterator;
        for (int i = 0; i < graphSize - 2; i++) {
            int vertex = prufer.get(i);
            graph.get(leaf).add(vertex);
//            graph.get(vertex).add(leaf);
            powers.set(leaf, powers.get(leaf) - 1);
            powers.set(vertex, powers.get(vertex) - 1);
            if (powers.get(vertex) == 1 && vertex < iterator)
                leaf = vertex;
            else {
                iterator++;
                while (iterator < graphSize && powers.get(iterator) != 1)
                    iterator++;
                leaf = iterator;
            }
        }
        for (int i = 0; i < graphSize - 1; i++) {
            if (powers.get(i) == 1) {
                graph.get(i).add(graphSize - 1);
//                graph.get(graphSize - 1).add(i);
            }
        }
    }


    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        int graphSize = scanner.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        ArrayList<Integer> prufer = new ArrayList<>();
        for (int i = 0; i < graphSize; i++)
            graph.add(new ArrayList<>());
        for (int i = 0; i < graphSize - 2; i++) {
            int element = scanner.nextInt();
            prufer.add(--element);
        }
        pruferToTree(graph, prufer, graphSize);
//        System.out.println(Arrays.toString(graph.toArray()));
        for (int i = 0; i < graphSize; i++)
            for (int j = 0; j < graph.get(i).size(); j++)
                System.out.println((i + 1) + " " + (graph.get(i).get(j) + 1));
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
2 3 3

7
6 2 2 3 6

 */
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class C {
    public static void main(String[] args) throws IOException {
        File file = new File("matching.in");
        FastReader scanner = new FastReader(new FileInputStream(file));

        int n = scanner.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        ArrayList<Boolean> used = new ArrayList<>();
        Vertex[] order = new Vertex[n];
        ArrayList<Integer> match = new ArrayList<>();
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
            used.add(false);
            order[i] = new Vertex(i, scanner.nextInt());
            match.add(-1);
            answer.add(-1);
        }

        for (int i = 0; i < n; i++) {
            int size = scanner.nextInt();
            for (int j = 0; j < size; j++)
                graph.get(i).add(scanner.nextInt() - 1);
        }

        Arrays.sort(order, new SortOrder());

        for (int i = 0; i < n; i++) {
            int v = order[i].vertex;
            int bound = used.size();
            for (int j = 0; j < bound; j++) {
                used.set(j, false);
            }
            kuhn(v, graph, used, match);
        }
        for (int i = 0; i < n; i++)
            if (match.get(i) != -1)
                answer.set(match.get(i), i);

        FileWriter writer = new FileWriter("matching.out");
        for (Integer integer : answer) writer.write((integer + 1) + " ");
        writer.close();
    }

    private static boolean kuhn(int v, ArrayList<ArrayList<Integer>> graph, ArrayList<Boolean> used,
                                ArrayList<Integer> match) {
        if (used.get(v)) return false;
        used.set(v, true);
        for (int i = 0; i < graph.get(v).size(); i++) {
            if (match.get(graph.get(v).get(i)) == -1 || kuhn(match.get(graph.get(v).get(i)), graph, used, match)) {
                match.set(graph.get(v).get(i), v);
                return true;
            }
        }
        return false;
    }

    static class SortOrder implements Comparator<Vertex> {
        public int compare(Vertex a, Vertex b) {
            return Integer.compare(b.getWeight(), a.getWeight());
        }
    }

    public static class Vertex {
        int vertex;
        int weight;

        public Vertex(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }

        public int getWeight() {
            return weight;
        }

    }

    static class FastReader implements AutoCloseable {
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

        @Override
        public void close() throws Exception {
            br.close();
        }
    }
}
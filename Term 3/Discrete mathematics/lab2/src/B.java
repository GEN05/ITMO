import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        File file = new File("destroy.in");
        FastReader scanner = new FastReader(new FileInputStream(file));
        int n, m;
        long sum;
        n = scanner.nextInt();
        m = scanner.nextInt();
        Edge[] graph = new Edge[m];
        sum = scanner.nextLong();
        for (int i = 0; i < m; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            long weight = scanner.nextLong();
            graph[i] = new Edge(from - 1, to - 1, -weight, i + 1);
        }
        Arrays.sort(graph, new SortGraph());
        ArrayList<Integer> p = new ArrayList<>();
        for (int i = 0; i < n; i++)
            p.add(i);

        long ans = 0;
        ArrayList<Integer> mst = new ArrayList<>();
        for (Edge edge : graph) {
            int from = edge.getFrom();
            int to = edge.getTo();
            long weight = edge.getWeight();
            int index = edge.getIndex();
            if (find(from, p) == find(to, p))
                continue;
            ans += weight;
            mst.add(index);
            join(from, to, p);
        }
        for (Edge edge : graph) edge.setWeight(-edge.getWeight());
        Arrays.sort(graph, new SortGraph());
        TreeSet<Integer> answer = new TreeSet<>();
        for (Edge edge : graph) {
            if (mst.contains(edge.getIndex()))
                continue;
            if (sum - edge.getWeight() >= 0) {
                answer.add(edge.getIndex());
                sum -= edge.getWeight();
            } else
                break;
        }

        FileWriter writer = new FileWriter("destroy.out");
//        writer.write(String.valueOf(ans));
//        writer.write("\n");
//        for (Integer integer : mst) {
//            writer.write(String.valueOf(integer));
//            writer.write(" ");
//        }
        int size = answer.size();
        writer.write(String.valueOf(size));
        writer.write("\n");
        for (int i = 0; i < size; i++) {
            writer.write(String.valueOf(answer.pollFirst()));
            writer.write(" ");
        }
        writer.close();
    }

    private static void join(int from, int to, ArrayList<Integer> p) {
        from = find(from, p);
        to = find(to, p);
        p.set(to, from);
    }

    private static int find(int from, ArrayList<Integer> p) {
        if (p.get(from) != from) {
            p.set(from, find(p.get(from), p));
            return p.get(from);
        }
        return from;
    }

    static class SortGraph implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            return Long.compare(a.getWeight(), b.getWeight());
        }
    }

    static public class Edge {
        int from;
        int to;
        long weight;
        int index;

        public Edge(int from, int to, long weight, int index) {
            this.from = from;
            this.to = to;
            this.weight = weight;
            this.index = index;
        }

        public int getIndex() {
            return index;
        }

        public int getFrom() {
            return from;
        }

        public int getTo() {
            return to;
        }

        public long getWeight() {
            return weight;
        }

        public void setWeight(long weight) {
            this.weight = weight;
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

        long nextLong() {
            return Long.parseLong(next());
        }

        @Override
        public void close() throws Exception {
            br.close();
        }
    }
}

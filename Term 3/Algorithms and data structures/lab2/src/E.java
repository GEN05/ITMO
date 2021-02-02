import java.util.ArrayList;
import java.util.Scanner;

public class E {

    private static final long INF = Long.MAX_VALUE;

    static void dfs(int vertex, ArrayList<ArrayList<Edge>> graph, boolean[] used) {
        if (used[vertex])
            return;
        used[vertex] = true;
        for (Edge edge : graph.get(vertex))
            dfs(edge.to, graph, used);
    }

    public static void main(String[] argc) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt(), s = scanner.nextInt();
        ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
        boolean[] used = new boolean[n];
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<>());
        for (int i = 0; i < m; i++)
            graph.get(scanner.nextInt() - 1).add(new Edge(scanner.nextInt() - 1, scanner.nextLong()));

        ArrayList<Long> distance = new ArrayList<>();
        for (int i = 0; i < n; i++)
            distance.add(INF);
        distance.set(--s, 0L);

        for (int i = 0; i < n; i++) {
            boolean flag = true;
            for (int u = 0; u < n; u++)
                for (Edge edge : graph.get(u))
                    if (distance.get(u) < INF)
                        if (distance.get(u) + edge.weight < distance.get(edge.to)) {
                            distance.set(edge.to, distance.get(u) + edge.weight);
                            flag = false;
                        }
            if (flag) break;
        }
        for (int u = 0; u < n; u++)
            for (Edge edge : graph.get(u))
                if (distance.get(u) < INF && distance.get(edge.to) > distance.get(u) + edge.weight && !used[u])
                    dfs(u, graph, used);

        for (int u = 0; u < n; u++) {
            if (distance.get(u) == INF) {
                System.out.println("*");
                continue;
            }
            if (used[u]) {
                System.out.println("-");
                continue;
            }
            System.out.println(distance.get(u));
        }
    }

    static class Edge {
        int to;
        long weight;

        public Edge(int to, long weight) {
            this.to = to;
            this.weight = weight;
        }
    }
}

import java.util.ArrayList;
import java.util.Scanner;

import static java.lang.Integer.min;

public class D {
    private static final int INF = (int) 2E9;

    public static void main(String[] argc) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt(), k = scanner.nextInt(), s = scanner.nextInt();
        ArrayList<Edge> graph = new ArrayList<>();
        ArrayList<ArrayList<Integer>> distance = new ArrayList<>();
        for (int i = 0; i <= k; i++) {
            distance.add(new ArrayList<>());
            for (int j = 0; j < n; j++)
                distance.get(i).add(INF);
        }

        for (int i = 0; i < m; i++) {
            int from = scanner.nextInt(), to = scanner.nextInt();
            graph.add(new Edge(--from, --to, scanner.nextInt()));
        }
        findKPaths(m, --s, k, graph, distance);
        for (int i = 0; i < n; i++) {
            if (distance.get(k).get(i) == INF) System.out.println(-1);
            else System.out.println(distance.get(k).get(i));
        }
    }

    static void findKPaths(int m, int s, int k, ArrayList<Edge> graph, ArrayList<ArrayList<Integer>> distance) {
        distance.get(0).set(s, 0);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                if (distance.get(i).get(graph.get(j).from) < INF)
                    distance.get(i + 1).set(graph.get(j).to, min(distance.get(i + 1).get(graph.get(j).to),
                            distance.get(i).get(graph.get(j).from) + graph.get(j).weight));
            }
        }
    }

    static class Edge {
        int from;
        int to;
        int weight;

        public Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }
}

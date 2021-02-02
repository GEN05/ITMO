import java.util.ArrayList;
import java.util.Scanner;

import static java.lang.Integer.max;
import static java.util.Collections.reverse;

public class C {
    private static final int INF = (int) 1E9;

    public static void findNegativeCycle(int size, ArrayList<Edge> graph, ArrayList<Integer> distance,
                                         ArrayList<Integer> p) {
        int x = 0;
        distance.set(0, 0);
        for (int i = 0; i < size; i++) {
            x = -1;
            for (Edge edge : graph) {
                if (distance.get(edge.to) > distance.get(edge.from) + edge.weight) {
                    distance.set(edge.to, max(-1 * INF, distance.get(edge.from) + edge.weight));
                    p.set(edge.to, edge.from);
                    x = edge.to;
                }
            }
        }
        if (x == -1)
            System.out.println("NO");
        else {
            System.out.println("YES");
            for (int i = 0; i < size; ++i)
                x = p.get(x);
            ArrayList<Integer> cycle = new ArrayList<>();
            int cur = x;
            do {
                cycle.add(cur);
                cur = p.get(cur);
            } while (cur != x || cycle.size() <= 1);
            reverse(cycle);
            System.out.println(cycle.size());
            for (int i : cycle) System.out.print((i + 1) + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        ArrayList<Edge> graph = new ArrayList<>();
        ArrayList<Integer> distance = new ArrayList<>();
        ArrayList<Integer> p = new ArrayList<>();
        for (int from = 0; from < size; from++) {
            distance.add(INF);
            p.add(-1);
            for (int to = 0; to < size; to++) {
                int weight = scanner.nextInt();
                if (weight != 1E5)
                    graph.add(new Edge(from, to, weight));
            }
        }
        findNegativeCycle(size, graph, distance, p);
    }

    public static class Edge {
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

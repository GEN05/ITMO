import java.util.ArrayList;
import java.util.Scanner;

import static java.lang.Math.sqrt;

public class I {

    private static final int INF = 2000000001;

    static double distance(int x, int y, ArrayList<Pair> graph) {
        if (x == y)
            return INF;
        Pair a = graph.get(x);
        Pair b = graph.get(y);
        return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    }

    static double solve(int n, boolean[] used, ArrayList<Double> minRib,
                        ArrayList<Integer> selectedRib, ArrayList<Pair> graph) {
        double answer = 0;
        for (int i = 0; i < n; i++) {
            int v = -1;
            for (int j = 0; j < n; j++)
                if (v == -1 || minRib.get(v) > minRib.get(j))
                    if (!used[j])
                        v = j;

            used[v] = true;
            if (selectedRib.get(v) != -1)
                answer += distance(v, selectedRib.get(v), graph);

            for (int j = 0; j < n; j++) {
                double distance = distance(v, j, graph);
                if (minRib.get(j) > distance) {
                    minRib.set(j, distance);
                    selectedRib.set(j, v);
                }
            }
        }
        return answer;
    }


    public static void main(String[] args) {
        int n;
        ArrayList<Pair> graph = new ArrayList<>();
        boolean[] used;
        ArrayList<Integer> selectedRib = new ArrayList<>();
        ArrayList<Double> minRib = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        used = new boolean[n];
        for (int i = 0; i < n; i++) {
            selectedRib.add(-1);
            minRib.add((double) INF);
        }
        minRib.set(0, (double) 0);

        for (int i = 0; i < n; ++i) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.add(new Pair(from, to));
        }
        System.out.println(solve(n, used, minRib, selectedRib, graph));
    }

    static public class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class D {
    private static final int INF = 2000001;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertexCount = scanner.nextInt();
        int edgesCount = scanner.nextInt();
        Status[] used = new Status[vertexCount];
        boolean[] isBridge = new boolean[edgesCount];
        ArrayList<Integer> entryTime = new ArrayList<>();
        ArrayList<Integer> minimumTime = new ArrayList<>();
        ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
        ArrayList<Integer> color = new ArrayList<>();
        for (int i = 0; i < vertexCount; i++) {
            graph.add(new ArrayList<>());
            entryTime.add(INF);
            minimumTime.add(INF);
            color.add(0);
            used[i] = Status.clean;
        }
        HashMap<Pair, Integer> edges = new HashMap<>();
        for (int i = 0; i < edgesCount; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(new Pair(--to, i));
            graph.get(to).add(new Pair(from, i));
            edges.put(new Pair(from, to), i);
            edges.put(new Pair(to, from), i);
        }
        int time = 0;
        for (int i = 0; i < vertexCount; i++)
            if (used[i] == Status.clean) dfs(i, -1, used, entryTime, minimumTime, time, graph, isBridge);
        int maxColor = 0;
        for (int i = 0; i < vertexCount; i++)
            if (color.get(i) == 0) {
                maxColor++;
                dfs1(i, maxColor, color, graph, isBridge);
            }
        System.out.println(maxColor);
        for (int i = 0; i < vertexCount; i++) System.out.print(color.get(i) + " ");
    }

    static void dfs(int vertex, int parent, Status[] used, ArrayList<Integer> entryTime,
                    ArrayList<Integer> minimumTime, int time, ArrayList<ArrayList<Pair>> graph,
                    boolean[] isBridge) {
        used[vertex] = Status.onProcess;
        entryTime.set(vertex, time);
        minimumTime.set(vertex, time++);

        for (Pair u : graph.get(vertex))
            if (u.second != parent) if (used[u.first] == Status.clean) {
                dfs(u.first, u.second, used, entryTime, minimumTime, time, graph, isBridge);
                if (minimumTime.get(vertex) > minimumTime.get(u.first))
                    minimumTime.set(vertex, minimumTime.get(u.first));
                if (minimumTime.get(u.first) > entryTime.get(vertex)) isBridge[u.second] = true;
            } else if (minimumTime.get(vertex) > entryTime.get(u.first))
                minimumTime.set(vertex, entryTime.get(u.first));
        used[vertex] = Status.complete;
    }

    static void dfs1(int vertex, int maxColor, ArrayList<Integer> color,
                     ArrayList<ArrayList<Pair>> graph, boolean[] isBridge) {
        color.set(vertex, maxColor);
        for (Pair u : graph.get(vertex)) {
            if (color.get(u.first) == 0 && !isBridge[u.second]) {
                dfs1(u.first, maxColor, color, graph, isBridge);
            }
        }
    }

    enum Status {
        clean, onProcess, complete
    }

    static public class Pair {
        int first;
        int second;

        public Pair(int neighbor, int numberOfRibs) {
            this.first = neighbor;
            this.second = numberOfRibs;
        }
    }
}

/*
6 7
1 2
2 3
3 1
1 4
4 5
4 6
5 6

 */
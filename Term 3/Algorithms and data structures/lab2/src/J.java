import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Integer.max;

public class J {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertexCount = scanner.nextInt();
        int edgeCount = scanner.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertexCount; i++)
            graph.add(new ArrayList<>());
        boolean[] used = new boolean[vertexCount];
        int[] degree = new int[vertexCount];
        ArrayList<Integer> queue = new ArrayList<>();
        int maxDegree = 0;
        for (int i = 0; i < edgeCount; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(--to);
            degree[from]++;
            maxDegree = max(maxDegree, degree[from]);
        }
        for (int i = 0; i < vertexCount; i++)
            dfs(i, used, graph, queue);
        int[] functionGrundy = new int[vertexCount];
        boolean[] marked = new boolean[++maxDegree];
        for (int u : queue) {
            Arrays.fill(marked, false);
            for (int v : graph.get(u))
                marked[functionGrundy[v]] = true;
            int answer = 0;
            while (marked[answer])
                answer++;
            functionGrundy[u] = answer;
        }
        for (int answer : functionGrundy)
            System.out.println(answer);
    }

    static void dfs(int start, boolean[] used, ArrayList<ArrayList<Integer>> graph, ArrayList<Integer> queue) {
        if (used[start])
            return;
        used[start] = true;
        for (int vertex : graph.get(start))
            dfs(vertex, used, graph, queue);
        queue.add(start);
    }
}

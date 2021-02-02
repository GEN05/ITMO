import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class H {
    public static void main(String[] args) throws FileNotFoundException {
        File in = new File("game.in");
        File outFile = new File("game.out");
        Scanner scanner = new Scanner(in);
        int vertexCount = scanner.nextInt();
        int edgeCount = scanner.nextInt();
        int start = scanner.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        ArrayList<Integer> queue = new ArrayList<>();
        boolean[] used = new boolean[vertexCount];
        for (int i = 0; i < vertexCount; i++)
            graph.add(new ArrayList<>());
        for (int i = 0; i < edgeCount; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(--to);
        }
        dfs(--start, used, graph, queue);
        boolean[] win = new boolean[vertexCount];
        for (int u : queue)
            for (int v : graph.get(u))
                win[u] |= !win[v];
        PrintWriter out = new PrintWriter(outFile);
        out.print(win[start] ? "First player wins" : "Second player wins");
        scanner.close();
        out.close();
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

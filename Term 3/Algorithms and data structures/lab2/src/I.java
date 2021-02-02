import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class I {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertexCount;
        int edgeCount;
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        ArrayList<ArrayList<Integer>> reverse = new ArrayList<>();
        ArrayList<Integer> degree = new ArrayList<>();
        ArrayList<Result> isWin = new ArrayList<>();
        boolean[] used = new boolean[0];
        while (scanner.hasNext()) {
            for (ArrayList<ArrayList<Integer>> arrayLists : Arrays.asList(graph, reverse))
                arrayLists.clear();
            isWin.clear();
            degree.clear();
            vertexCount = scanner.nextInt();
            edgeCount = scanner.nextInt();
            if (used.length == 0)
                used = new boolean[vertexCount];
            Arrays.fill(used, false);
            for (int i = 0; i < vertexCount; i++) {
                graph.add(new ArrayList<>());
                reverse.add(new ArrayList<>());
                isWin.add(Result.DRAW);
                degree.add(0);
            }
            for (int i = 0; i < edgeCount; i++) {
                int from = scanner.nextInt();
                int to = scanner.nextInt();
                graph.get(--from).add(--to);
                reverse.get(to).add(from);
                degree.set(from, degree.get(from) + 1);
            }

            for (int u = 0; u < vertexCount; u++) {
                if (degree.get(u) == 0) {
                    isWin.set(u, Result.SECOND);
                    dfs(u, used, reverse, isWin, degree);
                }
            }
            StringBuilder result = new StringBuilder();
            for (Result res : isWin)
                result.append(res.name()).append("\n");
            System.out.print(result);
            System.out.println();
        }
    }

    static void dfs(int vertex, boolean[] used, ArrayList<ArrayList<Integer>> reverse, ArrayList<Result> isWin,
                    ArrayList<Integer> deg) {
        used[vertex] = true;
        for (int u : reverse.get(vertex)) {
            if (used[u])
                continue;
            switch (isWin.get(vertex)) {
                case FIRST:
                    deg.set(u, deg.get(u) - 1);
                    if (deg.get(u) == 0) {
                        isWin.set(u, Result.SECOND);
                        dfs(u, used, reverse, isWin, deg);
                    }
                    break;
                case SECOND:
                    isWin.set(u, Result.FIRST);
                    dfs(u, used, reverse, isWin, deg);
                    break;
            }
        }
    }

    public enum Result {
        FIRST,
        DRAW,
        SECOND
    }

}

/*
5 5
1 2
2 3
3 1
1 4
4 5
2 1
1 2
4 4
1 2
2 3
3 1
1 4


 */

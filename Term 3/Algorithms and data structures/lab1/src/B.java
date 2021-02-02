import java.util.ArrayList;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

import static java.lang.Integer.min;

class B {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int countOfVertex = scanner.nextInt();
        int countOfRibs = scanner.nextInt();
        ArrayList<ArrayList<Pair>> graph = new ArrayList<>(countOfVertex);
        for (int i = 0; i < countOfVertex; i++)
            graph.add(new ArrayList<>());
        boolean[] used = new boolean[countOfVertex];
        SortedSet<Integer> answer = new TreeSet<>();
        for (int i = 0; i < countOfRibs; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(new Pair(--to, i));
            graph.get(to).add(new Pair(from, i));
        }
        findBridges(used, graph, answer, countOfVertex);
        System.out.println(answer.size());
        for (int i : answer)
            System.out.print(i + 1 + " ");
    }

    static void dfs(int vertex, int parent, boolean[] used, ArrayList<ArrayList<Pair>> graph, SortedSet<Integer> answer, int countOfVertex, int timer, int[] entryTime, int[] minEntryTime) {
        used[vertex] = true;
        entryTime[vertex] = minEntryTime[vertex] = timer++;
        for (int i = 0; i < graph.get(vertex).size(); i++) {
            int to = graph.get(vertex).get(i).neighbor;
            if (to == parent)
                continue;
            if (used[to])
                minEntryTime[vertex] = min(minEntryTime[vertex], entryTime[to]);
            else {
                dfs(to, vertex, used, graph, answer, countOfVertex, timer, entryTime, minEntryTime);
                minEntryTime[vertex] = min(minEntryTime[vertex], minEntryTime[to]);
                if (minEntryTime[to] > entryTime[vertex])
                    for (int j = 0; j < countOfVertex; j++) {
                        if (graph.get(vertex).get(j).neighbor == to) {
                            answer.add(graph.get(vertex).get(j).numberOfRibs);
                            break;
                        }
                    }
            }
        }
    }

    static void findBridges(boolean[] used, ArrayList<ArrayList<Pair>> graph, SortedSet<Integer> answer, int countOfVertex) {
        int timer = 0;
        int[] tin = new int[countOfVertex];
        int[] fup = new int[countOfVertex];
        for (int i = 0; i < countOfVertex; ++i)
            if (!used[i])
                dfs(i, -1, used, graph, answer, countOfVertex, timer, tin, fup);
    }

    static public class Pair {
        int neighbor;
        int numberOfRibs;

        public Pair(int neighbor, int numberOfRibs) {
            this.neighbor = neighbor;
            this.numberOfRibs = numberOfRibs;
        }
    }
}

/*

13 15
1 2
2 3
3 4
1 3
4 5
4 6
5 6
7 8
7 9
8 9
9 10
10 11
11 12
12 13
13 11


 */

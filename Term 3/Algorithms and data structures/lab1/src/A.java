import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

class A {
    static void dfs(ArrayList<ArrayList<Integer>> graph, int vertex, boolean[] used, Stack<Integer> answer) {
        used[vertex] = true;
        for (int i = 0; i < graph.get(vertex).size(); i++) {
            int to = graph.get(vertex).get(i);
            if (!used[to])
                dfs(graph, to, used, answer);
        }
        answer.push(vertex);
    }

    static void topologicalSorting(ArrayList<ArrayList<Integer>> graph, int countOfVertex, boolean[] used, Stack<Integer> answer) {
        for (int i = 0; i < countOfVertex; i++) {
            if (!used[i])
                dfs(graph, i, used, answer);
        }
        for (int i = 0; i < countOfVertex; i++) {
            System.out.print(answer.pop() + 1);
            System.out.print(" ");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int countOfVertex = scanner.nextInt();
        int countOfRibs = scanner.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < countOfVertex; i++)
            graph.add(new ArrayList<>());
        boolean[] used = new boolean[countOfVertex];
        Status[] statuses = new Status[countOfVertex];
        for (int i = 0; i < countOfVertex; i++) {
            statuses[i] = Status.clean;
        }
        Stack<Integer> answer = new Stack<>();
        for (int i = 0; i < countOfRibs; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(--to);
        }

        boolean flag = true;
        for (int i = 0; i < countOfVertex; i++) {
            if (!used[i])
                if (checkCycle(i, statuses, graph, used)) {
                    flag = false;
                    break;
                }
        }
        for (int i = 0; i < countOfVertex; i++) {
            used[i] = false;
        }
        if (flag)
            topologicalSorting(graph, countOfVertex, used, answer);
        else
            System.out.println(-1);
    }

    static boolean checkCycle(int vertex, Status[] statuses, ArrayList<ArrayList<Integer>> graph, boolean[] used) {
        statuses[vertex] = Status.onProcess;
        for (int i = 0; i < graph.get(vertex).size(); i++) {
            int to = graph.get(vertex).get(i);
            if (statuses[to] == Status.clean) {
                if (checkCycle(to, statuses, graph, used))
                    return true;
            } else if (statuses[to] == Status.onProcess) {
                return true;
            }
        }
        statuses[vertex] = Status.complete;
        used[vertex] = true;
        return false;
    }

    enum Status {
        clean, onProcess, complete
    }
}
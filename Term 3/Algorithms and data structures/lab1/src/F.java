import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class F {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int countOfVertex = scanner.nextInt();
        int countOfRibs = scanner.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        ArrayList<ArrayList<Integer>> invertGraph = new ArrayList<>();
        for (int i = 0; i < countOfVertex; i++)
            graph.add(new ArrayList<>());
        for (int i = 0; i < countOfVertex; i++)
            invertGraph.add(new ArrayList<>());
        boolean[] used = new boolean[countOfVertex];
        ArrayList<Integer> order = new ArrayList<>();
        ArrayList<Integer> component = new ArrayList<>();
        ArrayList<Integer> componentNumberAtVertex = new ArrayList<>();
        int componentNumber = 0;
        for (int i = 0; i < countOfRibs; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(--to);
            invertGraph.get(to).add(from);
        }
        for (int i = 0; i < countOfVertex; i++)
            if (!used[i])
                dfs1(i, used, graph, order);
        for (int i = 0; i < countOfVertex; i++)
            used[i] = false;
        for (int i = 0; i < countOfVertex; i++)
            componentNumberAtVertex.add(0);
        for (int i = 0; i < countOfVertex; i++) {
            int v = order.get(countOfVertex - 1 - i);
            if (!used[v]) {
                dfs2(v, used, invertGraph, component, componentNumberAtVertex, componentNumber);
                componentNumber++;
                component.clear();
            }
        }

        HashSet<String> ribsInCondensation = new HashSet<>();
        for (int i = 0; i < countOfVertex; i++)
            for (int j = 0; j < graph.get(i).size(); j++) {
                int to = graph.get(i).get(j);
                if (!componentNumberAtVertex.get(i).equals(componentNumberAtVertex.get(to)))
                    ribsInCondensation.add((componentNumberAtVertex.get(i).toString() + componentNumberAtVertex.get(to).toString()));
            }
        System.out.print(ribsInCondensation.size());
    }

    static void dfs1(int vertex, boolean[] used, ArrayList<ArrayList<Integer>> graph,
                     ArrayList<Integer> order) {
        used[vertex] = true;
        for (int to : graph.get(vertex))
            if (!used[to])
                dfs1(to, used, graph, order);
        order.add(vertex);
    }

    static void dfs2(int vertex, boolean[] used, ArrayList<ArrayList<Integer>> invertGraph,
                     ArrayList<Integer> component, ArrayList<Integer> componentNumberAtVertex, int componentNumber) {
        componentNumberAtVertex.set(vertex, componentNumber);
        used[vertex] = true;
        component.add(vertex);
        for (int to : invertGraph.get(vertex))
            if (!used[to])
                dfs2(to, used, invertGraph, component, componentNumberAtVertex, componentNumber);
    }
}

/*
4 4
1 2
3 2
2 3
4 3

 */
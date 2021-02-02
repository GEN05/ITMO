import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
    private static final int INF = Integer.MAX_VALUE;

    @SuppressWarnings("unused")
    static void logForGraph(ArrayList<ArrayList<Pair>> graph) {
        for (ArrayList<Pair> i : graph) {
            for (Pair j : i)
                System.out.print(j.first + " " + j.second + " | ");
            System.out.println();
        }
    }

    static void logForDistance(int[] distance) {
        StringBuilder answer = new StringBuilder();
        for (int dist : distance)
            answer.append(dist).append(" ");
        System.out.println(answer);
    }

    @SuppressWarnings("unused")
    static void logForHeap(Heap heap) {
        System.out.println("\nheap");
        StringBuilder stringBuilder = new StringBuilder();
        while (!heap.isEmpty())
            stringBuilder.append(heap.getMin().weight).append(" ");
        System.out.println(stringBuilder);
    }

    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        int vertexCount = scanner.nextInt();
        int edgeCount = scanner.nextInt();
        ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
        for (int i = 0; i < edgeCount; i++)
            graph.add(new ArrayList<>());
        for (int i = 0; i < edgeCount; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.get(--from).add(new Pair(--to, weight));
            graph.get(to).add(new Pair(from, weight));
        }
        //logForGraph(graph);

        int[] distance = new int[vertexCount];
        Arrays.fill(distance, INF);
        boolean[] completeVertex = new boolean[vertexCount];
        int completeVertexCount = 0;
        Heap outgoingEdge = new Heap();     //  first - weight  second - index
        completeVertex[0] = true;
        completeVertexCount++;
        distance[0] = 0;
        for (Pair i : graph.get(0))
            outgoingEdge.add(new Edge(0, i.first, i.second));
        while (completeVertexCount < vertexCount) {   //  пока не обработаем все вершины
            //logForHeap(outgoingEdge);
            Edge min = outgoingEdge.getMin();
            int from = min.from;
            int to = min.to;
            int minWeight = min.weight;
            if (distance[to] > distance[from] + minWeight)
                distance[to] = distance[from] + minWeight;
            completeVertex[from] = true;
            completeVertexCount++;
            for (Pair i : graph.get(to)) {
                if (completeVertex[i.first])
                    continue;
                outgoingEdge.add(new Edge(to, i.first, i.second));
            }
            logForDistance(distance);
        }
    }

    static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
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

    static class Heap {

        private final ArrayList<Edge> heap = new ArrayList<>();

        void siftUp(int i) {
            while (heap.get(i).weight + heap.get(i).from < heap.get((i - 1) / 2).weight + heap.get((i - 1) / 2).from && i >= 1) {
                swap(i, (i - 1) / 2);
                i = (i - 1) / 2;
            }
        }

        void add(Edge a) {
            heap.add(a);
            siftUp(heap.size() - 1);
        }

        void swap(int first, int second) {
            Edge temp = heap.get(first);
            heap.set(first, heap.get(second));
            heap.set(second, temp);
        }

        @SuppressWarnings("SameParameterValue")
        void siftDown(int i) {
            while (2 * i + 1 < heap.size()) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int j = left;
                if (right < heap.size() && heap.get(right).weight + heap.get(right).from < heap.get(left).weight + heap.get(left).from) {
                    j = right;
                }
                if (heap.get(i).weight + heap.get(i).from <= heap.get(j).weight + heap.get(j).from) {
                    break;
                }
                swap(i, j);
                i = j;
            }
        }

        Edge getMin() {
            Edge min = heap.get(0);
            heap.set(0, heap.get(heap.size() - 1));
            heap.remove(heap.size() - 1);
            siftDown(0);
            return min;
        }

        int size() {
            return heap.size();
        }

        boolean isEmpty() {
            return size() == 0;
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        FastReader(InputStream input) {
            br = new BufferedReader(new InputStreamReader(input));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    return null;
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        @SuppressWarnings("unused")
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}

/*

4 5
1 2 1
1 3 5
2 4 8
3 4 1
2 3 3

7 12
1 2 1
1 3 6
1 4 8
2 4 3
2 5 5
3 4 1
3 7 7
4 5 6
4 6 1
4 7 2
5 6 4
6 7 9
 */
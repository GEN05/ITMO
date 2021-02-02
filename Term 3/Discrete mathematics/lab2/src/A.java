import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class A {
    public static void main(String[] args) throws IOException {
        File file = new File("schedule.in");
        FastReader scanner = new FastReader(new FileInputStream(file));
        int n = scanner.nextInt();
        Task[] tasks = new Task[n];
        for (int i = 0; i < n; i++) {
            int deadline = scanner.nextInt();
            int weight = scanner.nextInt();
            tasks[i] = new Task(deadline, weight);
        }
        Arrays.sort(tasks, new SortTask());
        TreeSet<Integer> result = new TreeSet<>();
        long sumWeight = 0;
        int time = 0;
        for (int i = 0; i < n; i++) {
            result.add(tasks[i].getWeight());
            if (tasks[i].getDeadline() > time)
                time++;
            else
                //noinspection ConstantConditions
                sumWeight += result.pollFirst();
        }
        FileWriter writer = new FileWriter("schedule.out");
        writer.write(String.valueOf(sumWeight));
        writer.close();

//        System.out.println(sumWeight);
//        for (int i = 0; i < n; i++) {
//            System.out.println(tasks[i].getDeadline() + " " + tasks[i].getWeight());
//        }

    }

    public static class Task {
        private final int deadline;
        private final int weight;

        public Task(int deadline, int weight) {
            this.deadline = deadline;
            this.weight = weight;
        }

        public int getDeadline() {
            return deadline;
        }

        public int getWeight() {
            return weight;
        }
    }

    static class SortTask implements Comparator<Task> {
        public int compare(Task a, Task b) {
            int result = a.getDeadline() - b.getDeadline();
            if (result == 0)
                result = a.getWeight() - b.getWeight();
            return result;
        }
    }

    static class FastReader implements AutoCloseable {
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

        @Override
        public void close() throws Exception {
            br.close();
        }
    }
}


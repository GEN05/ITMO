import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

import static java.lang.Integer.min;

public class E {
    static ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
    static boolean[] used;
    static ArrayList<Integer> entryTime = new ArrayList<>();
    static ArrayList<Integer> list = new ArrayList<>();
    static ArrayList<Integer> color = new ArrayList<>();
    static Stack<Integer> stack = new Stack<>();
    static int time = 0;
    static int maxColor = 1;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        used = new boolean[n];
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
            entryTime.add(0);
            list.add(0);
            used[i] = false;
        }
        for (int i = 0; i < m; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.get(--from).add(new Pair(--to, i));
            graph.get(to).add(new Pair(from, i));
            color.add(0);
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                paint(i, -1);
                boolean f;
                f = !stack.empty();
                while (!stack.empty()) color.set(stack.pop(), maxColor);
                if (f) maxColor++;
            }
        }
        System.out.println(--maxColor);
        for (int i : color)
            System.out.print(i + " ");
    }

    static void paint(int vertex, int parent) {
        list.set(vertex, ++time);
        entryTime.set(vertex, time);
        used[vertex] = true;
        int counter = 0;
        for (Pair temp : graph.get(vertex)) {
            int u = temp.first;
            int number = temp.second;
            if (parent == number) continue;
            if (used[u]) {
                list.set(vertex, min(list.get(vertex), entryTime.get(u)));
                if (entryTime.get(vertex) > entryTime.get(u)) stack.push(number);
                continue;
            }
            counter++;
            stack.push(number);
            paint(u, number);
            list.set(vertex, min(list.get(u), list.get(vertex)));
            if (!(parent == -1) && list.get(u) >= entryTime.get(vertex)) {
                while (true) {
                    int temp2 = stack.pop();
                    if (temp2 == number) {
                        stack.push(temp2);
                        break;
                    }
                    color.set(temp2, maxColor);
                }
                color.set(number, maxColor);
                stack.pop();
                maxColor++;
            } else if (parent == -1 && counter > 1) {
                while (true) {
                    int temp2 = stack.pop();
                    if (temp2 == number) {
                        stack.push(temp2);
                        break;
                    }
                    color.set(temp2, maxColor);
                }
                color.set(number, maxColor);
                stack.pop();
                maxColor++;
            }
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
}
import java.util.ArrayList;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String p = scanner.nextLine();
        String t = scanner.nextLine();
        String string = p + '#' + t;
        ArrayList<Integer> prefixFunction = new ArrayList<>();
        for (int i = 0; i < string.length(); i++)
            prefixFunction.add(0);
        prefixFunction(string, prefixFunction);
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = p.length(); i < string.length(); i++)
            if (prefixFunction.get(i) == p.length())
                answer.add(i + 1 - 2 * p.length());
        System.out.println(answer.size());
        for (Integer integer : answer)
            System.out.print(integer + " ");
    }

    private static void prefixFunction(String string, ArrayList<Integer> prefixFunction) {
        for (int i = 1; i < string.length(); i++) {
            int j = prefixFunction.get(i - 1);
            while (j > 0 && string.charAt(i) != string.charAt(j))
                j = prefixFunction.get(j - 1);
            if (string.charAt(i) == string.charAt(j))
                prefixFunction.set(i, ++j);
        }
    }
}

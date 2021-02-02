import java.util.ArrayList;
import java.util.Scanner;

public class E {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();
        ArrayList<Integer> prefixFunction = new ArrayList<>();
        int n = string.length();
        for (int i = 0; i < n; i++)
            prefixFunction.add(0);
        prefixFunction(string, prefixFunction);
        int prefix = prefixFunction.get(n - 1);
        if (n % (n - prefix) == 0) {
            System.out.println(n - prefix);
            return;
        }
        System.out.print(n);
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

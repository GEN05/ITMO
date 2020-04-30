package Sum;

import static java.lang.Character.isWhitespace;

public class SumLong {
    public static void main(String[] args) {
        long sum = 0;
        for (String arg : args) {
            int j = 0;
            while (j < arg.length()) {
                while (j < arg.length() && isWhitespace(arg.charAt(j))) j++;
                if (j < arg.length()) {
                    int next = j + 1;
                    while (next < arg.length() && !isWhitespace(arg.charAt(next))) next++;
                    sum += Long.parseLong(arg.substring(j, next));
                    j = next;
                }
            }
        }
        System.out.print(sum);
    }
}
import java.util.ArrayList;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();
        int stringLength = string.length();
        int requestCount = scanner.nextInt();
        ArrayList<Long> powers = new ArrayList<>();
        ArrayList<Long> hashes = new ArrayList<>();
        getAllPowers(powers, stringLength);
        getAllHashes(string, powers, hashes, stringLength);
        for (int i = 0; i < requestCount; i++)
            System.out.println(isSame(scanner.nextInt() - 1, scanner.nextInt() - 1,
                    scanner.nextInt() - 1, scanner.nextInt() - 1, powers, hashes) ? "Yes" : "No");
    }

    private static boolean isSame(int a, int b, int c, int d, ArrayList<Long> powers, ArrayList<Long> hashes) {
        if (b - a != d - c)
            return false;
        if (a == c && b == d)
            return true;
        long thirstHash = hashes.get(b);
        if (a != 0)
            thirstHash -= hashes.get(a - 1);
        long secondHash = hashes.get(d);
        if (c != 0)
            secondHash -= hashes.get(c - 1);
        return a < c && thirstHash * powers.get(c - a) == secondHash ||
                a > c && thirstHash == secondHash * powers.get(a - c);
    }

    private static void getAllPowers(ArrayList<Long> powers, int stringLength) {
        powers.add(1L);
        for (int i = 1; i < stringLength; i++)
            powers.add(powers.get(i - 1) * 5);
    }

    private static void getAllHashes(String string, ArrayList<Long> powers, ArrayList<Long> hashes, int stringLength) {
        hashes.add((long) (string.charAt(0) - 'a' + 1));
        for (int i = 1; i < stringLength; i++) {
            hashes.add(hashes.get(i - 1));
            hashes.set(i, hashes.get(i) + ((string.charAt(i) - 'a' + 1) * powers.get(i)));
        }
    }
}

/*
trololo
3
1 7 1 7
5 7 3 5
1 5 1 1

aaaaaaaaaa
1
1 7
3 9

 */
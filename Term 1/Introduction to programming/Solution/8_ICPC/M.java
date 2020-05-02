import java.util.*;

public class M {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scan.nextInt();
            List<Integer> a = new ArrayList<Integer>();
            for (int j = 0; j < n; j++) {
                int temp = scan.nextInt();
                a.add(temp);
            }
            int sum = 0;
            Map<Integer, Integer> b = new HashMap<Integer, Integer>();
            for (int j = n - 1; j >= 0; j--) {
                for (int k = 0; k < j; k++) {
                    if (b.get(2 * a.get(j) - a.get(k)) != null) {
                        sum += b.get(2 * a.get(j) - a.get(k));
                    }
                }
                if (b.get(a.get(j)) != null) {
                    b.replace(a.get(j), b.get(a.get(j)) + 1);
                } else {
                    b.put(a.get(j), 1);
                }
            }
            System.out.println(sum);
        }
    }
}

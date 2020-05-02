import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a = scan.nextInt(), b = scan.nextInt(), n = scan.nextInt(), ans =  (int)Math.ceil((n - b) / (b - a)) * 2 + 1;
        System.out.println((int)ans);
    }
}

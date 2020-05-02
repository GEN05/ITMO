import java.util.Scanner;

public class I {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int xl = 1000000000, xr = -1000000000, yl = 1000000000, yr = -1000000000;
        for (int i = 0; i < n; i++) {
            int x = scan.nextInt(), y = scan.nextInt(), h = scan.nextInt();
            if (xl > x - h) {
                xl = x - h;
            }
            if (xr < x + h) {
                xr = x + h;
            }
            if (yl > y - h) {
                yl = y - h;
            }
            if (yr < y + h) {
                yr = y + h;
            }
        }
        System.out.print((xl + xr) / 2);
        System.out.print(" ");
        System.out.print((yl + yr) / 2);
        System.out.print(" ");
        System.out.print((Math.max(xr - xl, yr - yl) + 1) / 2);
    }
}

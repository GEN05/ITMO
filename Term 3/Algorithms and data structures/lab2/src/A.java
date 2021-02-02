import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[][] matrix = new int[size][size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j] = scanner.nextInt();
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = 0; k < size; k++)
                    if (matrix[j][k] > matrix[j][i] + matrix[i][k])
                        matrix[j][k] = matrix[j][i] + matrix[i][k];
        for (int[] i : matrix) {
            for (int j : i)
                System.out.print(j + " ");
            System.out.println();
        }
    }
}

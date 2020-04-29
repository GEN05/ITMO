package Reverse;

import java.util.ArrayList;
import java.util.Scanner;

public class ReverseEven {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<>();
        while (scanner.hasNextLine()) {
            for (String digit : " ".split(scanner.nextLine())) {
                if (!digit.equals("")) {
                    int digitInt = Integer.parseInt(digit);
                    if (digitInt % 2 == 0)
                        list.add(digitInt + " ");
                } else {
                    list.add(digit + " ");
                }
            }
            list.add("\n");
        }
        for (int i = list.size() - 2; i >= 0; i--) {
            System.out.print(list.get(i));
        }
    }
}

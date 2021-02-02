package C;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {
    public static void main(String[] args) {
        FastReader scanner = new FastReader(System.in);
        int lampsCount = scanner.nextInt();
        ArrayList<Integer> lamps = new ArrayList<>();
        try {
            for (int i = 0; i < lampsCount; i++)
                findTheRightLamp(i, lamps, scanner);
        } catch (Exception e) {
            e.printStackTrace();
        }
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(0).append(" ");
        for (Integer lamp : lamps) stringBuilder.append(lamp).append(" ");
        System.out.flush();
        System.out.print(stringBuilder);
    }

    private static void findTheRightLamp(int nowLamp, ArrayList<Integer> lamps, FastReader scanner) throws Exception {  // l = 0    r = i - 1   v = i
        int left = 0;
        int right = nowLamp;
        while (left < right) {
            int middle = (left + right) / 2;
            if (askTheWizard(nowLamp, lamps.get(middle), scanner))
                right = middle;
            else
                left = middle + 1;
        }
        lamps.add(left, nowLamp + 1);
    }

    private static boolean askTheWizard(int nowLamp, int middle, FastReader scanner) throws Exception {
        System.out.flush();
        System.out.println(1 + " " + (nowLamp + 1) + " " + middle);
        String wizardAnswer = scanner.next();
        if (wizardAnswer.equals("YES"))
            return true;
        else if (wizardAnswer.equals("NO"))
            return false;
        else
            throw new Exception("aaaa");
    }
}

class FastReader {
    BufferedReader br;
    StringTokenizer st;

    FastReader(InputStream input) {
        br = new BufferedReader(new InputStreamReader(input));
    }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

}


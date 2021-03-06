package md2html;

import java.io.*;
import java.nio.charset.StandardCharsets;

public class Md2Html {

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Not found names of files\n");
            return;
        }
        StringBuilder ans = new StringBuilder();
        StringBuilder par = new StringBuilder();
        BufferedReader reader = null;
        BufferedWriter writer = null;
        String s = "";
        try {
            reader = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]), StandardCharsets.UTF_8));
            while (s != null && (s = reader.readLine()) != null) {
                while (s != null && !s.equals("")) {
                    par.append(s).append('\n');
                    s = reader.readLine();
                }
                if (par.length() != 0) {
                    par.setLength(par.length() - 1);
                    new Str(par).toHtml(ans);
                    ans.append('\n');
                    par = new StringBuilder();
                }
            }
            try {
                writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(args[1]), StandardCharsets.UTF_8));
                writer.write(ans.toString());
            } catch (FileNotFoundException e) {
                System.out.println("Output file not found");
                e.printStackTrace();
            } catch (IOException e) {
                System.out.println("Output error");
                e.printStackTrace();
            } finally {
                try {
                    if (writer != null) {
                        writer.close();
                    }
                } catch (IOException e) {
                    System.out.println("Output error");
                    e.printStackTrace();
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Input file not found");
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("Input error");
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
            } catch (IOException e) {
                System.out.println("Input error");
                e.printStackTrace();
            }
        }
    }
}

package WordStat;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Map;
import java.util.TreeMap;

public class WordStatWords {
    public static void main(String[] args) {
        BufferedWriter writer = null;
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]), StandardCharsets.UTF_8), 1_000_000)) {
            TreeMap<String, Integer> wordsMap = new TreeMap<>();
            String str;
            while ((str = reader.readLine()) != null) {
                str = str.toLowerCase() + " ";
                int wordLength = 0;
                for (int i = 0; i < str.length(); i++) {
                    char c = str.charAt(i);
                    if (Character.isLetter(c) || c == '\'' || Character.getType(c) == Character.DASH_PUNCTUATION) {
                        wordLength++;
                    } else if (wordLength > 0) {
                        String word = str.substring(i - wordLength, i);
                        Integer v = wordsMap.get(word);
                        wordsMap.put(word, v == null ? 1 : 1 + v);
                        wordLength = 0;
                    }
                }
            }
            try {
                writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(args[1]), StandardCharsets.UTF_8), 1_000_000);
                for (Map.Entry mapEntry : wordsMap.entrySet())
                    writer.write(mapEntry.getKey() + " " + mapEntry.getValue() + "\n");
            } catch (IOException e) {
                System.out.println("Oops... Output error" + e.getMessage());
            } finally {
                assert writer != null;
                writer.close();
            }
        } catch (FileNotFoundException e) {
            System.out.println("Oops... File not found " + e.getMessage());
        } catch (IOException e) {
            System.out.println("Oops... Input error " + e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.err.println("IO error: " + e.getMessage());
        }
    }
}
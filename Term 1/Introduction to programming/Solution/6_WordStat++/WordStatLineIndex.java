import java.nio.charset.StandardCharsets;
import java.util.*;
import java.lang.*;
import java.io.*;

public class WordStatLineIndex {
    public static void main(String[] args) {
        if (args.length > 1) {
            Map<String, ArrayList<String>> map = new TreeMap<>();
            MyScanner scan = null;
            BufferedWriter writer = null;
            try {
            	scan = new MyScanner(args[0]); 
                int cnt = 1;
                while (scan.hasNext()) {
                    ArrayList<String> a = scan.nextArray();
                    for (int i = 0; i < a.size(); i++) {
                        String elem = a.get(i);
                        if (elem.length() > 0) {
                            ArrayList<String> tmp = map.getOrDefault(elem, new ArrayList<>());
                            tmp.add(cnt + ":" + (i + 1));
                            map.put(elem, tmp);
                        }
                    }
                    cnt++;
                }
            	try {
            		writer = new BufferedWriter(
                    	new OutputStreamWriter(new FileOutputStream(args[1]), StandardCharsets.UTF_8));
                	for (Map.Entry<String, ArrayList<String>> entry : map.entrySet()) {
                    	writer.write(entry.getKey() + " " + entry.getValue().size());
                    	for (String strTemp : entry.getValue()) {
                        	writer.write(" " + strTemp);
                    	}
                    	writer.write("\n");
                	}
            	} catch (IOException e) {
                	System.out.println("Oops... Output error" + e.getMessage());
            	} finally {
                    writer.close();
            	}
            } catch (FileNotFoundException e) {
				System.out.println("Oops... File not found" + e.getMessage());
			} catch (IOException e) {
				System.out.println("Oops... Input error" + e.getMessage());
			} catch (ArrayIndexOutOfBoundsException e) {
				System.err.println("IO error: " + e.getMessage());
			} finally {
				try {
					if (scan != null) {
						scan.close();
					}
				} catch (IOException e) {}
			}
        } else {
            System.out.println("Wrong input data");
        }
    }
}
package md2html;

import java.util.HashMap;
import java.util.Map;

class Text {

    private static Map<String, Integer> mdIndex;
    private static String[] htmlTag;
    private static String[] mdTag;

    static {
        mdTag = new String[]{"*", "_", "**", "__", "--", "`", "~"};
        mdIndex = new HashMap<>();
        int tagCount = mdTag.length;
        for (int i = 0; i < tagCount; i++) {
            mdIndex.put(mdTag[i], i);
        }
        htmlTag = new String[]{"em", "em", "strong", "strong", "s", "code", "mark"};
    }

    private StringBuilder origin;

    Text(StringBuilder origin) {
        this.origin = origin;
    }

    private Integer getTagPos(String cur) {
        Integer res = mdIndex.get(cur);
        if (res == null) {
            res = mdIndex.get(Character.toString(cur.charAt(0)));
        }
        return res;
    }

    void toHtml(StringBuilder ans) {
        int tagCount = htmlTag.length;
        myStack[] arr = new myStack[tagCount];
        for (int i = 0; i < tagCount; i++) {
            arr[i] = new myStack();
        }
        for (int i = 0; i < origin.length(); i++) {
            String cur;
            if (i + 2 < origin.length()) {
                cur = origin.substring(i, i + 2);
            } else {
                cur = origin.substring(i, origin.length());
            }
            if (origin.charAt(i) == '\\') {
                i++;
                continue;
            }
            Integer pos = getTagPos(cur);
            if (pos != null) {
                arr[pos].add(i);
            }
        }
        for (myStack j : arr) {
            if (j.getSize() % 2 == 1) {
                j.pop();
            }
        }
        int[] pos = new int[tagCount];
        for (int i = 0; i < origin.length(); i++) {
            char c = origin.charAt(i);
            String cur;
            if (i + 2 < origin.length()) {
                cur = origin.substring(i, i + 2);
            } else {
                cur = origin.substring(i, origin.length());
            }
            if (c == '<') {
                ans.append("&lt;");
                continue;
            } else if (c == '>') {
                ans.append("&gt;");
                continue;
            } else if (c == '&') {
                ans.append("&amp;");
                continue;
            } else if (c == '\\') {
                continue;
            }
            Integer Pos = getTagPos(cur);
            if (Pos == null || arr[Pos].getSize() == 0) {
                ans.append(c);
            } else {
                cur = mdTag[Pos];
                String tagName = htmlTag[Pos];
                int tagSize = cur.length();
                boolean isOpen = ((arr[Pos].getSize() - pos[Pos]) % 2 == 0);
                String tmp;
                if (isOpen) {
                    tmp = "<" + "" + tagName + ">";
                } else {
                    tmp = "<" + "/" + tagName + ">";
                }
                ans.append(tmp);
                i += tagSize - 1;
                pos[Pos]++;
            }
        }
    }
}
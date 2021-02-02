import java.util.ArrayList;

public class G {
    Node root;

    public static void main(String[] args) {

    }

    Node getSuffixLink(Node vertex) {
        if (vertex.suffixLink == null) {
            if (vertex == root || vertex.parent == root)
                vertex.suffixLink = root;
            else
                vertex.suffixLink = getLink(getSuffixLink(vertex.parent), vertex.charToParent);
        }
        return vertex.suffixLink;
    }

    Node getLink(Node vertex, char symbol) {
        if (vertex.go[symbol] == null)
            if (vertex.son[symbol] != null)
                vertex.go[symbol] = vertex.son[symbol];
            else if (vertex == root)
                vertex.go[symbol] = root;
            else
                vertex.go[symbol] = getLink(getSuffixLink(vertex), symbol);
        return vertex.go[symbol];
    }

    Node getUp(Node vertex) {
        if (vertex.up == null)
            if (getSuffixLink(vertex).isLeaf)
                vertex.up = getSuffixLink(vertex);
            else if (getSuffixLink(vertex) == root)
                vertex.up = root;
            else
                vertex.up = getUp(getSuffixLink(vertex));
        return vertex.up;
    }

    void addString(String s, int patternNumber) {
        Node cur = root;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (cur.son[c] == null) {
                cur.son[c] = new Node();
                /* здесь также нужно обнулить указатели на переходы и сыновей */
                cur.son[c].suffixLink = null;
                cur.son[c].up = null;
                cur.son[c].parent = cur;
                cur.son[c].charToParent = c;
                cur.son[c].isLeaf = false;
            }
            cur = cur.son[c];
        }
        cur.isLeaf = true;
        cur.leafPatternNumber.add(patternNumber);
    }

    void processText(String t) {
        Node cur = root;
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            cur = getLink(cur, c);
        }
    }

    public static class Node {
        public Node() {
        }

        Node[] son;
        Node[] go;
        Node parent;
        Node suffixLink;
        Node up;
        char charToParent;
        boolean isLeaf;
        ArrayList<Integer> leafPatternNumber;
    }
}

package md2html;

class Header {
    private StringBuilder origin;

    Header(StringBuilder origin) {
        this.origin = origin;
    }

    private int headerLvl(StringBuilder text) {
        int i = 0;
        while (i < text.length() && text.charAt(i) == '#') {
            i++;
        }
        return i;
    }

    void toHtml(StringBuilder ans) {
        int lvl = headerLvl(origin);
        ans.append('<').append('h').append(lvl).append('>');
        new Text(new StringBuilder(origin.substring(lvl + 1))).toHtml(ans);
        ans.append('<').append('/').append('h').append(lvl).append('>');
    }
}

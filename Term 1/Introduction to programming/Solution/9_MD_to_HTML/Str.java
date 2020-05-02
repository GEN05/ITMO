package md2html;

class Str {
    private StringBuilder origin;

    Str(StringBuilder origin) {
        this.origin = origin;
    }

    private boolean isHeader(StringBuilder text) {
        int i = 0;
        while (i < text.length() && text.charAt(i) == '#') {
            i++;
        }
        return (i > 0 && i < text.length() && text.charAt(i) == ' ');
    }

    void toHtml(StringBuilder ans) {
        if (isHeader(origin)) {
            new Header(origin).toHtml(ans);
        } else {
            new Paragraph(origin).toHtml(ans);
        }
    }
}

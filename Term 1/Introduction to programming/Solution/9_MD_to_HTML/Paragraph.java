package md2html;

class Paragraph {
    private StringBuilder origin;

    Paragraph(StringBuilder origin) {
        this.origin = origin;
    }

    void toHtml(StringBuilder ans) {
        ans.append('<').append('p').append('>');
        new Text(origin).toHtml(ans);
        ans.append('<').append('/').append('p').append('>');
    }
}

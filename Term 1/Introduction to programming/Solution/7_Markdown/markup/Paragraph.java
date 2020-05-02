package markup;

import java.util.List;

public class Paragraph extends AbstractMarkupElement {
    public Paragraph(List<InParagraph> elements) {
        super(elements);
    }

    public void toMarkdown(StringBuilder result) {
        toMarkdown(result, "");
    }

    public void toTex(StringBuilder result) {
        toTex(result, "", "");
    }
}
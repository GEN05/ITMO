package markup;

import java.util.List;

public abstract class AbstractMarkupElement {
    private List<InParagraph> elements;

    AbstractMarkupElement(List<InParagraph> value1) {
        this.elements = value1;
    }

    protected void toMarkdown(StringBuilder value1, String value2) {
        value1.append(value2);
        for (InParagraph value4 : this.elements) {
            value4.toMarkdown(value1);
        }
        value1.append(value2);
    }

    protected void toTex(StringBuilder value1, String value2, String value3) {
        value1.append(value2);
        for (InParagraph value5 : this.elements) {
            value5.toTex(value1);
        }
        value1.append(value3);
    }
}
package markup;

import java.util.List;

public class Strikeout extends AbstractMarkupElement implements InParagraph {
    public Strikeout(List<InParagraph> value1) {
        super(value1);
    }

    public void toMarkdown(StringBuilder value1) {
        this.toMarkdown(value1, "~");
    }

    public void toTex(StringBuilder value1) {
        this.toTex(value1, "\\textst{", "}");
    }
}

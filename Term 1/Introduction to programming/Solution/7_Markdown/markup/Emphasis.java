package markup;

import java.util.List;

public class Emphasis extends AbstractMarkupElement implements InParagraph {
    public Emphasis(List<InParagraph> elements) {
        super(elements);
    }

    @Override
    public void toMarkdown(StringBuilder result) {
        toMarkdown(result, "*");
    }

    @Override
    public void toTex(StringBuilder result) {
        toTex(result, "\\emph{", "}");
    }
}
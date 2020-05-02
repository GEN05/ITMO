package markup;

public interface InParagraph extends Markable {
    void toMarkdown(StringBuilder value1);

    @Override
    void toTex(StringBuilder value1);
}
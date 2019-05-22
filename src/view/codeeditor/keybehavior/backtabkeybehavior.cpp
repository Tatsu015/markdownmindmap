#include "backtabkeybehavior.h"
#include "view/codeeditor/codeeditor.h"
#include <QTextBlock>

BackTabKeyBehavior::BackTabKeyBehavior() : AbstractKeyBehavior() {
}

BackTabKeyBehavior::~BackTabKeyBehavior() {
}

void BackTabKeyBehavior::noModifierKeyPressEvent(CodeEditor* codeEditor) {
  QTextCursor cursor = codeEditor->textCursor();
  if (cursor.hasSelection()) {
    QString selectedText = cursor.selectedText();
    cursor.removeSelectedText();
    QString indentedText = selectedText.replace(QString(QChar::ParagraphSeparator + " "), "\n");
    cursor.insertText(indentedText);
  } else {
    QTextCursor cursor = codeEditor->textCursor();
    QString nowLine = cursor.block().text();
    if ((!nowLine.isEmpty()) && (' ' == nowLine.at(0))) {
      cursor.select(QTextCursor::BlockUnderCursor);
      cursor.removeSelectedText();
      cursor.insertText("\n" + nowLine.mid(1));
    }
  }
}

void BackTabKeyBehavior::shiftModifierKeyPressEvent(CodeEditor* codeEditor) {
  noModifierKeyPressEvent(codeEditor);
}

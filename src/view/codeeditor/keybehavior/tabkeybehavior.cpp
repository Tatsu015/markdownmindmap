#include "tabkeybehavior.h"
#include "view/codeeditor/codeeditor.h"
#include <QTextBlock>

TabKeyBehavior::TabKeyBehavior() : AbstractKeyBehavior() {
}

TabKeyBehavior::~TabKeyBehavior() {
}

void TabKeyBehavior::noModifierKeyPressEvent(CodeEditor* codeEditor) {
  QTextCursor cursor = codeEditor->textCursor();
  if (cursor.hasSelection()) {
    QString selectedText = cursor.selectedText();
    cursor.removeSelectedText();
    QString indentedText = selectedText.replace(QString(QChar::ParagraphSeparator), "\n ");
    cursor.insertText(indentedText);
  } else {
    QTextCursor cursor = codeEditor->textCursor();
    QString nowLine = cursor.block().text();
    cursor.select(QTextCursor::BlockUnderCursor);
    cursor.removeSelectedText();
    cursor.insertText("\n " + nowLine);
  }
}

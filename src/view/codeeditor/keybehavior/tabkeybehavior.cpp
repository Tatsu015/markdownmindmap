#include "tabkeybehavior.h"
#include "view/codeeditor/codeeditor.h"
#include <QTextBlock>

TabKeyBehavior::TabKeyBehavior() : AbstractKeyBehavior() {
}

TabKeyBehavior::~TabKeyBehavior() {
}

void TabKeyBehavior::noModifierKeyPressEvent(CodeEditor* codeEditor) {
  QTextCursor cursor = codeEditor->textCursor();
  cursor.beginEditBlock();
  if (cursor.hasSelection()) {
    // TODO when press tab, first line do not move
    QString selectedText = cursor.selectedText();
    cursor.removeSelectedText();
    QString indentedText = selectedText.replace(QString(QChar::ParagraphSeparator), "\n ");
    cursor.insertText(indentedText);
  } else {
    QString nowLine = cursor.block().text();
    cursor.select(QTextCursor::BlockUnderCursor);
    cursor.removeSelectedText();
    cursor.insertText("\n " + nowLine);
  }
  cursor.endEditBlock();
}

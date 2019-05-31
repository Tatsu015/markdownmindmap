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
    int32_t start = cursor.selectionStart();
    int32_t end = cursor.selectionEnd();

    cursor.setPosition(end);
    cursor.movePosition(cursor.EndOfLine);
    end = cursor.position();

    cursor.setPosition(start);
    cursor.movePosition(cursor.StartOfLine);
    start = cursor.position();

    cursor.beginEditBlock();
    while (cursor.position() < end) {
      cursor.movePosition(cursor.StartOfLine);
      cursor.insertText(" ");
      end += QString(" ").length();
      cursor.movePosition(cursor.Down);
      cursor.movePosition(cursor.EndOfLine);
    }
    cursor.movePosition(cursor.StartOfLine);
    cursor.insertText(" ");
    cursor.endEditBlock();
  } else {
    QString nowLine = cursor.block().text();
    cursor.select(QTextCursor::BlockUnderCursor);
    cursor.removeSelectedText();
    cursor.insertText("\n " + nowLine);
  }
  cursor.endEditBlock();
}

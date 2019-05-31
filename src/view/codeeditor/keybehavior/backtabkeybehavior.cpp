#include "backtabkeybehavior.h"
#include "view/codeeditor/codeeditor.h"
#include <QTextBlock>

BackTabKeyBehavior::BackTabKeyBehavior() : AbstractKeyBehavior() {
}

BackTabKeyBehavior::~BackTabKeyBehavior() {
}

void BackTabKeyBehavior::noModifierKeyPressEvent(CodeEditor* codeEditor) {
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
      QChar c = codeEditor->document()->characterAt(cursor.position());
      if (' ' == c) {
        cursor.deleteChar();
        end -= QString(" ").length();
      }
      cursor.movePosition(cursor.Down);
      cursor.movePosition(cursor.EndOfLine);
    }
    cursor.movePosition(cursor.StartOfLine);
    cursor.deleteChar();
    cursor.endEditBlock();
  } else {
    QString nowLine = cursor.block().text();
    if ((!nowLine.isEmpty()) && (' ' == nowLine.at(0))) {
      cursor.select(QTextCursor::BlockUnderCursor);
      cursor.removeSelectedText();
      cursor.insertText("\n" + nowLine.mid(1));
    }
  }
  cursor.endEditBlock();
}

void BackTabKeyBehavior::shiftModifierKeyPressEvent(CodeEditor* codeEditor) {
  noModifierKeyPressEvent(codeEditor);
}

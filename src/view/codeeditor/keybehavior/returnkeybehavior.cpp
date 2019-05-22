#include "returnkeybehavior.h"
#include "utility/stringutil.h"
#include "view/codeeditor/codeeditor.h"
#include <QTextBlock>

ReturnKeyBehavior::ReturnKeyBehavior() : AbstractKeyBehavior() {
}

ReturnKeyBehavior::~ReturnKeyBehavior() {
}

void ReturnKeyBehavior::noModifierKeyPressEvent(CodeEditor* codeEditor) {
  QTextCursor cursor = codeEditor->textCursor();
  QString lastLine = cursor.block().text();
  QString indent = extractIndent(lastLine, ' ');
  cursor.insertText("\n" + indent);
}

void ReturnKeyBehavior::controlModifierKeyPressEvent(CodeEditor* codeEditor) {
  QTextCursor cursor = codeEditor->textCursor();
  cursor.movePosition(QTextCursor::End);
  codeEditor->setTextCursor(cursor);
  QString lastLine = cursor.block().text();
  QString indent = extractIndent(lastLine, ' ');
  cursor.insertText("\n" + indent);
}

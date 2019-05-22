#include "codeeditor.h"
#include "ui_mainwindow.h"
#include "utility/stringutil.h"
#include "view/codeeditor/keybehavior/backtabkeybehavior.h"
#include "view/codeeditor/keybehavior/returnkeybehavior.h"
#include "view/codeeditor/keybehavior/tabkeybehavior.h"
#include <QTextBlock>

CodeEditor::CodeEditor(QWidget* parent) : QPlainTextEdit(parent) {
  m_keyBehavior[Qt::Key_Tab] = new TabKeyBehavior();
  m_keyBehavior[Qt::Key_Backtab] = new BackTabKeyBehavior();
  m_keyBehavior[Qt::Key_Return] = new ReturnKeyBehavior();
}

CodeEditor::~CodeEditor() {
}

void CodeEditor::keyPressEvent(QKeyEvent* event) {
  AbstractKeyBehavior* keyBehavior = m_keyBehavior[static_cast<Qt::Key>(event->key())];
  if (keyBehavior) {
    keyBehavior->keyPressEvent(this, event);
  } else {
    QPlainTextEdit::keyPressEvent(event);
  }
}

#include "codeeditor.h"
#include "ui_mainwindow.h"
#include <QDebug>

CodeEditor::CodeEditor(QWidget* parent) : QPlainTextEdit(parent) {
}

CodeEditor::~CodeEditor() {
}

void CodeEditor::keyPressEvent(QKeyEvent* event) {
  if (Qt::Key_Tab == event->key()) {
    QTextCursor cursor = textCursor();
    cursor.insertText(" ");
  } else {
    QPlainTextEdit::keyPressEvent(event);
  }
}

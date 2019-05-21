#include "codeeditor.h"
#include "ui_mainwindow.h"
#include "utility/stringutil.h"
#include <QDebug>
#include <QTextBlock>

CodeEditor::CodeEditor(QWidget* parent) : QPlainTextEdit(parent) {
  setTabChangesFocus(false);
}

CodeEditor::~CodeEditor() {
}

void CodeEditor::keyPressEvent(QKeyEvent* event) {
  if (Qt::Key_Tab == event->key()) {
    QTextCursor cursor = textCursor();
    if (cursor.hasSelection()) {
      QString replaceFrom;
      QString replaceTo;
      if (event->modifiers() & Qt::ShiftModifier) {
        // TODO do not work!
        replaceFrom = QString(QChar::ParagraphSeparator + " ");
        replaceTo = "\n";
      } else {
        replaceFrom = QString(QChar::ParagraphSeparator);
        replaceTo = "\n ";
      }
      QString selectedText = cursor.selectedText();
      cursor.removeSelectedText();
      QString indentedText = selectedText.replace(replaceFrom, replaceTo);
      cursor.insertText(indentedText);
    } else {
      QTextCursor cursor = textCursor();
      QString nowLine = cursor.block().text();
      cursor.select(QTextCursor::BlockUnderCursor);
      cursor.removeSelectedText();
      cursor.insertText("\n " + nowLine);
    }
  } else if (Qt::Key_Return == event->key()) {
    if (event->modifiers() & Qt::ControlModifier) {
      QTextCursor cursor = textCursor();
      cursor.movePosition(QTextCursor::End);
      setTextCursor(cursor);
      cursor.insertText("\n");
    } else {
      QTextCursor cursor = textCursor();
      QString lastLine = cursor.block().text();
      QString indent = extractIndent(lastLine, ' ');
      cursor.insertText("\n" + indent);
    }
  } else {
    QPlainTextEdit::keyPressEvent(event);
  }
}

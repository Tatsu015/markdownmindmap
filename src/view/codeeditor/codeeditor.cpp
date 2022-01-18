#include "codeeditor.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/stringutil.h"
#include "view/codeeditor/keybehavior/backtabkeybehavior.h"
#include "view/codeeditor/keybehavior/returnkeybehavior.h"
#include "view/codeeditor/keybehavior/tabkeybehavior.h"
#include <QFile>
#include <QMimeData>
#include <QTextBlock>
#include <QTextStream>

CodeEditor::CodeEditor(QWidget* parent) : QPlainTextEdit(parent) {
  m_keyBehavior[Qt::Key_Tab] = new TabKeyBehavior();
  m_keyBehavior[Qt::Key_Backtab] = new BackTabKeyBehavior();
  m_keyBehavior[Qt::Key_Return] = new ReturnKeyBehavior();
}

CodeEditor::~CodeEditor() {
  qDeleteAll(m_keyBehavior);
}

void CodeEditor::keyPressEvent(QKeyEvent* event) {
  AbstractKeyBehavior* keyBehavior = m_keyBehavior[static_cast<Qt::Key>(event->key())];
  if (keyBehavior) {
    keyBehavior->keyPressEvent(this, event);
  } else {
    QPlainTextEdit::keyPressEvent(event);
  }
}

void CodeEditor::dropEvent(QDropEvent* event) {
  QList<QUrl> urls = event->mimeData()->urls();
  // if drop data is markdowdmindmap project file, open project.
  // else default drop event process.
  if (0 >= urls.count()) {
    QPlainTextEdit::dropEvent(event);
  } else {
    QString filePath = event->mimeData()->urls().first().toLocalFile();

    QFile f(filePath);
    if (!f.open(QIODevice::ReadOnly)) {
      return;
    }
    Application::getInstance()->document()->setFilePath(filePath);
    QTextStream in(&f);
    const QString readData = in.readAll();
    Application::getInstance()->document()->setPlainText(readData);

    f.close();
  }
}

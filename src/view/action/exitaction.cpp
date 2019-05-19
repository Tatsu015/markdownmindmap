#include "exitaction.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

ExitAction::ExitAction(QObject* parent) : AbstractAction(parent) {
  QAction* exitAction = new QAction("Exit");
  exitAction->setShortcut(QKeySequence::Quit);
  connect(exitAction, &QAction::triggered, this, &ExitAction::execute);
  m_actions << exitAction;
}

ExitAction::~ExitAction() {
}

void ExitAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  QString projectPath;
  if (Application::getInstance()->document()->filePath().isEmpty()) {
    if (Application::getInstance()->ui()->codeEditor->toPlainText().isEmpty()) {
      qApp->exit(0);
      return;
    }
    projectPath = QFileDialog::getSaveFileName(nullptr, QObject::tr("Save file"), QDir::currentPath(),
                                               QObject::tr("project files (*.mdmm)"));
  } else {
    projectPath = Application::getInstance()->document()->filePath();
  }

  QFile f(projectPath);
  if (!f.open(QIODevice::WriteOnly)) {
    return;
  }
  QTextStream out(&f);
  out.setCodec("UTF-8");
  out << Application::getInstance()->document()->toPlainText();
  f.close();
  qApp->exit(0);
}

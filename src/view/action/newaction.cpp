#include "newaction.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

NewAction::NewAction(QObject* parent) : AbstractAction(parent) {
  m_action = new QAction("New");
  m_action->setShortcut(QKeySequence::New);
  connect(m_action, &QAction::triggered, this, &NewAction::execute);
}

NewAction::~NewAction() {
}

void NewAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  QString projectPath;
  if (Application::getInstance()->document()->filePath().isEmpty()) {
    if (Application::getInstance()->ui()->textEdit->toPlainText().isEmpty()) {
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

  Application::getInstance()->document()->setPlainText("");
  Application::getInstance()->document()->setFilePath("");
}

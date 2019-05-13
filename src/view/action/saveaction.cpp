#include "saveaction.h"
#include "controller/application.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

SaveAction::SaveAction(QObject* parent) : AbstractAction(parent) {
  QAction* saveAction = new QAction("Save");
  saveAction->setShortcut(QKeySequence::Save);
  connect(saveAction, &QAction::triggered, this, &SaveAction::execute);
  m_actions << saveAction;
}

SaveAction::~SaveAction() {
}

void SaveAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  QString filePath;
  if (Application::getInstance()->document()->filePath().isEmpty()) {
    filePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("Save file"), QDir::currentPath(),
                                            QObject::tr("project files (*.mdmm)"));
  } else {
    filePath = Application::getInstance()->document()->filePath();
  }

  QFile f(filePath);
  if (!f.open(QIODevice::WriteOnly)) {
    return;
  }
  Application::getInstance()->document()->setFilePath(filePath);
  QTextStream out(&f);
  out.setCodec("UTF-8");
  out << Application::getInstance()->document()->toPlainText();
  f.close();
}

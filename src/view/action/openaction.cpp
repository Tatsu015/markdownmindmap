#include "openaction.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

OpenAction::OpenAction(QObject* parent) : AbstractAction(parent) {
  QAction* openAction = new QAction("Open");
  openAction->setShortcut(QKeySequence::Open);
  connect(openAction, &QAction::triggered, this, &OpenAction::execute);
  m_actions << openAction;
}

OpenAction::~OpenAction() {
}

void OpenAction::execute() {
  QString filePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open file"), QDir::currentPath(),
                                                  QObject::tr("mdmm files (*.mdmm)"));

  QFile f(filePath);
  if (!f.open(QIODevice::ReadOnly)) {
    return;
  }
  Application::getInstance()->document()->setFilePath(filePath);
  QTextStream in(&f);
  in.setCodec("UTF-8");
  const QString readData = in.readAll();
  Application::getInstance()->document()->setPlainText(readData);

  f.close();
}

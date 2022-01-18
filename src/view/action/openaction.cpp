#include "openaction.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/definition.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

OpenAction::OpenAction(QObject* parent) : AbstractAction(parent) {
}

OpenAction::~OpenAction() {
}

void OpenAction::init() {
  QAction* openAction = new QAction("Open");
  openAction->setShortcut(QKeySequence::Open);
  connect(openAction, &QAction::triggered, this, &OpenAction::execute);
  m_actions << openAction;
}

void OpenAction::execute() {
  QString filePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open file"), QDir::currentPath(),
                                                  "project files (*." + MARKDOWN_MIND_MAP_SUFFIX + ")");

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

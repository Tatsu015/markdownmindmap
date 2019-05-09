#include "exitaction.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "viewmodel/graphicsitem/node.h"
#include "viewmodel/scene/scene.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

ExitAction::ExitAction(QObject* parent) : AbstractAction(parent) {
  m_action = new QAction("Exit");
  m_action->setShortcut(QKeySequence::Quit);
  connect(m_action, &QAction::triggered, this, &ExitAction::execute);
}

ExitAction::~ExitAction() {
}

void ExitAction::execute() {
  const QString editedData = Application::getInstance()->document()->toPlainText();
  Scene* scene = Application::getInstance()->ui()->graphicsView->customScene();
  scene->addMindMapTree(editedData);

  QString projectPath;
  if (Application::getInstance()->document()->filePath().isEmpty()) {
    if (Application::getInstance()->ui()->textEdit->toPlainText().isEmpty()) {
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
  out << editedData;
  f.close();
  qApp->exit(0);
}

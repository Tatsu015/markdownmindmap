#include "saveaction.h"
#include "controller/application.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/definition.h"
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
                                            "project files (*." + MARKDOWN_MIND_MAP_SUFFIX + ")");
  } else {
    filePath = Application::getInstance()->document()->filePath();
  }

  QFileInfo info(filePath);
  if (MARKDOWN_MIND_MAP_SUFFIX != info.suffix()) {
    filePath += ("." + MARKDOWN_MIND_MAP_SUFFIX);
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

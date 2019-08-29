#include "saveasaction.h"
#include "controller/application.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/definition.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

SaveAsAction::SaveAsAction(QObject* parent) : AbstractAction(parent) {
}

SaveAsAction::~SaveAsAction() {
}

void SaveAsAction::init() {
  QAction* saveAcAction = new QAction("Save As");
  saveAcAction->setShortcut(QKeySequence::SaveAs);
  connect(saveAcAction, &QAction::triggered, this, &SaveAsAction::execute);
  m_actions << saveAcAction;
}

void SaveAsAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  QString filePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("Save file"), QDir::currentPath(),
                                                  "project files (*." + MARKDOWN_MIND_MAP_SUFFIX + ")");

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

#include "saveasaction.h"
#include "controller/application.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

SaveAsAction::SaveAsAction(QObject* parent) : AbstractAction(parent) {
  QAction* saveAcAction = new QAction("Save As");
  saveAcAction->setShortcut(QKeySequence::SaveAs);
  connect(saveAcAction, &QAction::triggered, this, &SaveAsAction::execute);
  m_actions << saveAcAction;
}

SaveAsAction::~SaveAsAction() {
}

void SaveAsAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  QString filePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("Save file"), QDir::currentPath(),
                                                  QObject::tr("project files (*.mdmm)"));

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

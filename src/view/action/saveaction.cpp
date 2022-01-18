#include "saveaction.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/definition.h"
#include "utility/systemconfig.h"
#include "viewmodel/graphicsitem/node.h"
#include "viewmodel/scene/scene.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

SaveAction::SaveAction(QObject* parent) : AbstractAction(parent) {
}

SaveAction::~SaveAction() {
}

void SaveAction::init() {
  QAction* saveAction = new QAction("Save");
  saveAction->setShortcut(QKeySequence::Save);
  connect(saveAction, &QAction::triggered, this, &SaveAction::execute);
  m_actions << saveAction;
}

void SaveAction::execute() {
  Document* document = Application::getInstance()->document();
  // need to draw graphics before auto format,
  // because format text generate from graphics datas.
  emit document->contentsChanged();
  if (systemConfig(SystemConfig::autoFormatWhenSave).toBool()) {
    Scene* scene = Application::getInstance()->ui()->graphicsView->customScene();
    QString buf = scene->rootNode()->toString();
    if (!buf.isEmpty()) {
      if ('\n' != buf.at(0)) {
        document->setPlainText(buf);
      }
    }
  }

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
  out << Application::getInstance()->document()->toPlainText();
  f.close();
}

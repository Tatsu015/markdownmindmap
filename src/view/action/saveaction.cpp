#include "saveaction.h"
#include "controller/application.h"
#include "controller/application.h"
#include "controller/layouter/layouter.h"
#include "controller/parser/markdownparser.h"
#include "model/document.h"
#include "model/node.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QTextStream>

SaveAction::SaveAction(QObject* parent) : AbstractAction(parent) {
  m_action = new QAction("Save");
  m_action->setShortcut(QKeySequence::Save);
  connect(m_action, &QAction::triggered, this, &SaveAction::execute);
}

SaveAction::~SaveAction() {
}

void SaveAction::execute() {
  const QString editedData = Application::getInstance()->document()->toPlainText();

  // TODO more consider...
  Node* rootNode = MarkdownParser::getInstance()->parse(editedData);
  if (rootNode) {
    Layouter::getInstance()->Layout(rootNode);
    QGraphicsScene* scene = Application::getInstance()->ui()->graphicsView->scene();
    scene->clear();
    scene->addItem(rootNode);
  }

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
  out << editedData;
  f.close();
}

#include "openaction.h"
#include "controller/application.h"
#include "controller/layouter/layouter.h"
#include "controller/parser/markdownparser.h"
#include "model/document.h"
#include "model/node.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

OpenAction::OpenAction(QObject* parent) : AbstractAction(parent) {
  m_action = new QAction("Open");
  m_action->setShortcut(QKeySequence::Open);
  connect(m_action, &QAction::triggered, this, &OpenAction::execute);
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
  Application::getInstance()->ui()->textEdit->setText(readData);

  // TODO more consider...
  Node* rootNode = MarkdownParser::getInstance()->parse(readData);
  if (rootNode) {
    Layouter::getInstance()->Layout(rootNode);
    QGraphicsScene* scene = Application::getInstance()->ui()->graphicsView->scene();
    scene->clear();
    scene->addItem(rootNode);
  }

  f.close();
}

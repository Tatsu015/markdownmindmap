#include "codeeditor.h"
#include "controller/application.h"
#include "controller/parser/markdownparser.h"
#include "model/document.h"
#include "model/graphics/node.h"
#include "model/graphics/scene.h"
#include "ui_mainwindow.h"
#include "view/graphicsview/graphicsview.h"
#include <QDebug>
#include <QTimer>

CodeEditor::CodeEditor(QWidget* parent) : QTextEdit(parent) {
  m_timer = new QTimer();
  connect(this, &CodeEditor::textChanged, this, &CodeEditor::onStartTimer);
  connect(m_timer, &QTimer::timeout, this, &CodeEditor::onUpdateModel);
}

CodeEditor::~CodeEditor() {
}

void CodeEditor::onStartTimer() {
  m_timer->stop();
  m_timer->start(300);
}

void CodeEditor::onUpdateModel() {
  Node* rootNode = MarkdownParser::getInstance()->parse(toPlainText());
  Scene* scene = Application::getInstance()->ui()->graphicsView->customScene();
  scene->addNodeItem(rootNode);

  m_timer->stop();
}

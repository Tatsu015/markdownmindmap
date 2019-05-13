#include "scene.h"
#include "model/document.h"
#include "viewmodel/graphicsitem/node.h"
#include "viewmodel/parser/markdownparser.h"
#include "viewmodel/scene/layoutproxy/abstractlayoutproxy.h"
#include "viewmodel/scene/layoutproxy/lefttorighttreelayoutproxy.h"
#include "viewmodel/scene/layoutproxy/toptobottomtreelayoutproxy.h"
#include <QTimer>

Scene::Scene(Document* document) : QGraphicsScene(), m_document(document) {
  addLayouterDecorator(new LeftToRightTreeLayoutProxy());
  addLayouterDecorator(new TopToBottomTreeLayoutProxy());

  m_timer = new QTimer();
  connect(m_document, &Document::contentsChanged, this, &Scene::onStartTimer);
  connect(m_timer, &QTimer::timeout, this, &Scene::onUpdateMindMap);
}

Scene::~Scene() {
}

void Scene::updateMindMap() {
  MarkdownParser parser;
  Node* rootNode = parser.parse(m_document->toPlainText());

  if (!rootNode) {
    return;
  }

  m_activeLayoutProxy->layout(rootNode);
  clear();
  addItem(rootNode);
}

void Scene::addLayouterDecorator(AbstractLayoutProxy* layoutDecolator) {
  m_layoutProxies[layoutDecolator->name()] = layoutDecolator;
}

void Scene::changeActiveLayoutDecolator(const QString& name) {
  m_activeLayoutProxy = m_layoutProxies[name];
  updateMindMap();
}

void Scene::onStartTimer() {
  m_timer->stop();
  m_timer->start(300);
}

void Scene::onUpdateMindMap() {
  updateMindMap();
  m_timer->stop();
}

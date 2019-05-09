#include "scene.h"
#include "viewmodel/graphicsitem/node.h"
#include "viewmodel/parser/markdownparser.h"
#include "viewmodel/scene/layoutproxy/abstractlayoutproxy.h"
#include "viewmodel/scene/layoutproxy/lefttorighttreelayoutproxy.h"

Scene::Scene() : QGraphicsScene() {
  addLayouterDecorator(new LeftToRightTreeLayoutProxy());
  m_activeLayoutProxy = m_layoutProxies.first();
}

Scene::~Scene() {
}

void Scene::addMindMapTree(const QString& data) {
  MarkdownParser parser;
  Node* rootNode = parser.parse(data);

  if (!rootNode) {
    return;
  }

  m_activeLayoutProxy->layout(rootNode);
  clear();
  addItem(rootNode);
}

void Scene::addNodeItem(Node* rootNode) {
  m_activeLayoutProxy->layout(rootNode);
  clear();
  addItem(rootNode);
}

void Scene::addLayouterDecorator(AbstractLayoutProxy* layoutDecolator) {
  m_layoutProxies[layoutDecolator->name()] = layoutDecolator;
}

void Scene::changeActiveLayoutDecolator(const QString& name) {
  m_activeLayoutProxy = m_layoutProxies[name];
}

#include "scene.h"
#include "model/graphics/node.h"
#include "model/graphics/proxy/abstractlayoutproxy.h"
#include "model/graphics/proxy/lefttorighttreelayoutproxy.h"

Scene::Scene() : QGraphicsScene() {
  addLayouterDecorator(new LeftToRightTreeLayoutProxy());
  m_activeLayoutProxy = m_layoutProxies.first();
}

Scene::~Scene() {
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

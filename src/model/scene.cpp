#include "scene.h"
#include "model/node.h"

Scene::Scene() : QGraphicsScene() {
}

Scene::~Scene() {
}

void Scene::updateView(Node* rootNode) {
  clear();
  addItem(rootNode);
}

#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Node;

class Scene : public QGraphicsScene {
public:
  Scene();
  virtual ~Scene();

  void updateView(Node* rootNode);
};

#endif // SCENE_H

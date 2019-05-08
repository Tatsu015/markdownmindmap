#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QMap>

class Node;
class AbstractLayoutProxy;

class Scene : public QGraphicsScene {
public:
  Scene();
  virtual ~Scene();

  void addNodeItem(Node* rootNode);

private:
  void addLayouterDecorator(AbstractLayoutProxy* layoutDecolator);
  void changeActiveLayoutDecolator(const QString& name);

private:
  QMap<QString, AbstractLayoutProxy*> m_layoutProxies;
  AbstractLayoutProxy* m_activeLayoutProxy = nullptr;
};

#endif // SCENE_H

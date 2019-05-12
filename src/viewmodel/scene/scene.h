#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QMap>

class Document;
class Node;
class AbstractLayoutProxy;

class Scene : public QGraphicsScene {
public:
  Scene(Document* document);
  virtual ~Scene();

private:
  void updateMindMap();
  void addLayouterDecorator(AbstractLayoutProxy* layoutDecolator);
  void changeActiveLayoutDecolator(const QString& name);

private slots:
  void onStartTimer();
  void onUpdateMindMap();

private:
  Document* m_document = nullptr;
  QMap<QString, AbstractLayoutProxy*> m_layoutProxies;
  AbstractLayoutProxy* m_activeLayoutProxy = nullptr;
  QTimer* m_timer = nullptr;
};

#endif // SCENE_H

#ifndef ABSTRACTLAYOUTERDECORATOR_H
#define ABSTRACTLAYOUTERDECORATOR_H

#include <QtGlobal>

class Node;

class AbstractLayoutProxy {
public:
  AbstractLayoutProxy();
  virtual ~AbstractLayoutProxy();

  void layout(Node* rootNode);

  virtual QString name() const = 0;

private:
  virtual qreal layoutChild(Node* node) = 0;
};

#endif // ABSTRACTLAYOUTERDECORATOR_H

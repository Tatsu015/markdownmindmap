#ifndef ABSTRACTLAYOUTERDECORATOR_H
#define ABSTRACTLAYOUTERDECORATOR_H

#include <QtGlobal>

class Node;

class AbstractLayoutProxy {
public:
  AbstractLayoutProxy();
  virtual ~AbstractLayoutProxy();

  virtual void layout(Node* rootNode) = 0;
  virtual QString name() const = 0;
};

#endif // ABSTRACTLAYOUTERDECORATOR_H

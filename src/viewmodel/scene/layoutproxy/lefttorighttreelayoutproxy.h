#ifndef LEFTTORIGHTTREELAYOUTDECORATOR_H
#define LEFTTORIGHTTREELAYOUTDECORATOR_H

#include "abstractlayoutproxy.h"
#include <QString>

class LeftToRightTreeLayoutProxy : public AbstractLayoutProxy {
public:
  const static QString NAME;

public:
  LeftToRightTreeLayoutProxy();
  virtual ~LeftToRightTreeLayoutProxy();

  void layout(Node* rootNode);
  virtual QString name() const;

private:
  virtual qreal layoutChild(Node* node);

  qreal treeHeight(Node* node);
  qreal childrenHeight(Node* node);
};

#endif // LEFTTORIGHTTREELAYOUTDECORATOR_H

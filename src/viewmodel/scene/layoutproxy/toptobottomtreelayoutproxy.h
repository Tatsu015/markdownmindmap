#ifndef TOPTOBOTTOMTREELAYOUTDECORATOR_H
#define TOPTOBOTTOMTREELAYOUTDECORATOR_H

#include "abstractlayoutproxy.h"
#include <QString>

class TopToBottomTreeLayoutProxy : public AbstractLayoutProxy {
public:
  const static QString NAME;

public:
  TopToBottomTreeLayoutProxy();
  virtual ~TopToBottomTreeLayoutProxy();

  void layout(Node* rootNode);
  virtual QString name() const;

private:
  virtual qreal layoutChild(Node* node);

  qreal treeWidth(Node* node);
  qreal childrenWidth(Node* node);
};

#endif // TOPTOBOTTOMTREELAYOUTDECORATOR_H

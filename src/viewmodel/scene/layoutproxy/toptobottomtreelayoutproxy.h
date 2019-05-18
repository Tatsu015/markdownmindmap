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

  virtual void layout(Node* rootNode);
  virtual QString name() const;

private:
  qreal layoutChild(const Node* node);
  qreal treeWidth(const Node* node);
  qreal childrenWidth(const Node* node);
  void drawConnection(const Node* parentNode, const Node* childNode);
};

#endif // TOPTOBOTTOMTREELAYOUTDECORATOR_H

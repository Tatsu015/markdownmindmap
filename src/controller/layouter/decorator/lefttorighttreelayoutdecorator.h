#ifndef LEFTTORIGHTTREELAYOUTDECORATOR_H
#define LEFTTORIGHTTREELAYOUTDECORATOR_H

#include "abstractlayouterdecorator.h"
#include <QString>

const static QString LEFT_TO_RIGHT_TREE_LAYOUT_DECOLATOR = "LeftToRightTreeLayoutDecorator";

class LeftToRightTreeLayoutDecorator : public AbstractLayouterDecorator {
public:
  LeftToRightTreeLayoutDecorator();
  virtual ~LeftToRightTreeLayoutDecorator();

  void layout(Node* rootNode);
  virtual QString name() const;

private:
  virtual qreal layoutChild(Node* node);

  qreal treeHeight(Node* node);
  qreal childrenHeight(Node* node);
};

#endif // LEFTTORIGHTTREELAYOUTDECORATOR_H

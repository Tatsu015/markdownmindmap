#include "lefttorighttreelayoutdecorator.h"
#include "model/connection.h"
#include "model/node.h"
#include <QDebug>
#include <QRectF>

const qreal CHILD_TO_PARENT_SPACE = 36;
const qreal CHILD_TO_CHILD_SPACE = -5; // TODO why minus???

LeftToRightTreeLayoutDecorator::LeftToRightTreeLayoutDecorator() : AbstractLayouterDecorator() {
}

LeftToRightTreeLayoutDecorator::~LeftToRightTreeLayoutDecorator() {
}

QString LeftToRightTreeLayoutDecorator::name() const {
  return LEFT_TO_RIGHT_TREE_LAYOUT_DECOLATOR;
}

qreal LeftToRightTreeLayoutDecorator::layoutChild(Node* node) {
  const QRectF br = node->boundingRect();
  if (!node->hasChild()) {
    return br.height();
  }
  const qreal x = br.right() + CHILD_TO_PARENT_SPACE;
  const qreal childHeight = childrenHeight(node);
  qreal y = br.center().y() - childHeight / 2;
  foreach (Node* childNode, node->childNodes()) {
    const qreal th = layoutChild(childNode);
    childNode->setPos(x, y * th / 2 - childNode->boundingRect().center().y());
    QPointF parentToChild = node->scenePos() - childNode->scenePos();
    QPointF offset(10, 0);
    QPointF parentPos = parentToChild + node->rightCenter() + offset;
    QPointF childPos = childNode->leftCenter() - offset;
    childNode->connection()->draw(parentPos, childPos);
    y += th + CHILD_TO_CHILD_SPACE;
  }
  return qMax(childHeight, br.height());
}

qreal LeftToRightTreeLayoutDecorator::treeHeight(Node* node) {
  return qMax(childrenHeight(node), node->boundingRect().height());
}

qreal LeftToRightTreeLayoutDecorator::childrenHeight(Node* node) {
  if (!node->hasChild()) {
    return 0;
  }
  qreal height = -CHILD_TO_CHILD_SPACE;
  foreach (Node* childNode, node->childNodes()) {
    height += treeHeight(childNode);
    height += CHILD_TO_CHILD_SPACE;
  }
  return height;
}

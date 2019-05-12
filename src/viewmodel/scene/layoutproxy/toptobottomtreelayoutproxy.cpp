#include "toptobottomtreelayoutproxy.h"
#include "viewmodel/graphicsitem/connection.h"
#include "viewmodel/graphicsitem/node.h"
#include <QDebug>
#include <QRectF>

const qreal CHILD_TO_PARENT_SPACE = 36;
const qreal CHILD_TO_CHILD_SPACE = 16;
const QPointF OFFSET(0, 10);
const QPointF CUBIC_POINT(0, 10);

const QString TopToBottomTreeLayoutProxy::NAME = "Top To Bottom";

TopToBottomTreeLayoutProxy::TopToBottomTreeLayoutProxy() : AbstractLayoutProxy() {
}

TopToBottomTreeLayoutProxy::~TopToBottomTreeLayoutProxy() {
}

QString TopToBottomTreeLayoutProxy::name() const {
  return NAME;
}

qreal TopToBottomTreeLayoutProxy::layoutChild(Node* node) {
  const QRectF br = node->boundingRect();
  if (!node->hasChild()) {
    return br.width();
  }
  const qreal y = br.bottom() + CHILD_TO_PARENT_SPACE;
  const qreal childWidth = childrenWidth(node);
  qreal x = br.center().x() - childWidth / 2;
  foreach (Node* childNode, node->childNodes()) {
    const qreal th = layoutChild(childNode);
    childNode->setPos(x + th / 2 - childNode->boundingRect().center().x(), y);
    QPointF parentToChild = node->scenePos() - childNode->scenePos();
    QPointF parentPos = parentToChild + node->bottomCenter() + OFFSET;
    QPointF childPos = childNode->topCenter() - OFFSET;
    childNode->connection()->draw(parentPos, childPos, CUBIC_POINT);
    x += th + CHILD_TO_CHILD_SPACE;
  }
  return qMax(childWidth, br.bottom());
}

qreal TopToBottomTreeLayoutProxy::treeWidth(Node* node) {
  return qMax(childrenWidth(node), node->boundingRect().width());
}

qreal TopToBottomTreeLayoutProxy::childrenWidth(Node* node) {
  if (!node->hasChild()) {
    return 0;
  }
  qreal width = -CHILD_TO_CHILD_SPACE;
  foreach (Node* childNode, node->childNodes()) {
    width += treeWidth(childNode);
    width += CHILD_TO_CHILD_SPACE;
  }
  return width;
}

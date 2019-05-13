#include "lefttorighttreelayoutproxy.h"
#include "utility/systemconfig.h"
#include "viewmodel/graphicsitem/connection.h"
#include "viewmodel/graphicsitem/node.h"
#include <QDebug>
#include <QRectF>

const qreal CHILD_TO_PARENT_SPACE = 36;
const qreal CHILD_TO_CHILD_SPACE = 6;
const QPointF OFFSET(10, 0);
const QPointF CUBIC_POINT(10, 0);

const QString LeftToRightTreeLayoutProxy::NAME = "Left To Right";

LeftToRightTreeLayoutProxy::LeftToRightTreeLayoutProxy() : AbstractLayoutProxy() {
}

LeftToRightTreeLayoutProxy::~LeftToRightTreeLayoutProxy() {
}

QString LeftToRightTreeLayoutProxy::name() const {
  return NAME;
}

qreal LeftToRightTreeLayoutProxy::layoutChild(Node* node) {
  const QRectF br = node->boundingRect();
  if (!node->hasChild()) {
    return br.height();
  }
  const qreal x = br.right() + systemConfig(SystemConfig::leftToRightLayoutNodeXSpace).toReal();
  const qreal childHeight = childrenHeight(node);
  qreal y = br.center().y() - childHeight / 2;
  foreach (Node* childNode, node->childNodes()) {
    const qreal th = layoutChild(childNode);
    childNode->setPos(x, y + th / 2 - childNode->boundingRect().center().y());
    QPointF parentToChild = node->scenePos() - childNode->scenePos();
    QPointF parentPos = parentToChild + node->rightCenter() + OFFSET;
    QPointF childPos = childNode->leftCenter() - OFFSET;
    childNode->connection()->draw(parentPos, childPos, CUBIC_POINT);
    y += th + systemConfig(SystemConfig::leftToRightLayoutNodeYSpace).toReal();
  }
  return qMax(childHeight, br.height());
}

qreal LeftToRightTreeLayoutProxy::treeHeight(Node* node) {
  return qMax(childrenHeight(node), node->boundingRect().height());
}

qreal LeftToRightTreeLayoutProxy::childrenHeight(Node* node) {
  if (!node->hasChild()) {
    return 0;
  }
  qreal leftToRightLayoutNodeYSpace = systemConfig(SystemConfig::leftToRightLayoutNodeYSpace).toReal();
  qreal height = -leftToRightLayoutNodeYSpace;
  foreach (Node* childNode, node->childNodes()) {
    height += treeHeight(childNode);
    height += leftToRightLayoutNodeYSpace;
  }
  return height;
}

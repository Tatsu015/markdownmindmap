#include "node.h"
#include "connection.h"
#include "utility/systemconfig.h"
#include <QDebug>
#include <QPen>

Node::Node(const QString& text, uint32_t depth, QGraphicsItem* parent)
    : QGraphicsSimpleTextItem(text, parent), m_depth(depth), m_connection(new Connection(this)) {
  QColor color = SystemConfig::getInstance()->systemConfig(SystemConfig::CONF_TEXT_COLOR).value<QColor>();
  setPen(QPen(color));
}

Node::~Node() {
}

void Node::addChildNode(Node* childNode) {
  m_childNodes << childNode;
  childNode->m_parentNode = this;
  childNode->setParentItem(this);
}

QList<Node*> Node::childNodes() const {
  return m_childNodes;
}

bool Node::hasChild() const {
  if (m_childNodes.isEmpty()) {
    return false;
  }
  return true;
}

int32_t Node::childCount() const {
  return m_childNodes.count();
}

Node* Node::parentNode() const {
  return m_parentNode;
}

uint32_t Node::depth() const {
  return m_depth;
}

QPointF Node::topCenter() const {
  return QPointF(boundingRect().center().x(), boundingRect().top());
}

QPointF Node::rightCenter() const {
  return QPointF(boundingRect().right(), boundingRect().center().y());
}

QPointF Node::bottomCenter() const {
  return QPointF(boundingRect().center().x(), boundingRect().bottom());
}

QPointF Node::leftCenter() const {
  return QPointF(boundingRect().left(), boundingRect().center().y());
}

Connection* Node::connection() const {
  return m_connection;
}

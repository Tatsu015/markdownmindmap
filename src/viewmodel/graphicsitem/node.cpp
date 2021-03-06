#include "node.h"
#include "connection.h"
#include "utility/systemconfig.h"
#include <QDebug>
#include <QPen>

Node::Node(const QString& text, const uint32_t depth, const uint32_t lineCount, QGraphicsItem* parent)
    : QGraphicsSimpleTextItem(text, parent), m_depth(depth), m_connection(new Connection(this)),
      m_lineCount(lineCount) {
  QColor color = systemConfig(SystemConfig::textColor).value<QColor>();
  setPen(QPen(color));
  setBrush(QBrush(color));
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

uint32_t Node::lineCount() const {
  return m_lineCount;
}

QString Node::toString() const {
  QString buf = toStringRecursive("");
  return buf;
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

QString Node::toStringRecursive(const QString& indent) const {
  QString buf;
  buf += indent + text() + "\n";
  foreach (Node* childNode, m_childNodes) { buf += childNode->toStringRecursive(indent + " "); }
  return buf;
}

#ifndef NODE_H
#define NODE_H

#include <QGraphicsSimpleTextItem>

class Connection;

class Node : public QGraphicsSimpleTextItem {
public:
  Node(const QString& text, const uint32_t depth, const uint32_t lineCount, QGraphicsItem* parent = nullptr);
  virtual ~Node();

  void addChildNode(Node* childNode);
  QList<Node*> childNodes() const;
  bool hasChild() const;
  int32_t childCount() const;

  Node* parentNode() const;
  uint32_t depth() const;
  uint32_t lineCount() const;

  QString toString() const;

  QPointF topCenter() const;
  QPointF rightCenter() const;
  QPointF bottomCenter() const;
  QPointF leftCenter() const;

  Connection* connection() const;

private:
  QString toStringRecursive(const QString& indent) const;

private:
  Node* m_parentNode = nullptr;
  QList<Node*> m_childNodes;
  uint32_t m_depth = 0;
  Connection* m_connection = nullptr;
  uint32_t m_lineCount;
};

#endif // NODE_H

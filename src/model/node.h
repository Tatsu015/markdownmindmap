#ifndef NODE_H
#define NODE_H

#include <QGraphicsSimpleTextItem>

class Connection;

class Node : public QGraphicsSimpleTextItem {
public:
  Node(const QString& text, uint32_t depth, QGraphicsItem* parent = nullptr);
  virtual ~Node();

  void addChildNode(Node* childNode);
  QList<Node*> childNodes() const;
  bool hasChild() const;
  int32_t childCount() const;

  Node* parentNode() const;
  uint32_t depth() const;

  QPointF topCenter() const;
  QPointF rightCenter() const;
  QPointF bottomCenter() const;
  QPointF leftCenter() const;

  Connection* connection() const;

private:
  Node* m_parentNode = nullptr;
  QList<Node*> m_childNodes;
  uint32_t m_depth = 0;
  Connection* m_connection = nullptr;
};

#endif // NODE_H

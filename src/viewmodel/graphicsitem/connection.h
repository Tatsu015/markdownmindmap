#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>

class Connection : public QGraphicsPathItem {
public:
  Connection(QGraphicsItem* parent = nullptr);
  virtual ~Connection();
  void draw(const QPointF& pos1, const QPointF& pos2, const QPointF& cubicPoint);
};

#endif // CONNECTION_H

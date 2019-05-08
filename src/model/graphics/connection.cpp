#include "connection.h"
#include <QPen>

Connection::Connection(QGraphicsItem* parent) : QGraphicsPathItem(parent) {
}

Connection::~Connection() {
}

void Connection::draw(const QPointF& pos1, const QPointF& pos2) {
  QPainterPath p;
  QPointF offset(10, 0);
  p.moveTo(pos1);
  p.cubicTo(pos1 + offset, pos2 - offset, pos2);
  setPen(QPen(Qt::white));
  setPath(p);
}

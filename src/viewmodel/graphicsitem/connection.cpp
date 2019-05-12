#include "connection.h"
#include "utility/systemconfig.h"
#include <QPen>

Connection::Connection(QGraphicsItem* parent) : QGraphicsPathItem(parent) {
  QColor color = systemConfig(SystemConfig::textColor).value<QColor>();
  setPen(QPen(color));
}

Connection::~Connection() {
}

void Connection::draw(const QPointF& pos1, const QPointF& pos2, const QPointF& cubicPoint) {
  QPainterPath p;
  p.moveTo(pos1);
  p.cubicTo(pos1 + cubicPoint, pos2 - cubicPoint, pos2);
  setPath(p);
}

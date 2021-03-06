#include "graphicsview.h"
#include "utility/systemconfig.h"
#include "viewmodel/scene/scene.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimeLine>
#include <QWheelEvent>

GraphicsView::GraphicsView(QWidget* parent)
    : QGraphicsView(parent), m_isControlPressed(false), m_numScheduledScalings(0) {
  setRenderHint(QPainter::Antialiasing);
  setAlignment(Qt::AlignCenter);
  setMouseTracking(true);
  setDragMode(RubberBandDrag);

  qreal initScale = 1;
  scale(initScale, initScale);

  QColor color = systemConfig(SystemConfig::backgroundColor).value<QColor>();
  setBackgroundBrush(QBrush(color));
}

GraphicsView::~GraphicsView() {
}

void GraphicsView::wheelEvent(QWheelEvent* event) {
  if (!m_isControlPressed) {
    QGraphicsView::wheelEvent(event);
    return;
  }

  int numDegrees = event->angleDelta().y() / 8;
  int numSteps = numDegrees / 15;

  m_numScheduledScalings += numSteps;
  // reset scaling when wheel rotate direction changed
  if (m_numScheduledScalings * numSteps < 0) {
    m_numScheduledScalings = numSteps;
  }

  QTimeLine* anim = new QTimeLine(350, this);
  anim->setUpdateInterval(20);

  connect(anim, &QTimeLine::valueChanged, this, &GraphicsView::onScalingTime);
  connect(anim, &QTimeLine::finished, this, &GraphicsView::onAnimFinished);
  anim->start();

  QGraphicsView::wheelEvent(event);
}

void GraphicsView::keyPressEvent(QKeyEvent* event) {
  if (Qt::Key_Control == event->key()) {
    m_isControlPressed = true;
  }

  QGraphicsView::keyPressEvent(event);
}

void GraphicsView::keyReleaseEvent(QKeyEvent* event) {
  if (Qt::Key_Control == event->key()) {
    m_isControlPressed = false;
  }

  QGraphicsView::keyReleaseEvent(event);
}

Scene* GraphicsView::customScene() const {
  return dynamic_cast<Scene*>(scene());
}

void GraphicsView::onScalingTime(qreal x) {
  Q_UNUSED(x);

  int scrollDirection = systemConfig(SystemConfig::zoomScrollDirection).toInt();
  qreal factor = 1.0 + qreal(scrollDirection * m_numScheduledScalings) / 300.0;
  scale(factor, factor);
}

void GraphicsView::onAnimFinished() {
  if (m_numScheduledScalings > 0) {
    --m_numScheduledScalings;
  } else {
    ++m_numScheduledScalings;
  }
  sender()->~QObject();
}

#include "exporttransparentpngaction.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/systemconfig.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QImage>

ExportTransparentPngAction::ExportTransparentPngAction(QObject* parent) : ExportPngAction(parent) {
}

ExportTransparentPngAction::~ExportTransparentPngAction() {
}

void ExportTransparentPngAction::init() {
  QAction* exportAction = new QAction("Export PNG(Transparent)");
  connect(exportAction, &QAction::triggered, this, &ExportTransparentPngAction::execute);
  m_actions << exportAction;
}

QImage ExportTransparentPngAction::imageFromGraphicsView(const QGraphicsView* graphicsView) const {
  QGraphicsScene* scene = graphicsView->scene();
  scene->clearSelection();
  scene->setSceneRect(scene->itemsBoundingRect());
  QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
  image.fill(Qt::transparent);

  return image;
}

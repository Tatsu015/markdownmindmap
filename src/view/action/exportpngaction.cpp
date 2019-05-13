#include "exportpngaction.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/systemconfig.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QImage>

ExportPngAction::ExportPngAction(QObject* parent) : AbstractAction(parent) {
  QAction* exportAction = new QAction("Export PNG");
  connect(exportAction, &QAction::triggered, this, &ExportPngAction::execute);
  m_actions << exportAction;
}

ExportPngAction::~ExportPngAction() {
}

void ExportPngAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  QString filePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("Export PNG file"), QDir::currentPath(),
                                                  QObject::tr("png files (*.png)"));

  QFile f(filePath);
  if (!f.open(QIODevice::WriteOnly)) {
    return;
  }

  QGraphicsView* graphicsView = Application::getInstance()->ui()->graphicsView;
  QGraphicsScene* scene = graphicsView->scene();
  scene->clearSelection();
  scene->setSceneRect(scene->itemsBoundingRect());
  QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);

  if (systemConfig(SystemConfig::exportPngTransparent).toBool()) {
    image.fill(Qt::transparent);
  } else {
    image.fill(graphicsView->backgroundBrush().color());
  }

  QPainter painter(&image);
  scene->render(&painter);
  image.save(filePath);
}

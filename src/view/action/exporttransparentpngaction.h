#ifndef ExportTransparentPngAction_H
#define ExportTransparentPngAction_H

#include "view/action/exportpngaction.h"

class ExportTransparentPngAction : public ExportPngAction {
public:
  ExportTransparentPngAction(QObject* parent = nullptr);
  virtual ~ExportTransparentPngAction();

  virtual void init();

protected:
  virtual QImage imageFromGraphicsView(const QGraphicsView* graphicsView) const;
};

#endif // ExportTransparentPngAction_H

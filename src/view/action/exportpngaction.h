#ifndef EXPORTPNGACTION_H
#define EXPORTPNGACTION_H

#include "view/action/abstractaction.h"

class QGraphicsView;

class ExportPngAction : public AbstractAction {
public:
  ExportPngAction(QObject* parent = nullptr);
  virtual ~ExportPngAction();

  virtual void init();

protected:
  virtual QImage imageFromGraphicsView(const QGraphicsView* graphicsView) const;

protected slots:
  void execute();
};

#endif // EXPORTPNGACTION_H

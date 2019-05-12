#ifndef ExportPngAction_H
#define ExportPngAction_H

#include "view/action/abstractaction.h"

class ExportPngAction : public AbstractAction {
public:
  ExportPngAction(QObject* parent = nullptr);
  virtual ~ExportPngAction();

protected slots:
  virtual void execute();
};

#endif // ExportPngAction_H

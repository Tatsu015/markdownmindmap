#ifndef EXPORTPNGACTION_H
#define EXPORTPNGACTION_H

#include "view/action/abstractaction.h"

class ExportPngAction : public AbstractAction {
public:
  ExportPngAction(QObject* parent = nullptr);
  virtual ~ExportPngAction();

protected slots:
  void execute();
};

#endif // EXPORTPNGACTION_H

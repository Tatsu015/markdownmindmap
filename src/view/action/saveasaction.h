#ifndef SAVEASACTION_H
#define SAVEASACTION_H

#include "view/action/abstractaction.h"

class SaveAsAction : public AbstractAction {
public:
  SaveAsAction(QObject* parent = nullptr);
  virtual ~SaveAsAction();

protected slots:
  virtual void execute();
};

#endif // SAVEASACTION_H

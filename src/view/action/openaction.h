#ifndef OPENACTION_H
#define OPENACTION_H

#include "view/action/abstractaction.h"

class OpenAction : public AbstractAction {
public:
  OpenAction(QObject* parent = nullptr);
  virtual ~OpenAction();

protected slots:
  virtual void execute();
};

#endif // OPENACTION_H

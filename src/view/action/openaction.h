#ifndef OPENACTION_H
#define OPENACTION_H

#include "view/action/abstractaction.h"

class OpenAction : public AbstractAction {
public:
  OpenAction(QObject* parent = nullptr);
  virtual ~OpenAction();

  virtual void init();

protected slots:
  void execute();
};

#endif // OPENACTION_H

#ifndef EXITACTION_H
#define EXITACTION_H

#include "view/action/abstractaction.h"

class ExitAction : public AbstractAction {
public:
  ExitAction(QObject* parent = nullptr);
  virtual ~ExitAction();

  virtual void init();

protected slots:
  void execute();
};

#endif // EXITACTION_H

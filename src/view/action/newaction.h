#ifndef NEWACTION_H
#define NEWACTION_H

#include "view/action/abstractaction.h"

class NewAction : public AbstractAction {
public:
  NewAction(QObject* parent = nullptr);
  virtual ~NewAction();

  virtual void init();

protected slots:
  void execute();
};

#endif // NEWACTION_H

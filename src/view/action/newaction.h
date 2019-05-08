#ifndef NEWACTION_H
#define NEWACTION_H

#include "view/action/abstractaction.h"

class NewAction : public AbstractAction {
public:
  NewAction(QObject* parent = nullptr);
  virtual ~NewAction();

protected slots:
  virtual void execute();
};

#endif // NEWACTION_H

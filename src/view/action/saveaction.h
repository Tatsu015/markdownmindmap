#ifndef SAVEACTION_H
#define SAVEACTION_H

#include "view/action/abstractaction.h"

class SaveAction : public AbstractAction {
public:
  SaveAction(QObject* parent = nullptr);
  virtual ~SaveAction();

  virtual void init();

protected slots:
  void execute();
};

#endif // SAVEACTION_H

#ifndef ChangeLeftToRightLayoutAction_H
#define ChangeLeftToRightLayoutAction_H

#include "view/action/abstractaction.h"

class ChangeLeftToRightLayoutAction : public AbstractAction {
public:
  ChangeLeftToRightLayoutAction(QObject* parent = nullptr);
  virtual ~ChangeLeftToRightLayoutAction();

protected slots:
  virtual void execute();
};

#endif // ChangeLeftToRightLayoutAction_H

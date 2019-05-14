#ifndef ChangeLeftToRightLayoutAction_H
#define ChangeLeftToRightLayoutAction_H

#include "view/action/abstractaction.h"

class QActionGroup;

class ChangeLayoutAction : public AbstractAction {
public:
  ChangeLayoutAction(QObject* parent = nullptr);
  virtual ~ChangeLayoutAction();

protected slots:
  void execute();

private:
  void setDefaultAction(QAction* activeAction);

private:
  QActionGroup* actionGroup = nullptr;
};

#endif // ChangeLeftToRightLayoutAction_H

#ifndef ChangeLeftToRightLayoutAction_H
#define ChangeLeftToRightLayoutAction_H

#include "view/action/abstractaction.h"

class QActionGroup;

class ChangeLeftToRightLayoutAction : public AbstractAction {
public:
  ChangeLeftToRightLayoutAction(QObject* parent = nullptr);
  virtual ~ChangeLeftToRightLayoutAction();

protected slots:
  void execute();

private:
  void setDefaultAction(QAction* activeAction);

private:
  QActionGroup* actionGroup = nullptr;
};

#endif // ChangeLeftToRightLayoutAction_H

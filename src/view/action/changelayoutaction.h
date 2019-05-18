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
  void addAction(QAction* action);
  void setDefaultAction(QAction* activeAction);

private:
  QActionGroup* m_actionGroup = nullptr;
};

#endif // ChangeLeftToRightLayoutAction_H

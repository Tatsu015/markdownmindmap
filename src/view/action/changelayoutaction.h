#ifndef CHANGELAYOUTACTION_H
#define CHANGELAYOUTACTION_H

#include "view/action/abstractaction.h"

class QActionGroup;

class ChangeLayoutAction : public AbstractAction {
public:
  ChangeLayoutAction(QObject* parent = nullptr);
  virtual ~ChangeLayoutAction();

  virtual void init();

protected slots:
  void execute();

private:
  void addAction(QAction* action);
  void setDefaultAction(QAction* activeAction);

private:
  QActionGroup* m_actionGroup = nullptr;
};

#endif // CHANGELAYOUTACTION_H

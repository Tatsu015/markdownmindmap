#ifndef ABSTRACTACTION_H
#define ABSTRACTACTION_H

#include <QObject>

class QAction;

class AbstractAction : public QObject {
  Q_OBJECT

public:
  AbstractAction(QObject* parent = nullptr);
  virtual ~AbstractAction();
  virtual void init() = 0;

  QList<QAction*> actions() const;

protected:
  QList<QAction*> m_actions;
};

#endif // ABSTRACTACTION_H

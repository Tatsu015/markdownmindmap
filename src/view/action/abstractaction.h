#ifndef ABSTRACTACTION_H
#define ABSTRACTACTION_H

#include <QObject>

class QAction;

class AbstractAction : public QObject {
  Q_OBJECT

public:
  AbstractAction(QObject* parent = nullptr);
  virtual ~AbstractAction();

  QAction* action() const;

protected slots:
  virtual void execute() = 0;

protected:
  QAction* m_action = nullptr;
};

#endif // ABSTRACTACTION_H

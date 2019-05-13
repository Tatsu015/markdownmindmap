#include "abstractaction.h"
#include <QAction>

AbstractAction::AbstractAction(QObject* parent) : QObject(parent) {
}

AbstractAction::~AbstractAction() {
}

QList<QAction*> AbstractAction::actions() const {
  return m_actions;
}

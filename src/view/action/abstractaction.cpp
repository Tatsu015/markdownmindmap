#include "abstractaction.h"
#include <QAction>

AbstractAction::AbstractAction(QObject* parent) : QObject(parent) {
}

AbstractAction::~AbstractAction() {
}

QAction* AbstractAction::action() const {
  return m_action;
}

#include "abstractkeybehavior.h"
#include <QKeyEvent>

AbstractKeyBehavior::AbstractKeyBehavior() {
}

AbstractKeyBehavior::~AbstractKeyBehavior() {
}

void AbstractKeyBehavior::keyPressEvent(CodeEditor* codeEditor, QKeyEvent* event) {
  if (event->modifiers() == Qt::NoModifier) {
    noModifierKeyPressEvent(codeEditor);
  } else if (event->modifiers() & Qt::ControlModifier) {
    controlModifierKeyPressEvent(codeEditor);
  } else if (event->modifiers() & Qt::ShiftModifier) {
    shiftModifierKeyPressEvent(codeEditor);
  } else if (event->modifiers() & Qt::AltModifier) {
    altModifierKeyPressEvent(codeEditor);
  } else {
  }
}

void AbstractKeyBehavior::controlModifierKeyPressEvent(CodeEditor* codeEditor) {
  Q_UNUSED(codeEditor);
}

void AbstractKeyBehavior::shiftModifierKeyPressEvent(CodeEditor* codeEditor) {
  Q_UNUSED(codeEditor);
}

void AbstractKeyBehavior::altModifierKeyPressEvent(CodeEditor* codeEditor) {
  Q_UNUSED(codeEditor);
}

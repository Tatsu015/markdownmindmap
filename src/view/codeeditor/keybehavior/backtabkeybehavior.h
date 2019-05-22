#ifndef BACKTABKEYBEHAVIOR_H
#define BACKTABKEYBEHAVIOR_H

#include "view/codeeditor/keybehavior/abstractkeybehavior.h"

class BackTabKeyBehavior : public AbstractKeyBehavior {
public:
  BackTabKeyBehavior();
  virtual ~BackTabKeyBehavior();

protected:
  virtual void noModifierKeyPressEvent(CodeEditor* codeEditor);
  virtual void shiftModifierKeyPressEvent(CodeEditor* codeEditor);
};

#endif // BACKTABKEYBEHAVIOR_H

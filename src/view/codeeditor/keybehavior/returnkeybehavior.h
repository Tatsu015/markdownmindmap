#ifndef RETURNKEYBEHAVIOR_H
#define RETURNKEYBEHAVIOR_H

#include "view/codeeditor/keybehavior/abstractkeybehavior.h"

class ReturnKeyBehavior : public AbstractKeyBehavior {
public:
  ReturnKeyBehavior();
  virtual ~ReturnKeyBehavior();

protected:
  virtual void noModifierKeyPressEvent(CodeEditor* codeEditor);
  virtual void controlModifierKeyPressEvent(CodeEditor* codeEditor);
};

#endif // RETURNKEYBEHAVIOR_H

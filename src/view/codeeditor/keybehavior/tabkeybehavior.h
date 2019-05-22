#ifndef TABKEYBEHAVIOR_H
#define TABKEYBEHAVIOR_H

#include "view/codeeditor/keybehavior/abstractkeybehavior.h"

class TabKeyBehavior : public AbstractKeyBehavior {
public:
  TabKeyBehavior();
  virtual ~TabKeyBehavior();

protected:
  virtual void noModifierKeyPressEvent(CodeEditor* codeEditor);
};

#endif // TABKEYBEHAVIOR_H

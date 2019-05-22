#ifndef ABSTRACTKEYBEHAVIOR_H
#define ABSTRACTKEYBEHAVIOR_H

#include <qnamespace.h>

class CodeEditor;
class QKeyEvent;

class AbstractKeyBehavior {
public:
  AbstractKeyBehavior();
  virtual ~AbstractKeyBehavior();

  void keyPressEvent(CodeEditor* codeEditor, QKeyEvent* event);

protected:
  virtual void noModifierKeyPressEvent(CodeEditor* codeEditor) = 0;
  virtual void controlModifierKeyPressEvent(CodeEditor* codeEditor);
  virtual void shiftModifierKeyPressEvent(CodeEditor* codeEditor);
  virtual void altModifierKeyPressEvent(CodeEditor* codeEditor);
};

#endif // ABSTRACTKEYBEHAVIOR_H

#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>

class AbstractKeyBehavior;

class CodeEditor : public QPlainTextEdit {
  Q_OBJECT

public:
  CodeEditor(QWidget* parent = nullptr);
  virtual ~CodeEditor();

protected:
  virtual void keyPressEvent(QKeyEvent* event) override;

  virtual void dropEvent(QDropEvent* event) override;

private:
  QMap<Qt::Key, AbstractKeyBehavior*> m_keyBehavior;
};

#endif // CODEEDITOR_H

#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>

class CodeEditor : public QPlainTextEdit {
  Q_OBJECT

public:
  CodeEditor(QWidget* parent = nullptr);
  virtual ~CodeEditor();

protected:
  virtual void keyPressEvent(QKeyEvent* event) override;
};

#endif // CODEEDITOR_H

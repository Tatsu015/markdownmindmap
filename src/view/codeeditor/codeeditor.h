#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QTextEdit>

class Document;

class CodeEditor : public QTextEdit {
  Q_OBJECT

public:
  CodeEditor(QWidget* parent = nullptr);
  virtual ~CodeEditor();

private slots:
  void onUpdateDocument();
};

#endif // CODEEDITOR_H

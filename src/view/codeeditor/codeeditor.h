#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QTextEdit>

class QTimer;

class CodeEditor : public QTextEdit {
  Q_OBJECT

public:
  CodeEditor(QWidget* parent = nullptr);
  virtual ~CodeEditor();

private slots:
  void onStartTimer();
  void onUpdateModel();

private:
  QTimer* m_timer = nullptr;
};

#endif // CODEEDITOR_H

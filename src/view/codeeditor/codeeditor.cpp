#include "codeeditor.h"
#include "model/document.h"

CodeEditor::CodeEditor(QWidget* parent) : QTextEdit(parent) {
  connect(this, &CodeEditor::textChanged, this, &CodeEditor::onUpdateDocument);
}

CodeEditor::~CodeEditor() {
}

void CodeEditor::onUpdateDocument() {
  Document* doc = dynamic_cast<Document*>(document());
  if (doc) {
    doc->setData(toPlainText());
  }
}

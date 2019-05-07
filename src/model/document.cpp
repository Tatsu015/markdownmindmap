#include "document.h"

Document::Document(QObject* parent) : QTextDocument(parent) {
}

Document::~Document() {
}

QString Document::filePath() const {
  return m_filePath;
}

void Document::setFilePath(const QString& filePath) {
  m_filePath = filePath;
}

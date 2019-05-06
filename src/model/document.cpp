#include "document.h"

Document::Document(QObject* parent) : QTextDocument(parent) {
}

Document::~Document() {
}

void Document::setData(const QString& data) {
  m_data = data;
}

QString Document::data() const {
  return m_data;
}

QString Document::filePath() const {
  return m_filePath;
}

void Document::setFilePath(const QString& filePath) {
  m_filePath = filePath;
}

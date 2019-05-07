#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QTextDocument>

class Document : public QTextDocument {
public:
  Document(QObject* parent = nullptr);
  virtual ~Document();

  QString filePath() const;
  void setFilePath(const QString& filePath);

private:
  QString m_filePath;
};

#endif // DOCUMENT_H

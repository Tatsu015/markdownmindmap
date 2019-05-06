#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QTextDocument>

class Document : public QTextDocument {
public:
  Document(QObject* parent = nullptr);
  virtual ~Document();

  void setData(const QString& data);
  QString data() const;

  QString filePath() const;
  void setFilePath(const QString& filePath);

private:
  QString m_data;
  QString m_filePath;
};

#endif // DOCUMENT_H

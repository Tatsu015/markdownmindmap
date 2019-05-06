#ifndef MARKDOWNPARSER_H
#define MARKDOWNPARSER_H

#include <QString>
class Node;

class MarkdownParser {
public:
  static MarkdownParser* getInstance();
  Node* parse(const QString& data);

private:
  QStringList removeComment(const QString& data);
  bool hasError(QStringList validLines);
  uint32_t indentCount(const QString& oneLine);

private:
  MarkdownParser();
  ~MarkdownParser();
};

#endif // MARKDOWNPARSER_H

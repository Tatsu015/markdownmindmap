#ifndef MARKDOWNPARSER_H
#define MARKDOWNPARSER_H

#include <QString>
class Node;

class MarkdownParser {
public:
  MarkdownParser();
  ~MarkdownParser();
  Node* parse(const QString& data);

private:
  QStringList toValidLines(const QString& data);
  bool isValidLine(const QString& line) const;
  bool hasRootNode(QString rootLine);
  bool hasMonoRootNode(QStringList validLines);
  uint32_t indentCount(const QString& oneLine);
};

#endif // MARKDOWNPARSER_H

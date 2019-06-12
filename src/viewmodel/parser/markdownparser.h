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
  bool hasRootNode(const QString rootLine) const;
  bool hasMonoRootNode(QStringList validLines) const;
};

#endif // MARKDOWNPARSER_H

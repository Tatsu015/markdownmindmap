#include "markdownparser.h"
#include "model/node.h"
#include <QDebug>

const static QString COMMENT_KEYWORD = "#";
const static QChar INDENT_KEYWORD = ' ';
const static QString RETURN_CODE = "\n";

MarkdownParser* MarkdownParser::getInstance() {
  static MarkdownParser s;
  return &s;
}

Node* MarkdownParser::parse(const QString& data) {
  QStringList validLines = removeComment(data);

  if (hasError(validLines)) {
    return nullptr;
  }

  QString rootLine = validLines.takeFirst();

  Node* rootNode = new Node(rootLine, 0);
  Node* lastNode = rootNode;
  Node* currentNode = nullptr;

  foreach (QString validLine, validLines) {
    uint32_t depth = indentCount(validLine);
    QString text = validLine.simplified();
    currentNode = new Node(text, depth);
    if (currentNode->depth() == lastNode->depth()) {
      lastNode->parentNode()->addChildNode(currentNode);
    } else if (currentNode->depth() < lastNode->depth()) {
      uint32_t depthDiff = static_cast<uint32_t>(lastNode->depth() - currentNode->depth());
      Node* parentNode = lastNode->parentNode();
      for (uint32_t d = 0; d < depthDiff; ++d) {
        parentNode = parentNode->parentNode();
      }
      parentNode->addChildNode(currentNode);
    } else if (currentNode->depth() > lastNode->depth()) {
      lastNode->addChildNode(currentNode);
    }
    lastNode = currentNode;
  }
  return rootNode;
}

QStringList MarkdownParser::removeComment(const QString& data) {
  QStringList validLines;
  foreach (QString line, data.split(RETURN_CODE, QString::SkipEmptyParts)) {
    if (!line.contains(COMMENT_KEYWORD)) {
      validLines << line;
    }
  }
  return validLines;
}

bool MarkdownParser::hasError(QStringList validLines) {
  if (validLines.isEmpty()) {
    qDebug() << "ERROR! any data exist!";
    return true;
  }

  QString rootLine = validLines.takeFirst();
  uint32_t rootIndent = indentCount(rootLine);
  if (0 != rootIndent) {
    qDebug() << "ERROR! no root item exist!";
    return true;
  }

  foreach (QString validLine, validLines) {
    uint32_t depth = indentCount(validLine);
    if (0 == depth) {
      qDebug() << "Error! two or more root data exist!";
      return true;
    }
  }
  return false;
}

uint32_t MarkdownParser::indentCount(const QString& oneLine) {
  uint32_t count = 0;
  if (0 >= oneLine.count()) {
    return 0;
  }
  while (INDENT_KEYWORD == oneLine[count]) {
    ++count;
  }
  return count;
}

MarkdownParser::MarkdownParser() {
}

MarkdownParser::~MarkdownParser() {
}

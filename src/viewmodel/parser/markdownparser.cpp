#include "markdownparser.h"
#include "utility/stringutil.h"
#include "viewmodel/graphicsitem/node.h"
#include <QDebug>

const static QString RETURN_CODE = "\n";

MarkdownParser::MarkdownParser() {
}

MarkdownParser::~MarkdownParser() {
}

Node* MarkdownParser::parse(const QString& data) {
  QStringList validLines = data.split("\n");

  if (validLines.isEmpty()) {
    return nullptr;
  }

  QString rootLine = validLines.takeFirst();
  QStringList childLines = validLines;

  if (!hasRootNode(rootLine)) {
    return nullptr;
  }
  if (!hasMonoRootNode(childLines)) {
    return nullptr;
  }

  uint32_t lineCount = 1;
  Node* rootNode = new Node(rootLine, 0, lineCount);
  Node* lastNode = rootNode;
  Node* currentNode = nullptr;

  foreach (QString validLine, childLines) {
    ++lineCount;
    if (!isValidLine(validLine)) {
      continue;
    }
    uint32_t depth = indentCount(validLine);
    QString text = validLine.simplified();
    currentNode = new Node(text, depth, lineCount);
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

QStringList MarkdownParser::toValidLines(const QString& data) {
  QStringList validLines;
  foreach (QString line, data.split(RETURN_CODE, QString::SkipEmptyParts)) {
    // skip only blank line
    if (!line.simplified().isEmpty()) {
      validLines << line;
    }
  }
  return validLines;
}

bool MarkdownParser::isValidLine(const QString& line) const {
  if (line.simplified().isEmpty()) {
    return false;
  }
  return true;
}

bool MarkdownParser::hasRootNode(QString rootLine) {
  uint32_t rootIndent = indentCount(rootLine);
  if (0 == rootIndent) {
    return true;
  }
  return false;
}

bool MarkdownParser::hasMonoRootNode(QStringList validLines) {
  foreach (QString validLine, validLines) {
    if (!isValidLine(validLine)) {
      continue;
    }
    uint32_t depth = indentCount(validLine);
    if (0 == depth) {
      return false;
    }
  }
  return true;
}

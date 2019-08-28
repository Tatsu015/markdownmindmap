#include "stringutil.h"

uint32_t indentCount(const QString& data, const QChar indentKey) {
  uint32_t count = 0;
  if (0 >= data.count()) {
    return 0;
  }
  QString unIndentKeyData = data;
  unIndentKeyData = unIndentKeyData.replace(indentKey, "");
  if (0 >= unIndentKeyData.count()) {
    return 0;
  }
  while (indentKey == data[count]) {
    ++count;
  }
  return count;
}

QString extractIndent(const QString& data, const QChar indentKey) {
  QString indent;
  return indent.fill(indentKey, indentCount(data, indentKey));
}

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <QString>

extern uint32_t indentCount(const QString& data, const QChar indentKey = ' ');
extern QString extractIndent(const QString& data, const QChar indentKey = ' ');

#endif // STRINGUTIL_H

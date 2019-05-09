#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include <QJsonObject>
#include <QMap>
#include <QVariant>

class SystemConfig {
public:
  const static QString CONF_TEXT_COLOR;
  const static QString CONF_BACKGROUND_COLOR;

public:
  static SystemConfig* getInstance();

  QVariant systemConfig(const QString& key);

  void loadSystemConfig(const QString& filePath);
  void saveSystemConfig(const QString& filePath);

private:
  QJsonObject m_systemConfig;

private:
  SystemConfig();
  ~SystemConfig();
};

#endif // SYSTEMCONFIG_H

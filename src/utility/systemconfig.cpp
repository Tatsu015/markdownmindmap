#include "systemconfig.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>

const QString SystemConfig::CONF_TEXT_COLOR = "textColor";
const QString SystemConfig::CONF_BACKGROUND_COLOR = "backgroundColor";
const QString SystemConfig::CONF_STYLESHEET_FILE_PATH = "styleSheetPath";

SystemConfig* SystemConfig::getInstance() {
  static SystemConfig s;
  return &s;
}

QVariant SystemConfig::systemConfig(const QString& key) {
  return m_systemConfig.value(key).toVariant();
}

void SystemConfig::loadSystemConfig(const QString& filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << "Error! file read error!" << filePath;
    file.close();
  }

  QByteArray saveData = file.readAll();
  m_systemConfig = QJsonDocument::fromJson(saveData).object();
  qDebug() << m_systemConfig;
  file.close();
}

void SystemConfig::saveSystemConfig(const QString& filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::WriteOnly)) {
    qDebug() << "Error! file write error!" << filePath;
    file.close();
  }

  QJsonDocument saveDocument(m_systemConfig);
  QTextStream out(&file);
  out << saveDocument.toJson();
  file.close();
}

SystemConfig::SystemConfig() {
}

SystemConfig::~SystemConfig() {
}

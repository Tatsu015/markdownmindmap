#include "systemconfig.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

static QJsonObject m_config;

QVariant systemConfig(const QString& name) {
  return m_config.value(name).toVariant();
}

void loadSystemConfig(const QString& filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << "Error! file read error!" << filePath;
    file.close();
  }

  QByteArray saveData = file.readAll();
  m_config = QJsonDocument::fromJson(saveData).object();
  qDebug() << m_config;
  file.close();
}

void saveSystemConfig(const QString& filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::WriteOnly)) {
    qDebug() << "Error! file write error!" << filePath;
    file.close();
  }

  QJsonDocument saveDocument(m_config);
  QTextStream out(&file);
  out << saveDocument.toJson();
  file.close();
}

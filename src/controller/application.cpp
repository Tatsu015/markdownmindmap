#include "application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/systemconfig.h"
#include <QFile>
#include <QTextStream>
#include <QTimer>

const static QString SYSTEM_CONFIG_FILE = "../conf/system.conf";
const static QString AUTOSAVE_FILEPATH = ".autosave";

Application* Application::getInstance() {
  static Application s;
  return &s;
}

void Application::setUp() {
  loadSystemConfig(SYSTEM_CONFIG_FILE);

  m_timer = new QTimer();
  connect(m_timer, &QTimer::timeout, this, &Application::onAutoSave);
  m_timer->start(systemConfig(SystemConfig::autoSaveInterval).toInt());
}

void Application::tearDown() {
  m_timer->stop();
  saveSystemConfig(SYSTEM_CONFIG_FILE);
  QFile autoSaveFile(AUTOSAVE_FILEPATH);
  autoSaveFile.remove();
}

Document* Application::document() const {
  return m_document;
}

void Application::setDocument(Document* document) {
  m_document = document;
}

Ui::MainWindow* Application::ui() const {
  return m_ui;
}

void Application::setUi(Ui::MainWindow* ui) {
  m_ui = ui;
}

void Application::recoverLastCrash() {
  QFile backupFile(AUTOSAVE_FILEPATH);
  if (!backupFile.exists()) {
    return;
  }

  QFile f(AUTOSAVE_FILEPATH);
  if (!f.open(QIODevice::ReadOnly)) {
    return;
  }
  QTextStream in(&f);
  const QString readData = in.readAll();
  m_document->setPlainText(readData);

  m_ui->statusBar->showMessage("Auto fix last crash file.", 10000);
}

void Application::onAutoSave() {
  QFile f(AUTOSAVE_FILEPATH);
  if (!f.open(QIODevice::WriteOnly)) {
    return;
  }
  QTextStream out(&f);
  out << Application::getInstance()->document()->toPlainText();
  f.close();
}

Application::Application(QObject* parent) : QObject(parent) {
}

Application::~Application() {
}

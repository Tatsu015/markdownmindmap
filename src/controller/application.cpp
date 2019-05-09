#include "application.h"
#include "utility/systemconfig.h"

const static QString SYSTEM_CONFIG_FILE = "../conf/system.conf";

Application* Application::getInstance() {
  static Application s;
  return &s;
}

void Application::setUp() {
  SystemConfig::getInstance()->loadSystemConfig(SYSTEM_CONFIG_FILE);
}

void Application::tearDown() {
  SystemConfig::getInstance()->saveSystemConfig(SYSTEM_CONFIG_FILE);
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

Application::Application() {
}

Application::~Application() {
}

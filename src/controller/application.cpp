#include "application.h"

Application* Application::getInstance() {
  static Application s;
  return &s;
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

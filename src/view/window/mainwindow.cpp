#include "mainwindow.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "view/action/exitaction.h"
#include "view/action/newaction.h"
#include "view/action/openaction.h"
#include "view/action/saveaction.h"
#include "viewmodel/graphicsitem/node.h"
#include "viewmodel/scene/scene.h"
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), m_ui(new Ui::MainWindow), m_scene(new Scene()) {
  m_ui->setupUi(this);

  Application::getInstance()->setUp();
  Document* doc = new Document();
  Application::getInstance()->setDocument(doc);
  m_ui->textEdit->setDocument(doc);
  Application::getInstance()->setUi(m_ui);

  setupScene();
  setupMenu();
  setupStyleSheet();
}

MainWindow::~MainWindow() {
  Application::getInstance()->tearDown();
  delete m_ui;
}

void MainWindow::setupScene() {
  m_ui->graphicsView->setScene(m_scene);
}

void MainWindow::setupMenu() {
  QMenu* fileMenu = new QMenu("File");
  setupAction(fileMenu, new NewAction());
  setupAction(fileMenu, new OpenAction());
  setupAction(fileMenu, new SaveAction());
  setupAction(fileMenu, new ExitAction());

  m_ui->menuBar->addMenu(fileMenu);
}

void MainWindow::setupStyleSheet() {
  QFile file("../resource/stylesheet/DarkAndBlue.css");
  if (file.open(QIODevice::ReadOnly)) {
    qApp->setStyleSheet(file.readAll());
  }
}

void MainWindow::setupAction(QMenu* menu, AbstractAction* action) {
  menu->addAction(action->action());
}

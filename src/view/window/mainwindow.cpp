#include "mainwindow.h"
#include "controller/application.h"
#include "controller/parser/markdownparser.h"
#include "model/document.h"
#include "model/graphics/node.h"
#include "model/graphics/proxy/lefttorighttreelayoutproxy.h"
#include "model/graphics/scene.h"
#include "ui_mainwindow.h"
#include "view/action/exitaction.h"
#include "view/action/openaction.h"
#include "view/action/saveaction.h"
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), m_ui(new Ui::MainWindow), m_scene(new Scene()) {
  m_ui->setupUi(this);

  Document* doc = new Document();
  Application::getInstance()->setDocument(doc);
  m_ui->textEdit->setDocument(doc);
  Application::getInstance()->setUi(m_ui);

  setupScene();
  setupMenu();
  setupStyleSheet();
}

MainWindow::~MainWindow() {
  delete m_ui;
}

void MainWindow::setupScene() {
  m_ui->graphicsView->setScene(m_scene);
}

void MainWindow::setupMenu() {
  QMenu* fileMenu = new QMenu("File");
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

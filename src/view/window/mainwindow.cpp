#include "mainwindow.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/systemconfig.h"
#include "view/action/changelayoutaction.h"
#include "view/action/exitaction.h"
#include "view/action/exportpngaction.h"
#include "view/action/newaction.h"
#include "view/action/openaction.h"
#include "view/action/saveaction.h"
#include "view/action/saveasaction.h"
#include "viewmodel/graphicsitem/node.h"
#include "viewmodel/scene/scene.h"
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), m_ui(new Ui::MainWindow) {
  Application::getInstance()->setUp();

  m_ui->setupUi(this);

  Document* doc = new Document();
  m_scene = new Scene(doc);
  Application::getInstance()->setDocument(doc);
  m_ui->textEdit->setDocument(doc);
  Application::getInstance()->setUi(m_ui);
  m_ui->graphicsView->setScene(m_scene);

  setupScene();
  setupMenu();
  setupStyleSheet();
}

MainWindow::~MainWindow() {
  Application::getInstance()->tearDown();
  delete m_ui;
}

void MainWindow::setupScene() {
}

void MainWindow::setupMenu() {
  QMenu* fileMenu = new QMenu("File");
  m_ui->menuBar->addMenu(fileMenu);
  setupAction(fileMenu, new NewAction());
  setupAction(fileMenu, new OpenAction());
  setupAction(fileMenu, new SaveAction());
  setupAction(fileMenu, new SaveAsAction());
  setupAction(fileMenu, new ExitAction());

  QMenu* toolMenu = new QMenu("Tool");
  m_ui->menuBar->addMenu(toolMenu);
  setupAction(toolMenu, new ExportPngAction());

  QMenu* viewMenu = new QMenu("View");
  m_ui->menuBar->addMenu(viewMenu);
  QMenu* treeLayout = new QMenu("Tree Layout");
  viewMenu->addMenu(treeLayout);
  setupAction(treeLayout, new ChangeLayoutAction());
}

void MainWindow::setupStyleSheet() {
  const QString styleSheetPath = systemConfig(SystemConfig::styleSheetPath).toString();
  QFile file(styleSheetPath);
  if (file.open(QIODevice::ReadOnly)) {
    qApp->setStyleSheet(file.readAll());
  }
}

void MainWindow::setupAction(QMenu* menu, AbstractAction* action) {
  menu->addActions(action->actions());
}

#include "mainwindow.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "utility/systemconfig.h"
#include "view/action/changelayoutaction.h"
#include "view/action/exitaction.h"
#include "view/action/exportpngaction.h"
#include "view/action/exporttransparentpngaction.h"
#include "view/action/newaction.h"
#include "view/action/openaction.h"
#include "view/action/saveaction.h"
#include "view/action/saveasaction.h"
#include "viewmodel/graphicsitem/node.h"
#include "viewmodel/scene/scene.h"
#include <QKeyEvent>
#include <QPlainTextDocumentLayout>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), m_ui(new Ui::MainWindow) {
  Application::getInstance()->setUp();
  Application::getInstance()->setUi(m_ui);

  m_ui->setupUi(this);

  setupDocument();
  setupScene();
  setupGraphicsView();
  setupMenu();
  setupStyleSheet();

  Application::getInstance()->recoverLastCrash();
}

MainWindow::~MainWindow() {
  Application::getInstance()->tearDown();
  delete m_ui;
}

void MainWindow::setupDocument() {
  Document* doc = new Document();
  QPlainTextDocumentLayout* documentLayout = new QPlainTextDocumentLayout(doc);
  doc->setDocumentLayout(documentLayout);
  Application::getInstance()->setDocument(doc);
  m_ui->codeEditor->setDocument(doc);
}

void MainWindow::setupScene() {
  m_scene = new Scene(Application::getInstance()->document());
  m_ui->graphicsView->setScene(m_scene);
}

void MainWindow::setupGraphicsView() {
  const qreal defaultViewSplitRate = systemConfig(SystemConfig::defaultViewSplitRate).toReal();
  const qreal lhs = defaultViewSplitRate * 100 * 10;
  const qreal rhs = (1 - defaultViewSplitRate) * 100 * 10;
  m_ui->splitter->setSizes(QList<int32_t>() << lhs << rhs);
}

void MainWindow::setupMenu() {
  QMenu* fileMenu = new QMenu("File");
  m_ui->menuBar->addMenu(fileMenu);
  setupAction(fileMenu, new NewAction());
  setupAction(fileMenu, new OpenAction());
  setupAction(fileMenu, new SaveAction());
  setupAction(fileMenu, new SaveAsAction());

  QMenu* exportMenu = new QMenu("Export");
  fileMenu->addMenu(exportMenu);
  setupAction(exportMenu, new ExportPngAction());
  setupAction(exportMenu, new ExportTransparentPngAction());
  setupAction(fileMenu, new ExitAction());

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
  action->init();
  menu->addActions(action->actions());
}

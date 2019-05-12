#include "changelefttorightlayoutaction.h"
#include "controller/application.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "viewmodel/scene/layoutproxy/lefttorighttreelayoutproxy.h"
#include "viewmodel/scene/scene.h"
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

ChangeLeftToRightLayoutAction::ChangeLeftToRightLayoutAction(QObject* parent) : AbstractAction(parent) {
  m_action = new QAction(LeftToRightTreeLayoutProxy::NAME);
  connect(m_action, &QAction::triggered, this, &ChangeLeftToRightLayoutAction::execute);
}

ChangeLeftToRightLayoutAction::~ChangeLeftToRightLayoutAction() {
}

void ChangeLeftToRightLayoutAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  Scene* scene = Application::getInstance()->ui()->graphicsView->customScene();
  scene->changeActiveLayoutDecolator(LeftToRightTreeLayoutProxy::NAME);
}

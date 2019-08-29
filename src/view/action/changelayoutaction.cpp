#include "changelayoutaction.h"
#include "controller/application.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "viewmodel/scene/layoutproxy/bothsidestreelayoutproxy.h"
#include "viewmodel/scene/layoutproxy/lefttorighttreelayoutproxy.h"
#include "viewmodel/scene/layoutproxy/toptobottomtreelayoutproxy.h"
#include "viewmodel/scene/scene.h"
#include "viewmodel/scene/scene.h"
#include <QAction>
#include <QActionGroup>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

ChangeLayoutAction::ChangeLayoutAction(QObject* parent)
    : AbstractAction(parent), m_actionGroup(new QActionGroup(nullptr)) {
}

ChangeLayoutAction::~ChangeLayoutAction() {
}

void ChangeLayoutAction::init() {
  addAction(new QAction(LeftToRightTreeLayoutProxy::NAME));
  addAction(new QAction(TopToBottomTreeLayoutProxy::NAME));
  addAction(new QAction(BothSidesTreeLayoutProxy::NAME));

  setDefaultAction(m_actions.first());
}

void ChangeLayoutAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  Scene* scene = Application::getInstance()->ui()->graphicsView->customScene();
  QAction* action = dynamic_cast<QAction*>(sender());
  scene->changeActiveLayoutDecolator(action->text());
}

void ChangeLayoutAction::addAction(QAction* action) {
  action->setCheckable(true);
  connect(action, &QAction::triggered, this, &ChangeLayoutAction::execute);
  m_actions << action;
  m_actionGroup->addAction(action);
}

void ChangeLayoutAction::setDefaultAction(QAction* activeAction) {
  activeAction->setChecked(true);
  Scene* scene = Application::getInstance()->ui()->graphicsView->customScene();
  scene->changeActiveLayoutDecolator(activeAction->text());
}

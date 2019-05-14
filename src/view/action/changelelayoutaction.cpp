#include "changelayoutaction.h"
#include "controller/application.h"
#include "controller/application.h"
#include "model/document.h"
#include "ui_mainwindow.h"
#include "viewmodel/scene/layoutproxy/lefttorighttreelayoutproxy.h"
#include "viewmodel/scene/layoutproxy/toptobottomtreelayoutproxy.h"
#include "viewmodel/scene/scene.h"
#include "viewmodel/scene/scene.h"
#include <QAction>
#include <QActionGroup>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

ChangeLayoutAction::ChangeLayoutAction(QObject* parent) : AbstractAction(parent) {
  QAction* leftToRightAction = new QAction(LeftToRightTreeLayoutProxy::NAME);
  leftToRightAction->setCheckable(true);
  connect(leftToRightAction, &QAction::triggered, this, &ChangeLayoutAction::execute);
  m_actions << leftToRightAction;

  QAction* topToBottomAction = new QAction(TopToBottomTreeLayoutProxy::NAME);
  topToBottomAction->setCheckable(true);
  connect(topToBottomAction, &QAction::triggered, this, &ChangeLayoutAction::execute);
  m_actions << topToBottomAction;

  actionGroup = new QActionGroup(nullptr);
  actionGroup->addAction(leftToRightAction);
  actionGroup->addAction(topToBottomAction);

  setDefaultAction(m_actions.first());
}

ChangeLayoutAction::~ChangeLayoutAction() {
}

void ChangeLayoutAction::execute() {
  emit Application::getInstance()->document()->contentsChanged();

  Scene* scene = Application::getInstance()->ui()->graphicsView->customScene();
  QAction* action = dynamic_cast<QAction*>(sender());
  scene->changeActiveLayoutDecolator(action->text());
}

void ChangeLayoutAction::setDefaultAction(QAction* activeAction) {
  activeAction->setChecked(true);
  Scene* scene = Application::getInstance()->ui()->graphicsView->customScene();
  scene->changeActiveLayoutDecolator(activeAction->text());
}

#include "layouter.h"
#include "controller/layouter/decorator/lefttorighttreelayoutdecorator.h"
#include <QDebug>

Layouter* Layouter::getInstance() {
  static Layouter s;
  return &s;
}

void Layouter::Layout(Node* node) {
  m_activeLayoutDecolator->layout(node);
}

void Layouter::addLayouterDecorator(AbstractLayouterDecorator* layoutDecolator) {
  m_layoutDecolators[layoutDecolator->name()] = layoutDecolator;
}

void Layouter::changeActiveLayoutDecolator(const QString& name) {
  m_activeLayoutDecolator = m_layoutDecolators.value(name, m_layoutDecolators[m_defaultLayoutDecolatorName]);
}

void Layouter::setDefaultLayoutDecolatorName(const QString& defaultLayoutDecolatorName) {
  m_defaultLayoutDecolatorName = defaultLayoutDecolatorName;
  m_activeLayoutDecolator = m_layoutDecolators[m_defaultLayoutDecolatorName];
}

Layouter::Layouter() {
}

Layouter::~Layouter() {
}

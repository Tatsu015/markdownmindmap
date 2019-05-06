#include "abstractlayouterdecorator.h"

AbstractLayouterDecorator::AbstractLayouterDecorator() {
}

AbstractLayouterDecorator::~AbstractLayouterDecorator() {
}

void AbstractLayouterDecorator::layout(Node* rootNode) {
  layoutChild(rootNode);
}

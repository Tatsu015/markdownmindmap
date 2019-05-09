#include "abstractlayoutproxy.h"

AbstractLayoutProxy::AbstractLayoutProxy() {
}

AbstractLayoutProxy::~AbstractLayoutProxy() {
}

void AbstractLayoutProxy::layout(Node* rootNode) {
  if (rootNode) {
    layoutChild(rootNode);
  }
}

#ifndef LAYOUTER_H
#define LAYOUTER_H

#include <QMap>

class Node;
class AbstractLayouterDecorator;

class Layouter {
public:
  static Layouter* getInstance();
  void Layout(Node* node);

  void addLayouterDecorator(AbstractLayouterDecorator* layoutDecolator);
  void changeActiveLayoutDecolator(const QString& name);
  void setDefaultLayoutDecolatorName(const QString& defaultLayoutDecolatorName);

private:
  QMap<QString, AbstractLayouterDecorator*> m_layoutDecolators;
  AbstractLayouterDecorator* m_activeLayoutDecolator = nullptr;
  QString m_defaultLayoutDecolatorName;

private:
  Layouter();
  ~Layouter();
};

#endif // LAYOUTER_H

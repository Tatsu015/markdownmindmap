#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class AbstractAction;
class Scene;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr);
  virtual ~MainWindow();

private:
  void setupScene();
  void setupLayouter();
  void setupMenu();
  void setupStyleSheet();

  void setupAction(QMenu* menu, AbstractAction* action);

private:
  Ui::MainWindow* m_ui = nullptr;
  Scene* m_scene = nullptr;
};

#endif // MAINWINDOW_H

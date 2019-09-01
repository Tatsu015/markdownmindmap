#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

class QTimer;
class Document;
namespace Ui {
class MainWindow;
}

class Application : public QObject {
  Q_OBJECT

public:
  static Application* getInstance();
  void setUp();
  void tearDown();

  Document* document() const;
  void setDocument(Document* document);

  Ui::MainWindow* ui() const;
  void setUi(Ui::MainWindow* ui);

  void recoverLastCrash();

private slots:
  void onAutoSave();

private:
  Document* m_document = nullptr;
  Ui::MainWindow* m_ui = nullptr;
  QTimer* m_timer = nullptr;

private:
  explicit Application(QObject* parent = nullptr);
  virtual ~Application();
};

#endif // APPLICATION_H

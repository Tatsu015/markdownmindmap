#ifndef APPLICATION_H
#define APPLICATION_H

class Document;
namespace Ui {
class MainWindow;
}

class Application {
public:
  static Application* getInstance();
  void setUp();
  void tearDown();

  Document* document() const;
  void setDocument(Document* document);

  Ui::MainWindow* ui() const;
  void setUi(Ui::MainWindow* ui);

private:
  Document* m_document = nullptr;
  Ui::MainWindow* m_ui = nullptr;

private:
  Application();
  ~Application();
};

#endif // APPLICATION_H

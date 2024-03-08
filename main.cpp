#include <QApplication>
#include <memory>
#include "mainwindow.h"
#include "statusbar.h"
#include "menubar.h"
#include "fileslayout.h"
#include "filessettingslayout.h"

#define APP_VERSION "v1.0.1"

int main(int argc, char *argv[]) {
    QCoreApplication::setApplicationVersion(APP_VERSION);
    QApplication a(argc, argv);
    MainWindow window;

    std::unique_ptr<StatusBar> statusbar = std::make_unique<StatusBar>(nullptr, APP_VERSION);
    window.setStatusBar(statusbar.get());
    std::unique_ptr<FilesLayout> filesLayout = std::make_unique<FilesLayout>(&window);
    std::unique_ptr<FilesSettingsLayout> filesSettingsLayout = std::make_unique<FilesSettingsLayout>(&window);

    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(filesLayout.get());

    QFrame *line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    verticalLayout->addWidget(line);
    verticalLayout->addWidget(filesSettingsLayout.get());

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(verticalLayout);
    window.setCentralWidget(centralWidget);

    std::unique_ptr<MenuBar> menubar = std::make_unique<MenuBar>(nullptr);
    window.setMenuBar(menubar.get());

    window.show();

    return a.exec();
}

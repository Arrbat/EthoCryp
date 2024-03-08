#include "menubar.h"
#include <QCoreApplication>

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
    QAction *addFileAction = new QAction("Add", this);
    connect(addFileAction, &QAction::triggered, this, &MenuBar::addFile);

    QAction *preferencesAction = new QAction("Preferences", this);
    connect(preferencesAction, &QAction::triggered, this, &MenuBar::showPreferences);

    QAction *exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, this, &MenuBar::exitApp);

    QMenu *actionsMenu = new QMenu("Actions", this);
    actionsMenu->addAction(addFileAction);
    actionsMenu->addAction(preferencesAction);
    actionsMenu->addSeparator();
    actionsMenu->addAction(exitAction);
    addMenu(actionsMenu);
}


void MenuBar::addFile()
{

}

void MenuBar::showPreferences()
{

}

void MenuBar::exitApp()
{
    QCoreApplication::exit(0);
}


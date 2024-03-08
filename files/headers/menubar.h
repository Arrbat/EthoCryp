#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = nullptr);

public slots:
    void addFile();
    void showPreferences();
    void exitApp();
};

#endif // MENUBAR_H

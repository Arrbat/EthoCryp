#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QLabel>

class StatusBar : public QStatusBar {
    Q_OBJECT

public:
    StatusBar(QWidget *parent = nullptr, const QString &version = "");
};

#endif // STATUSBAR_H

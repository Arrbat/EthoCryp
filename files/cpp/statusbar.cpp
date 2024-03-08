#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent, const QString &version) : QStatusBar(parent) {
    QLabel *versionLabel = new QLabel(version);
    addPermanentWidget(versionLabel);
}

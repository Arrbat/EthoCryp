#include "filessettingslayout.h"
#include <QPalette>

FilesSettingsLayout::FilesSettingsLayout(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(5, 5, 5, 5);
    mainLayout->setSpacing(5);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::gray);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    setLayout(mainLayout);
}

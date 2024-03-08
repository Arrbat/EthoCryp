#ifndef FILESSETTINGSLAYOUT_H
#define FILESSETTINGSLAYOUT_H

#include <QWidget>
#include <QHBoxLayout>

class FilesSettingsLayout : public QWidget {
    Q_OBJECT

public:
    explicit FilesSettingsLayout(QWidget *parent = nullptr);

private:
    QHBoxLayout *mainLayout;
};

#endif // FILESSETTINGSLAYOUT_H

#ifndef FILESLAYOUT_H
#define FILESLAYOUT_H

#include <QWidget>
#include <QHBoxLayout>

class FilesLayout : public QWidget {
    Q_OBJECT

public:
    explicit FilesLayout(QWidget *parent = nullptr);

private:
    QHBoxLayout *mainLayout;
};

#endif // FILESLAYOUT_H

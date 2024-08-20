#ifndef SETDIALOG_H
#define SETDIALOG_H
#include "racinggame.h"
#include <QDialog>

namespace Ui {
class SetDialog;
}

class SetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetDialog(QWidget *parent = nullptr);
    ~SetDialog();

private slots:
    void on_commandLinkButton_clicked();
    void on_numCombo_currentIndexChanged(int index);

private:
    Ui::SetDialog *ui;
    RacingGame * racingGame;
};

#endif // SETDIALOG_H

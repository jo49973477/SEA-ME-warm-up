#include <QMessageBox>
#include "setdialog.h"
#include "ui_setdialog.h"
#include "QLineEdit"

SetDialog::SetDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetDialog)
{
    ui->setupUi(this);
}

SetDialog::~SetDialog()
{
    delete ui;
}

void SetDialog::on_numCombo_currentIndexChanged(int num_car) //hide and show
{
    for (int i = 0; i < 3; i++){
        if(i <= num_car){
            for (int j = 0; j < 4; j++){
                ui->inputLayout->itemAtPosition(i, j)->widget()->show();
            }
        }
        else{
            for (int j = 0; j < 4; j++){
                ui->inputLayout->itemAtPosition(i, j)->widget()->hide();
            }
        }
    }
}

void SetDialog::on_commandLinkButton_clicked()
{  //there is a tracks!
    Track track1 = Track({Position(50, 300)}, Position(750, 300));
    Track track2 = Track({Position(50, 100), Position(50, 500), Position(750, 500)}, Position(750, 200));
    Track track3 = Track({Position(50, 100), Position(50, 500), Position(750, 500), Position(750,100),
                          Position(200, 100),Position(200, 400), Position(650, 400)}, Position(650, 250));
    Track candidates[3] = {track1, track2, track3};

    //getting a track
    int track_num = ui->trackCombo->currentIndex();
    Track track = candidates[track_num];

    //getting a car from textfield
    int car_num = ui->numCombo->currentIndex() +1;
    QList<Car> cars;
    for (int i = 0; i < car_num; i++){
        QWidget * basePtr = ui->inputLayout->itemAtPosition(i, 1)->widget();
        QLineEdit *nameInput = dynamic_cast<QLineEdit*>(basePtr);
        QString name = nameInput->text();

        QWidget * basePtr2 = ui->inputLayout->itemAtPosition(i, 3)->widget();
        QLineEdit *speedInput = dynamic_cast<QLineEdit*>(basePtr2);
        bool isNumber;
        int speed = speedInput->text().toInt(&isNumber);
        if (!isNumber){
            QMessageBox::warning(nullptr, "Warning", "The speed of the car must be a number.");
            return;
        }
        cars.append(Car(name, track[0], speed, track.dir(0)));
    }

    //into the racinggame window
    hide();
    racingGame = new RacingGame(cars, track);
    racingGame -> show();
}

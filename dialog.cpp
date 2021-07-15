#include "dialog.h"
#include "ui_dialog.h"
enum CALIBRATIONMODE{
    SIMULATION,
    APPLICATION
};

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    initUi();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initUi()
{
    ui->frame_mainFrame->raise();
    ui->radioButton_simulationMode->setChecked(true);
}

int Dialog::checkMode()
{
    if(ui->radioButton_simulationMode->isChecked())
        return CALIBRATIONMODE::SIMULATION;
    else if(ui->radioButton_applicationMode->isChecked())
        return CALIBRATIONMODE::APPLICATION;
    else
        return -1;
}


void Dialog::on_pushButton_kinematicParameters_clicked()
{
    if(checkMode() == CALIBRATIONMODE::SIMULATION)
        ui->frame_simulationKinematicParameters->raise();
    else if(checkMode() == CALIBRATIONMODE::APPLICATION)
        ui->frame_kinematicParameters->raise();
}

void Dialog::on_pushButton_optimizationSettings_clicked()
{
    ui->frame_optimizationSettings->raise();
}

void Dialog::on_pushButton_measurements_clicked()
{
    if(checkMode() == CALIBRATIONMODE::SIMULATION)
        ui->frame_loadSimulationMeasurements->raise();
    else if(checkMode() == CALIBRATIONMODE::APPLICATION)
        ui->frame_loadApplicationMeasurements->raise();
}

void Dialog::on_pushButton_startCalibration_clicked()
{

}

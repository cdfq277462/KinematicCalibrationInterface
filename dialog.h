#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void initUi();

    int checkMode();

    void on_pushButton_kinematicParameters_clicked();

    void on_pushButton_optimizationSettings_clicked();

    void on_pushButton_measurements_clicked();

    void on_pushButton_startCalibration_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H

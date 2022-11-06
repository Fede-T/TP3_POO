#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

config Dialog::on_buttonBox_accepted()
{
    config configuraciones;

    if(this->ui->recomendado->isChecked()){
        configuraciones.n = 10;
        configuraciones.cantc = 1;
        configuraciones.cantd = 1;
        configuraciones.cantl = 1;
        configuraciones.cantp = 1;
        configuraciones.cants = 1;
    }else if(this->ui->personalizado->isChecked()){
        QString a;
        a = this->ui->dimensiones->text();
        configuraciones.n = a.toInt();

        a = this->ui->portaaviones->text();
        configuraciones.cantp = a.toInt();

        a = this->ui->destructores->text();
        configuraciones.cantd = a.toInt();

        a = this->ui->cruceros->text();
        configuraciones.cantc = a.toInt();


        a = this->ui->submarinos->text();
        configuraciones.cants = a.toInt();

        a = this->ui->lanchas->text();
        configuraciones.cantl = a.toInt();
    }else{
        configuraciones.n = 10;
        configuraciones.cantc = 1;
        configuraciones.cantd = 1;
        configuraciones.cantl = 1;
        configuraciones.cantp = 1;
        configuraciones.cants = 1;
    }

    return configuraciones;
}


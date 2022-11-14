#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

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

void Dialog::on_buttonBox_accepted()
{
    config configuraciones;
    bool resp = this->ui->modo2jugadores->isChecked();
    if(resp){
        configuraciones.vsIA = false;
        qDebug()<<"se juega vs ia";
    }else{
        configuraciones.vsIA = true;
        qDebug()<<"se juega vs player";
    }

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
        if(this->ui->dimensiones->text().isEmpty())
            configuraciones.n = 10;
        else
        configuraciones.n = a.toInt();

        a = this->ui->portaaviones->text();
        if(this->ui->portaaviones->text().isEmpty())
            configuraciones.cantp = 0;
        else
        configuraciones.cantp = a.toInt();

        a = this->ui->destructores->text();
        if(this->ui->destructores->text().isEmpty())
            configuraciones.cantd = 0;
        else
        configuraciones.cantd = a.toInt();

        a = this->ui->cruceros->text();
        if(this->ui->cruceros->text().isEmpty())
            configuraciones.cantc = 0;
        else
        configuraciones.cantc = a.toInt();


        a = this->ui->submarinos->text();
        if(this->ui->submarinos->text().isEmpty())
            configuraciones.cants = 0;
        else
        configuraciones.cants = a.toInt();

        a = this->ui->lanchas->text();
        if(this->ui->lanchas->text().isEmpty())
            configuraciones.cantl = 0;
        else
        configuraciones.cantl = a.toInt();
    }else{
        configuraciones.n = 10;
        configuraciones.cantc = 1;
        configuraciones.cantd = 1;
        configuraciones.cantl = 1;
        configuraciones.cantp = 1;
        configuraciones.cants = 1;
    }

    MainWindow* mw = dynamic_cast<MainWindow*>(this->parent());
    mw->inicializarJuego(configuraciones);


}


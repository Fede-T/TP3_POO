/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *parte_superior;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLabel *turno_de;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QHBoxLayout *tablerosLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *radarVisual;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *oceanoVisual;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *parte_inferior;
    QLabel *instruccionesLabel;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *terminarTurno;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 562);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setWindowFilePath(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("/*#centralwidget{\n"
"	background-image: url(:/fondo.jpg);\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        parte_superior = new QHBoxLayout();
        parte_superior->setObjectName(QString::fromUtf8("parte_superior"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        parte_superior->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Ignored, QSizePolicy::Minimum);

        parte_superior->addItem(horizontalSpacer_4);

        turno_de = new QLabel(centralwidget);
        turno_de->setObjectName(QString::fromUtf8("turno_de"));
        turno_de->setFont(font);
        turno_de->setAlignment(Qt::AlignCenter);

        parte_superior->addWidget(turno_de);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Ignored, QSizePolicy::Minimum);

        parte_superior->addItem(horizontalSpacer_5);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        parte_superior->addWidget(label_3);

        parte_superior->setStretch(0, 5);
        parte_superior->setStretch(1, 1);
        parte_superior->setStretch(2, 4);
        parte_superior->setStretch(3, 1);
        parte_superior->setStretch(4, 5);

        verticalLayout->addLayout(parte_superior);

        tablerosLayout = new QHBoxLayout();
        tablerosLayout->setObjectName(QString::fromUtf8("tablerosLayout"));
        tablerosLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tablerosLayout->addItem(horizontalSpacer);

        radarVisual = new QGridLayout();
        radarVisual->setSpacing(1);
        radarVisual->setObjectName(QString::fromUtf8("radarVisual"));
        radarVisual->setSizeConstraint(QLayout::SetDefaultConstraint);

        tablerosLayout->addLayout(radarVisual);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tablerosLayout->addItem(horizontalSpacer_2);

        oceanoVisual = new QGridLayout();
        oceanoVisual->setSpacing(1);
        oceanoVisual->setObjectName(QString::fromUtf8("oceanoVisual"));
        oceanoVisual->setSizeConstraint(QLayout::SetDefaultConstraint);

        tablerosLayout->addLayout(oceanoVisual);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tablerosLayout->addItem(horizontalSpacer_3);

        tablerosLayout->setStretch(0, 1);
        tablerosLayout->setStretch(1, 15);
        tablerosLayout->setStretch(2, 1);
        tablerosLayout->setStretch(3, 15);
        tablerosLayout->setStretch(4, 1);

        verticalLayout->addLayout(tablerosLayout);

        parte_inferior = new QHBoxLayout();
        parte_inferior->setObjectName(QString::fromUtf8("parte_inferior"));
        parte_inferior->setSizeConstraint(QLayout::SetNoConstraint);
        parte_inferior->setContentsMargins(-1, 2, -1, 2);
        instruccionesLabel = new QLabel(centralwidget);
        instruccionesLabel->setObjectName(QString::fromUtf8("instruccionesLabel"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(10);
        instruccionesLabel->setFont(font1);
        instruccionesLabel->setAlignment(Qt::AlignCenter);

        parte_inferior->addWidget(instruccionesLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        parte_inferior->addItem(horizontalSpacer_6);

        terminarTurno = new QPushButton(centralwidget);
        terminarTurno->setObjectName(QString::fromUtf8("terminarTurno"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(terminarTurno->sizePolicy().hasHeightForWidth());
        terminarTurno->setSizePolicy(sizePolicy);
        terminarTurno->setBaseSize(QSize(11, 8));

        parte_inferior->addWidget(terminarTurno);

        parte_inferior->setStretch(0, 5);
        parte_inferior->setStretch(1, 2);
        parte_inferior->setStretch(2, 1);

        verticalLayout->addLayout(parte_inferior);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);
        verticalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Radar", nullptr));
        turno_de->setText(QCoreApplication::translate("MainWindow", "Turno de jugador: 0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Oceano", nullptr));
        instruccionesLabel->setText(QCoreApplication::translate("MainWindow", "Clickee en el radar para realizar un disparo", nullptr));
        terminarTurno->setText(QCoreApplication::translate("MainWindow", "Terminar Turno", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

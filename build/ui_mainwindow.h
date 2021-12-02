/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quit;
    QAction *action_About;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *label_2;
    QComboBox *stopBits;
    QComboBox *dataBits;
    QLabel *label_5;
    QComboBox *baud;
    QLabel *label_3;
    QComboBox *serialPort;
    QLabel *label_4;
    QComboBox *parity;
    QLabel *label;
    QCheckBox *checkBox;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClearRawData;
    QPlainTextEdit *plainTextEdit;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnClearCmdData;
    QTableWidget *busMonTable;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_About;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/sniffer.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 100));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(142, 6, 123, 48));
        stopBits = new QComboBox(widget);
        stopBits->addItem(QString());
        stopBits->addItem(QString());
        stopBits->addItem(QString());
        stopBits->setObjectName(QString::fromUtf8("stopBits"));
        stopBits->setGeometry(QRect(401, 60, 123, 24));
        dataBits = new QComboBox(widget);
        dataBits->addItem(QString());
        dataBits->addItem(QString());
        dataBits->setObjectName(QString::fromUtf8("dataBits"));
        dataBits->setGeometry(QRect(271, 60, 124, 24));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(530, 6, 123, 48));
        baud = new QComboBox(widget);
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->addItem(QString());
        baud->setObjectName(QString::fromUtf8("baud"));
        baud->setGeometry(QRect(142, 60, 123, 24));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(271, 6, 124, 48));
        serialPort = new QComboBox(widget);
        serialPort->setObjectName(QString::fromUtf8("serialPort"));
        serialPort->setGeometry(QRect(13, 60, 123, 24));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(401, 6, 123, 48));
        parity = new QComboBox(widget);
        parity->addItem(QString());
        parity->addItem(QString());
        parity->addItem(QString());
        parity->setObjectName(QString::fromUtf8("parity"));
        parity->setGeometry(QRect(530, 60, 123, 24));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(13, 6, 123, 48));
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(680, 60, 83, 22));

        verticalLayout->addWidget(widget);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnClearRawData = new QPushButton(centralwidget);
        btnClearRawData->setObjectName(QString::fromUtf8("btnClearRawData"));
        btnClearRawData->setMinimumSize(QSize(140, 0));

        horizontalLayout->addWidget(btnClearRawData);


        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnClearCmdData = new QPushButton(centralwidget);
        btnClearCmdData->setObjectName(QString::fromUtf8("btnClearCmdData"));
        btnClearCmdData->setMinimumSize(QSize(140, 0));

        horizontalLayout_2->addWidget(btnClearCmdData);


        verticalLayout->addLayout(horizontalLayout_2);

        busMonTable = new QTableWidget(centralwidget);
        if (busMonTable->columnCount() < 5)
            busMonTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        busMonTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        busMonTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        busMonTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        busMonTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        busMonTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        busMonTable->setObjectName(QString::fromUtf8("busMonTable"));

        verticalLayout->addWidget(busMonTable);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_About = new QMenu(menubar);
        menu_About->setObjectName(QString::fromUtf8("menu_About"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_About->menuAction());
        menu_File->addAction(action_Quit);
        menu_About->addAction(action_About);

        retranslateUi(MainWindow);
        QObject::connect(btnClearRawData, SIGNAL(clicked()), plainTextEdit, SLOT(clear()));
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        dataBits->setCurrentIndex(1);
        baud->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Quit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        action_About->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Baud", nullptr));
        stopBits->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        stopBits->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        stopBits->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        dataBits->setItemText(0, QCoreApplication::translate("MainWindow", "7", nullptr));
        dataBits->setItemText(1, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Parity", nullptr));
        baud->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        baud->setItemText(1, QCoreApplication::translate("MainWindow", "4800", nullptr));
        baud->setItemText(2, QCoreApplication::translate("MainWindow", "9600", nullptr));
        baud->setItemText(3, QCoreApplication::translate("MainWindow", "19200", nullptr));
        baud->setItemText(4, QCoreApplication::translate("MainWindow", "38400", nullptr));
        baud->setItemText(5, QCoreApplication::translate("MainWindow", "57600", nullptr));
        baud->setItemText(6, QCoreApplication::translate("MainWindow", "115200", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Data bits", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Stop bits", nullptr));
        parity->setItemText(0, QCoreApplication::translate("MainWindow", "none", nullptr));
        parity->setItemText(1, QCoreApplication::translate("MainWindow", "odd", nullptr));
        parity->setItemText(2, QCoreApplication::translate("MainWindow", "even", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Serial port", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Active", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Raw data:", nullptr));
        btnClearRawData->setText(QCoreApplication::translate("MainWindow", "Clear Raw Data", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Commands:", nullptr));
        btnClearCmdData->setText(QCoreApplication::translate("MainWindow", "Clear Commands Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem = busMonTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Slave ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = busMonTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Cmd", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = busMonTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = busMonTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = busMonTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menu_About->setTitle(QCoreApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

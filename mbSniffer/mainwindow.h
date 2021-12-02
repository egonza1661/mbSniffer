#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <qextserialport.h>

class MB_Data;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QextSerialPort *port;

    BaudRateType getBaudRate();
    ParityType getParity();
    DataBitsType getDataBits();
    StopBitsType getStopBits();

    bool eventFilter(QObject *f_object, QEvent *f_event);

    void busMonitorAddItem(const MB_Data &mbData);
    QString getCmdDescrition(const unsigned char &funcCode);
    QString getErrorDescription(const unsigned char &funcCode);

private slots:
    void onReadyRead();
    void onDsrChanged(bool status);
    void onPortSettingsChange();
    void onStartListening();
    void onActivatePort();
    void on_btnClearCmdData_clicked();
    void on_action_About_triggered();
};
#endif // MAINWINDOW_H

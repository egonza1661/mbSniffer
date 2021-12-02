#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <qextserialport.h>

class MB_Data;
/****************************************************************************
** Copyright (c) 2021 Eduardo Adrián González
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/

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

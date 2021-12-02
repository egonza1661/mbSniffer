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

#include "crc16.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QTableWidget>

#include <aboutdialog.h>
#include <qextserialenumerator.h>
#include <qextserialport.h>



/* Modbus function codes */
#define MODBUS_FC_READ_COILS                0x01
#define MODBUS_FC_READ_DISCRETE_INPUTS      0x02
#define MODBUS_FC_READ_HOLDING_REGISTERS    0x03
#define MODBUS_FC_READ_INPUT_REGISTERS      0x04
#define MODBUS_FC_WRITE_SINGLE_COIL         0x05
#define MODBUS_FC_WRITE_SINGLE_REGISTER     0x06
#define MODBUS_FC_READ_EXCEPTION_STATUS     0x07
#define MODBUS_FC_READ_DIAGNOSTICS          0x08
#define MODBUS_FC_GET_COMM_EVENT_COUTER     0x0B
#define MODBUS_FC_GET_COMM_EVENT_LOG        0x0C
#define MODBUS_FC_WRITE_MULTIPLE_COILS      0x0F
#define MODBUS_FC_WRITE_MULTIPLE_REGISTERS  0x10
#define MODBUS_FC_REPORT_SLAVE_ID           0x11
#define MODBUS_FC_READ_FILE_RECORD          0x14
#define MODBUS_FC_WRITE_FILE_RECORD         0x15
#define MODBUS_FC_MASK_WRITE_REGISTER       0x16
#define MODBUS_FC_WRITE_AND_READ_REGISTERS  0x17
#define MODBUS_FC_READ_FIFO_QUEUE           0x18
#define MODBUS_FC_READ_DEVICE_ID            0x2B

#define MODBUS_EC_ILEGAL_FUNCTION           0x01
#define MODBUS_EC_ILLEGAL_DATA_ADDRESS      0x02
#define MODBUS_EC_ILLEGAL_DATA_VALUE        0x03
#define MODBUS_EC_SERVER_DEVICE_FAILURE     0x04
#define MODBUS_EC_ACKNOWLEDGE               0x05
#define MODBUS_EC_SERVER_DEVICE_BUSY        0x06
#define MODBUS_EC_MEMORY_PARITY_ERROR       0x08

class MB_Data {
public:
    QString slaveID;
    QString cmd;
    QString data;
    QString status;
    QString descrition;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , port(nullptr)
{
    ui->setupUi(this);

    setWindowTitle("MODBUS Sniffer");


    foreach(const QextPortInfo &info ,QextSerialEnumerator::getPorts()){
        ui->serialPort->addItem(info.physName);
    }
    ui->checkBox->setChecked(false);
    connect(ui->serialPort, &QComboBox::currentTextChanged, this, &MainWindow::onPortSettingsChange);
    connect(ui->baud, &QComboBox::currentTextChanged, this, &MainWindow::onPortSettingsChange);
    connect(ui->dataBits, &QComboBox::currentTextChanged, this, &MainWindow::onPortSettingsChange);
    connect(ui->parity, &QComboBox::currentTextChanged, this, &MainWindow::onPortSettingsChange);
    connect(ui->stopBits, &QComboBox::currentTextChanged, this, &MainWindow::onPortSettingsChange);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::onActivatePort);

    onPortSettingsChange();

    ui->busMonTable->horizontalHeader()->setStretchLastSection(true);

}
MainWindow::~MainWindow()
{
    if(port){
        port->close();
        delete port;
    }
    delete ui;
}

BaudRateType MainWindow::getBaudRate()
{
    switch (ui->baud->currentIndex()) {
    case 0:
        return BAUD1200;
    case 1:
        return BAUD4800;
    case 2:
        return BAUD9600;
    case 3:
        return BAUD19200;
    case 4:
        return BAUD38400;
    case 5:
        return BAUD57600;
    case 6:
        return BAUD115200;
    }
    return BAUD9600;
}

ParityType MainWindow::getParity()
{
    switch (ui->parity->currentIndex()) {
    case 1:
        return PAR_ODD;
    case 2:
        return PAR_EVEN;
    }
    return PAR_NONE;
}

DataBitsType MainWindow::getDataBits()
{
    switch (ui->dataBits->currentIndex()) {
    case 0:
        return DATA_7;
    }
    return DATA_8;
}

StopBitsType MainWindow::getStopBits()
{
    switch (ui->stopBits->currentIndex()) {
    case 1:
        return STOP_1_5;
    case 2:
        return STOP_2;
    }
    return STOP_1;
}

bool MainWindow::eventFilter(QObject *f_object, QEvent *f_event)
{
    if(f_object == ui->serialPort){
        if(f_event->type() == QEvent::MouseButtonPress){
            QString curr = ui->serialPort->currentText();
            ui->serialPort->clear();
            foreach(const QextPortInfo &info ,QextSerialEnumerator::getPorts()){
                ui->serialPort->addItem(info.portName);
            }
            ui->serialPort->setCurrentText(curr);
        }
        return false;
    }
    return false;

}

void MainWindow::busMonitorAddItem(const MB_Data &mbData)
{
    QTableWidget * bm = ui->busMonTable;
    const int rowCount = bm->rowCount();
    bm->setRowCount( rowCount+1 );

    QTableWidgetItem * slaveItem = new QTableWidgetItem(mbData.slaveID);
    QTableWidgetItem * funcItem = new QTableWidgetItem(mbData.cmd);
    QTableWidgetItem * dataItem = new QTableWidgetItem(mbData.data);
    QTableWidgetItem * statusItem = new QTableWidgetItem(mbData.status);
    QTableWidgetItem * descItem = new QTableWidgetItem(mbData.descrition);

    slaveItem->setFlags( slaveItem->flags() & ~Qt::ItemIsEditable );
    funcItem->setFlags( funcItem->flags() & ~Qt::ItemIsEditable );
    dataItem->setFlags( dataItem->flags() & ~Qt::ItemIsEditable );
    statusItem->setFlags( statusItem->flags() & ~Qt::ItemIsEditable );
    descItem->setFlags( descItem->flags() & ~Qt::ItemIsEditable );

    bm->setItem( rowCount, 0, slaveItem );
    bm->setItem( rowCount, 1, funcItem );
    bm->setItem( rowCount, 2, dataItem );
    bm->setItem( rowCount, 3, statusItem );
    bm->setItem( rowCount, 4, descItem );

    bm->resizeColumnsToContents();

}


QString MainWindow::getCmdDescrition(const unsigned char &funcCode)
{
    switch( funcCode )
    {
    case MODBUS_FC_READ_COILS:
        return "Read coil";
    case MODBUS_FC_READ_DISCRETE_INPUTS:
        return "Read discrete inputs";
    case MODBUS_FC_READ_HOLDING_REGISTERS:
        return "Read holding register";
    case MODBUS_FC_READ_INPUT_REGISTERS:
        return "Read input register";
    case MODBUS_FC_WRITE_SINGLE_COIL:
        return "Write single coil";
    case MODBUS_FC_WRITE_SINGLE_REGISTER:
        return "Write single register";
    case MODBUS_FC_READ_EXCEPTION_STATUS:
        return "Read exception status";
    case MODBUS_FC_READ_DIAGNOSTICS:
        return "Read diagnostics";
    case MODBUS_FC_GET_COMM_EVENT_COUTER:
        return "Get communication's event counter";
    case MODBUS_FC_GET_COMM_EVENT_LOG:
        return "Get communication's event log";
    case MODBUS_FC_WRITE_MULTIPLE_COILS:
        return "Write multiple coils";
    case MODBUS_FC_WRITE_MULTIPLE_REGISTERS:
        return "Write multiple registers";
    case MODBUS_FC_REPORT_SLAVE_ID:
        return "Report slave ID";
    case MODBUS_FC_READ_FILE_RECORD:
        return "Read file record";
    case MODBUS_FC_WRITE_FILE_RECORD:
        return "Write file record";
    case MODBUS_FC_MASK_WRITE_REGISTER:
        return "Mask write register";
    case MODBUS_FC_WRITE_AND_READ_REGISTERS:
        return "Read write multiple registers";
    case MODBUS_FC_READ_FIFO_QUEUE:
        return "Read fifo queue";
    case MODBUS_FC_READ_DEVICE_ID:
        return "Read device ID";
    default:
        break;
    }
    return "Unknown";

}

QString MainWindow::getErrorDescription(const unsigned char &funcCode)
{
    switch( funcCode )
    {
    case MODBUS_EC_ILEGAL_FUNCTION:
        return " (Ilegal function)";
    case MODBUS_EC_ILLEGAL_DATA_ADDRESS:
        return " (Ilegal data address)";
    case MODBUS_EC_ILLEGAL_DATA_VALUE:
        return " (Ilegal data value)";
    case MODBUS_EC_SERVER_DEVICE_FAILURE:
        return " (Server error)";
    case MODBUS_EC_ACKNOWLEDGE:
        return " (Request takes too long to process)";
    case MODBUS_EC_SERVER_DEVICE_BUSY :
        return " (Server busy)";
    case MODBUS_EC_MEMORY_PARITY_ERROR:
        return " (Server memory error)";
    default:
        break;
    }
    return " Unknown";
}

void MainWindow::onReadyRead()
{
    MB_Data mbData;
    QByteArray bytes;
    int a = port->bytesAvailable();
    bytes.resize(a);
    port->read(bytes.data(), bytes.size());

    QDataStream ds(&bytes, QIODevice::ReadOnly);
    ds.setByteOrder(QDataStream::LittleEndian);

    unsigned char c;
    ds >> c;
    mbData.slaveID = QString().asprintf("%.2x", c&0xFF);
    ds >> c;
    mbData.cmd = QString().asprintf("%.2x", c&0xFF);

    bool error = c&0x80;
    if(error){
        mbData.descrition = getCmdDescrition(c&0x7F);
        mbData.descrition.prepend("ERROR: ");
    }
    else
        mbData.descrition = getCmdDescrition(c);

    for(int i=2; i<bytes.size()-2; i++){
        ds >> c;
        if(error){
            mbData.descrition.append(getErrorDescription(c));
            error = false;
        }
        mbData.data.append(QString().asprintf("%.2x ", c&0xFF));
    }
    unsigned short readCrc;
    ds >> readCrc;

    unsigned short crc = CRC16::CalculateCRC16((unsigned char*)bytes.constData(), bytes.size()-2);


    QString s;
    s.append(mbData.slaveID).append(' ');
    s.append(mbData.cmd).append(' ');
    s.append(mbData.data);

    if(readCrc == crc){
        mbData.status = "OK";
        s.append( " OK");
    }
    else{
        mbData.status = "ERROR";
        s.append(" ERROR");
    }
    ui->plainTextEdit->appendPlainText(s);
    busMonitorAddItem(mbData);
}

void MainWindow::onDsrChanged(bool status)
{
    if (status)
        ui->statusbar->showMessage("device was turned on");
    else
        ui->statusbar->showMessage("device was turned off");
}

void MainWindow::onPortSettingsChange()
{
    ui->checkBox->setChecked(false);
    if(port)
        port->close();
}

void MainWindow::onStartListening()
{
}

void MainWindow::onActivatePort()
{
    if(port){
        port->close();
        delete port;
    }
    port = new QextSerialPort(ui->serialPort->currentText(), QextSerialPort::EventDriven);
    port->setBaudRate(getBaudRate());
    port->setFlowControl(FLOW_OFF);
    port->setParity(getParity());
    port->setDataBits(getDataBits());
    port->setStopBits(getStopBits());
    if (port->open(QIODevice::ReadWrite) == true) {
        connect(port, &QIODevice::readyRead, this, &MainWindow::onReadyRead);
        connect(port, &QextSerialPort::dsrChanged, this, &MainWindow::onDsrChanged);
        //        if (!(port->lineStatus() & LS_DSR))
        //            QMessageBox::warning(this, "Atention", "warning: device is not turned on");
        ui->statusbar->showMessage(QString("Listening for data on ").append(port->portName()));
    }
    else {
        QString msg = QString("Device failed to open: ").append(port->errorString());
        ui->statusbar->showMessage(msg);
        QMessageBox::critical(this, "Error", msg);
        ui->checkBox->setChecked(false);
    }
}


void MainWindow::on_btnClearCmdData_clicked()
{
    //ui->busMonTable->clearContents();
    ui->busMonTable->setRowCount(0);
}


void MainWindow::on_action_About_triggered()
{
    (new AboutDialog(this))->exec();
}


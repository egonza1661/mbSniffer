#ifndef CRC16_H
#define CRC16_H



class QByteArray;
class CRC16
{
public:
    static unsigned short CalculateCRC16 (const unsigned char *nData, unsigned short wLength);
    QByteArray makeRTUFrame(int slave, int function, const QByteArray & data);
};

#endif // CRC16_H

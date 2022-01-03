#ifndef CRC16_H
#define CRC16_H


namespace Ui {
class crc16;
}

class crc16
{
public:
    static unsigned short int usMBCRC16  ( char * pucFrame, int usLen );
   // static char16_t usMBCRC16_2(char * pucFrame, int usLen );
};

#endif // CRC16_H

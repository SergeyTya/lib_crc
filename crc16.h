#ifndef CRC16_H
#define CRC16_H

#include "cstdint"
#include "vector"
namespace Ui {
class crc16;
}

class crc16
{
public:
    static unsigned short int usMBCRC16  ( unsigned char * pucFrame, int usLen );
    static unsigned short int usMBCRC16  ( std::vector<uint8_t>& v);
    static bool checkCRC(uint8_t * resp,unsigned int len);
    static bool checkCRC(std::vector<uint8_t>& v);
   // static char16_t usMBCRC16_2(char * pucFrame, int usLen );
};

#endif // CRC16_H

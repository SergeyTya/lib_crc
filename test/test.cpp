
#include <gtest/gtest.h>
#include "crc16.h"

TEST(hexImage, record_check_true) {

    // Arrange
    char buf[] = { 1, 0x2b, 0xe, 0x1, 0x1, 0, 0 };
    crc16::usMBCRC16(buf, 5);
    // Act (empty for this test)
   bool res = crc16::checkCRC(buf, sizeof buf);
    // Assert
    ASSERT_TRUE(res);
}

TEST(hexImage, record_check_false_hi) {

    // Arrange
    char buf[] = { 1, 0x2b, 0xe, 0x1, 0x1, 0, 0 };
    crc16::usMBCRC16(buf, 5);
    buf[6] =0;
    // Act (empty for this test)
    bool res = crc16::checkCRC(buf, sizeof buf);
    // Assert
    ASSERT_FALSE(res);
}


TEST(hexImage, record_check_false_lo) {

    // Arrange
    char buf[] = { 1, 0x2b, 0xe, 0x1, 0x1, 0, 0 };
    crc16::usMBCRC16(buf, 5);
    buf[5] =0;
    // Act (empty for this test)
    bool res = crc16::checkCRC(buf, sizeof buf);
    // Assert
    ASSERT_FALSE(res);
}

TEST(hexImage, record_check_zero_size) {

    // Arrange
    char buf[] = { 1, 0x2b, 0xe, 0x1, 0x1, 0, 0 };
    crc16::usMBCRC16(buf, 5);
    buf[5] =0;
    // Act (empty for this test)
    bool res = crc16::checkCRC(buf, 0); // len is 0
    // Assert
    ASSERT_FALSE(res);
}

TEST(hexImage, record_check_min_size) {

    // Arrange
    char buf[] = { 1, 0x2b, 0xe, 0x1, 0x1, 0, 0 };
    crc16::usMBCRC16(buf, 5);
    buf[5] =0;
    // Act (empty for this test)
    bool res = crc16::checkCRC(buf, 3); // len is 0
    // Assert
    ASSERT_FALSE(res);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

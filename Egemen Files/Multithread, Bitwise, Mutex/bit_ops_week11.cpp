#include <iostream>

using namespace std;

int main()
{
    /*
        * Hexadecimal numbers
        *   - Ranged [0,15]
        *   - a = 10, b = 11, c = 12, d = 13, e = 14, f = 15
        *   - 1 byte is 2 hex digits
        *   
        *   Example:
        *       0xb4a2 = 11x(16**3) + 4x(16**2) + 10x(16) + 2x(16**0) = 46262 in decimal 
    */

    short nums = -200;

    cout << "hexadecimal: " << hex << nums << " decimal: " << dec << nums << endl;

    char ch = 0x7c; //* 12x(16**0) + 7x(16**1) in decimal

    //* When you want to display a numberic output as hexadecimal, you use the following hex before the number within the stream operation.
    //* This affects all future integers outputs so if you want to swtich back to decimal, use dec word in same syntax as above.

    unsigned int numi = 0xfd04e0e4;
    cout << "hexadecimal: " << hex << numi << " decimal: " << dec << numi << endl;


    /*
    !   Bit operators
    *       Bitwise and: &
    *       Bitwise or: |, 2 operand aliyor karsilastirirken bildigin 1 V 0 (1 veya 0) diye dumduz bakiyor sonra sonucu yaziyorsun
    *       Bitwise explusive or: ^
    *       Complement(unary operator, takes only one operand): ~
    *       Shift left: <<
    *       Shift right: >>
    */
    char x, y, z;

    x = 0xd5;
    y = 0x6c;
    z = x&y;
    cout << x << " " << y << " " << z << endl;
    //* z is 68 in decimal. 68 = 4x16 + 4

    unsigned char c1, c2, c3, c4, c5;

    c1 = 0x45; //* 0100 0101
    c2 = 0x71; //* 0111 0001
    c3 = c1&c2;  //* 0100 0001 = 0x41 = 4*16 + 1 = 65(10)
    c4 = c1|c2; //* 0111 0101 = 0x75 = 7*16 + 5 = 117(10)
    c5 = c1 ^ c2; //* 0011 0100 = 0x34 = 3*16 + 4 = 52(10)

    unsigned char b1 = 0xc1; //* 1100 0001
    unsigned char b4; 
    b4 = ~b1; //* 0011 1110
    cout << b4 << endl;  

    //* Shift operators: Discarding bits from one side and filling the other side with 0s ( filling part has an expection that we will see)
    //* Don't confuse bitwise shift operators with stream operators

    unsigned char shift_this = 0x9C; //* 1011100
    unsigned char shifted = c2 << 2; //* 0111000 (shift all bits to the left, with size of 2 bits)

    //! Shifting one bit to left means multiplying the value by 2 in magnitude, doesn't matter if its an integer or not.
    //!     - It may cause overflow.
    //! Shifting left n bits multiplies the number with 2**n.

    /*
        * Shifting To Right
        *   - Right shifting works differently for signed and unsigned numbers.
        *   - For UNSIGNED numbers:
        *       - Drop rightmost k bits and append k zeroes to the left
        *   - For SIGNED numbers:
        *       - Drop rightmost k bits and APPEND THE SIGN BIT K TIMES TO THE LEFT
        * Logical shift right one bit divides by 2 for unsigned and the result is rounded down.
        * Arithmetic shift right one bit divides by 2 for signed numbers and result is rounded down.
    */
    
    //* For positives:
    char c = 8; //* 0000 1000
    c = c >> 2; //* 0000 0010 = 2(10)
    //* For negatives
    char c = -8 //* 1111 1000 in 2s complement
    c = c >> 2; //* 1111 1110 which is -2(10)
    //! This is called arithmetic shifting
    //----------------------------------------------------------------
    //* For unsigned 
    unsigned char d = 0xf8; //* 1111 1000 248(10)
    d = d >> 2; //* 0011 1110 which is 62(10)
    //! This is called logical shift
    
    //! When you need to use only positive numbers or whe you need to manipulate bits, use unsigned numbers.

    return 0;
}
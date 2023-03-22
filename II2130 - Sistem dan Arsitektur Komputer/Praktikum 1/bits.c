#include <stdio.h>

int gura(int x, int y) {
    return ~(~x & ~y);
}

int rushia(void) {
    return 1 << 31;
}

unsigned int kobokan(unsigned int x, unsigned int n) {
    return x & ((1 << n) + ~0);
}

int yamada(int x) {
    return (135 + ~x)>>31 & (x + ~182)>>31 & 1;
}

// 0x12345678
int pekora(int x) {
    int a = (x >> 24) & 255; // 00 00 00 12
    int b = ((x >> 16) & 255) << 8; // 00 00 34 00
    int c = ((x >> 8) & 255) << 16; // 00 56 00 00
    int d = (x & 255) << 24; // 00 00 12 34
    return a | b | c | d;
}

int mumei(int x, int n) {
    return (x >> n) & ~((1 << 31) >> (n + ~0));
}

int fauna(int x, int n) {
    return (x >> (n << 3)) & 255;
}

unsigned int ollie(unsigned int a) {
    int temp, shift;
    a = (a & 31) + ((a >> 5) << 1);
    temp = a + (~30 + 1);
    shift = ~(temp >> 31);
    return a + ((~30 + 1) & shift);
    // z ^ ((y ^ z) & ((!x) + ~0));     // x ? y : z
    // unsigned int neg, shift;
    // neg = a + ~29;
    // shift = neg >> 31;
    // // printf("%d", shift);
    // a = a ^ ((neg ^ a) & ((!!(shift & 1)) + ~0));
    return a;
}

unsigned coco(unsigned uf) {
    unsigned sign = uf >> 31;
    unsigned exp = uf >> 23 & 255;
    unsigned frac = uf & 8388607;

    if (exp == 255) {
        return uf;
    } else if (exp == 0) {
        frac <<= 1;
    } else {
        exp++;
    }
    return (sign << 31) | (exp << 23) | frac;
}

unsigned int reverse(register unsigned int x)
{
	x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
	x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
	x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
	x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
	
    return((x >> 16) | (x << 16));
}

int countLeadingZero(int x)  // 25 ops
{
    /*
     * Speed up from countLeadingZero_36()
     * Idea: ilog2() https://www.viseator.com/2017/06/18/CS_APP_DataLab/,
     * No need to use leading_n_zero as a mask!
     */

    int num_zero = 0;

    // value = 1 if the leading 16 bits are all zero else 0
    int leading_n_zero = !(x >> 16);
    int n = leading_n_zero << 4;  // n = 16 if leading_n_zero is true
    num_zero = n;
    x = x << n;

    // value = 1 if the leading 8 bits are all zero else 0
    leading_n_zero = !(x >> 24);
    n = leading_n_zero << 3;
    num_zero = num_zero + n;
    x = x << n;

    // value = 1 if the leading 4 bits are all zero else 0
    leading_n_zero = !(x >> 28);
    n = leading_n_zero << 2;
    num_zero = num_zero + n;
    x = x << n;

    // value = 1 if the leading 2 bits are all zero else 0
    leading_n_zero = !(x >> 30);
    n = leading_n_zero << 1;
    num_zero = num_zero + n;
    x = x << n;

    int bit_31_is_zero = !(x >> 31);
    num_zero = num_zero + bit_31_is_zero;

    int bit_31_to_30_is_zero = !(x >> 30);
    num_zero = num_zero + bit_31_to_30_is_zero;

    return num_zero;
}


int moona(int x) {
    int y = x & ((~x) + 1);
    int a = 1  ^ (1  & ((!y) + ~0));
    int b = 16 ^ (16 & ((!((y & 0x0000FFFF))) + ~0));
    int c = 8  ^ (8 & ((!((y & 0x00FF00FF))) + ~0));
    int d = 4  ^ (4 & ((!((y & 0x0F0F0F0F))) + ~0));
    int e = 2 ^ (2 & ((!((y & 0X33333333))) + ~0));
    int f = 1 ^ (1 & ((!((y & 0x55555555))) + ~0));
    return a + b + c + d + e + f;
}
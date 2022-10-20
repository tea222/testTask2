#include <iostream>

#define SET_BIT(x, p) x |= 1UL << p
#define CLR_BIT(x, p) x &= ~(1UL << p)
#define TGL_BIT(x, p) x ^= 1UL << p
#define CHK_BIT(x,p) x = (x >> p) & 1U

void Int2BitStr(int x, char* str, int size) {

    str[--size] = '\0';

    while (size){

        size--;
        str[size] = x % 2 == 0 ? '0' : '1';
        
        x /= 2;
    }
}

int main()
{
    int size = 9;
    char* str = new char[size];
    int p = 2;

    int num = 66;
    Int2BitStr(num, str, size);
    printf("before SET_BIT:\ndec: %d bin: %s\n", num, str);
    num = SET_BIT(num, p);
    Int2BitStr(num, str, size);
    printf("after SET_BIT (p = %d):\ndec: %d bin: %s\n\n", p, num, str);

    p = 7;
    num = 228;
    Int2BitStr(num, str, size);
    printf("before CLR_BIT:\ndec: %d bin: %s\n", num, str);
    num = CLR_BIT(num, p);
    Int2BitStr(num, str, size);
    printf("after CLR_BIT (p = %d):\ndec: %d bin: %s\n\n", p, num, str);

    p = 0;
    num = 71;
    Int2BitStr(num, str, size);
    printf("before TGL_BIT:\ndec: %d bin: %s\n", num, str);
    num = TGL_BIT(num, p);
    Int2BitStr(num, str, size);
    printf("after TGL_BIT (p = %d):\ndec: %d bin: %s\n\n", p, num, str);

    p = 4;
    num = 23;
    Int2BitStr(num, str, size);
    printf("CHK_BIT (p = %d):\ndec: %d bin: %s\n", p, num, str);
    int checkBit = CHK_BIT(num, p);
    printf("checkBit: %d\n", checkBit);
}

/*
output:
before SET_BIT:
dec: 66 bin: 01000010
after SET_BIT (p = 2):
dec: 70 bin: 01000110

before CLR_BIT:
dec: 228 bin: 11100100
after CLR_BIT (p = 7):
dec: 100 bin: 01100100

before TGL_BIT:
dec: 71 bin: 01000111
after TGL_BIT (p = 0):
dec: 70 bin: 01000110

CHK_BIT (p = 4):
dec: 23 bin: 00010111
checkBit: 1
*/
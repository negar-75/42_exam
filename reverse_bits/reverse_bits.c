unsigned char	reverse_bits(unsigned char octet)
{
    int i = 0;
    unsigned char result = 0;
    while(i <= 7)
    {
        result |= (octet >> i & (1)) << (7-i);
        i++;
    }
 return result;
}
#include<stdio.h>
int main ()
{
    unsigned char test = 2;
    printf("%u", reverse_bits(test));
    return 0;

}

void print_bits(unsigned char octet) {
    int i = 7;
    while (i >= 0) {
        putchar((octet & (1 << i)) ? '1' : '0');
        i--;
    }
}

unsigned char reverse_bits(unsigned char octet) {
    unsigned char reversed = 0;
    int i = 0;
    while (i < 8) {
        reversed |= ((octet >> i) & 1) << (7 - i);
        i++;
    }
    return reversed;
}

unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
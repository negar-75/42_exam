
#include<stdio.h>

int ft_atoi_base(const char *str, int str_base) {

    int result = 0;
    int sign = 1;
    int i = 0;
    int digit;

    if(str[i] == '-')
    {
        sign *= -1;
        i++;
    }
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
            digit = str[i] - '0';
        else if(str[i] >= 'a'&& str[i] <= 'f')
            digit = str[i] - 'a' + 10;
        else if(str[i] >= 'A'&& str[i] <= 'F')
            digit = str[i] - 'A' + 10;
        else 
            break;
        if(digit > str_base)
            break;
        i++;
        result = result * str_base + digit;
    }
    return (result * sign);
}


int main() {
    // Example usage
    const char *str = "12FDB3";
    int str_base = 5;
    printf("Input string: %s\n", str);
    printf("Base: %d\n", str_base);
    printf("Result: %d\n", ft_atoi_base(str, str_base));
    return 0;
}
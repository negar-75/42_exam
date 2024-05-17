#include<unistd.h>
int	ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}
void put_char(char c)
{
    write(1,&c,1);
}
void print_hex (int num)
{
    int long n = num;
    char* base = "0123456789abcdef";
    if(n >= 16)
    {
        print_hex(n / 16);          
    }
    put_char((base[n % 16]));
}


int main(int argc, char **argv)
{
    if(argc == 2)
    {
        print_hex(ft_atoi(argv[1]));
    }
    put_char('\n');
    return(0);
}
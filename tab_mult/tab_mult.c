#include<unistd.h>
void put_char(char c)
{
    write(1,&c,1);
}
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
void put_nbr(int num)
{
    int long n = num;
    if(n < 0)
    {
        put_char('-');
        n = n * -1;
    }
    if(n >= 10)
    {
        put_nbr(n / 10);             
    }
    put_char((n % 10 )+ '0');
}
 void tab_molt(int num)
 {
    int i = 1;
    while(i <= 9)
    {
        int result = i * num;
        put_char(i  + '0');
        put_char(' ');
        put_char('x');
        put_char(' ');
        put_nbr(num);
        put_char(' ');
        put_char('=');
        put_char(' ');
        put_nbr(result);
        if(i != 9)
            put_char('\n');
        i++;
    }
 }

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        tab_molt(ft_atoi(argv[1]));
    }
    write(1,"\n",1);
    return (0);
}
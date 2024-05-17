#include<unistd.h>
void put_char(char c)
{
    write(1,&c,1);
}
void ft_putnbr(int num)
{
    int long nb = num;
    if(num >= 10)
    {
        ft_putnbr(num / 10);
        put_char((num % 10) + '0');
    }
    else
    {
        put_char(num+ '0');
    }
}

int main(int argc, char **ar)
{
    ar = NULL;
    ft_putnbr(argc -1);
    write(1,"\n",1);
    return 0;
}
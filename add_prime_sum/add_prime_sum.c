#include<unistd.h>
#include<stdio.h>

void ft_putchar_fd(char c)
{
    write(1,&c,1);
}


void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-');
		ft_putchar_fd('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10);
		ft_putchar_fd(n % 10 + '0');
	}
	else
		ft_putchar_fd(n % 10 + '0');
}
int ft_atoi(char *num)
{
    int result = 0;
    int sign = 1;
    int i = 0 ;

    while (num[i] >= 9 && num[i] <= 13)
    {
        i++;
    }
    if(num[i] == '-' || num[i] == '+')
    {
        if(num[i] == '-')
            sign *= -1;
        i++;
    }
    while(num[i] >= '0' && num[i] <='9')
    {
        result = result * 10 + (num[i] - '0');
        i++;
    }
    return (result * sign);
}

int is_prime(int num)
{
    int i = 2;

    while( i * i <= num)
    {
        if(num % i == 0)
        {
           return 0;
        }
        i++;
    }
    return (1);
}
int get_sum(int num)
{
    int i = 2;
    int sum = 0;

    while(i <= num)
    {
        if(is_prime(i))
        {
            sum = sum + i ;
        }
        i++;
    }
    return sum;

}

int main(int argc, char ** argv)
{
    if( argc == 2)
    {
        int res = get_sum(ft_atoi(argv[1]));
        ft_putnbr_fd(res);

    }
    else
    {
         write(1,"0",1);
    }
    write(1,"\n",1);
    return (0);
}
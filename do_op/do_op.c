#include<unistd.h>
#include<stdio.h>
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
int do_op(char *num1, char op, char *num2)
{
    if(op == '+')
        return ft_atoi(num1) + ft_atoi(num2);
    else if(op == '-')
        return ft_atoi(num1) - ft_atoi(num2);
    else if(op == '*')
        return ft_atoi(num1) * ft_atoi(num2);
    else if(op == '/')
        return ft_atoi(num1) / ft_atoi(num2);
     else if(op == '%')
        return ft_atoi(num1) % ft_atoi(num2);
     else
        return 0;
}

int main(int argc, char **argv)
{
    
    if(argc == 4)
    {
        int res = do_op(argv[1],argv[2][0],argv[3]);
        printf("%d", res);
    }
    printf("\n");
    return (0);
    
}
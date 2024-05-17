#include<stdio.h>
#include<stdlib.h>

int is_prime(int num)
{
    int i = 2;
    while( i * i <= num)
    {
        if(num % i == 0)
            return 0;
        i++;
    }
    return 1;

}

void fprime(int num)
{
    int i = 2;
    
    if(is_prime(num))
    {
        printf("%d",num);
        return;
    }
     
    while( i < num)
    {
        if(is_prime(i))
        {
            if(num % i == 0)
            {
                printf("%d*",i);
                fprime(num / i);
                return;
            }
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        if(atoi(argv[1]) > 0)
            fprime(atoi(argv[1]));
    }
    printf("\n");
    return 0;
}
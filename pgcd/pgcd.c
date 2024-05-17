#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int find_min(int a,int b)
{
    if(a > b)
        return b;
    return a;
}
int find_max(int a,int b)
{
    if(a < b)
        return b;
    return a;
}

int pgcd (int num1,int num2)
{
   int min = find_min(num1,num2);
   int max = find_max(num1,num2);
   int reminder = 0;

   while(1)
   {
    if(min == 0)
        return max;
     reminder = max % min;
     if(reminder == 0)
     {
        return min;
     }
     max = min;
     min = reminder;
    }
}

int main(int argc, char** argv)
{
    if(argc == 3)
    {
        printf("%d",pgcd(atoi(argv[1]),atoi(argv[2])));
    }
    printf("\n");
    return  0;
}
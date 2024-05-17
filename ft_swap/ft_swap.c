void	ft_swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

// #include<stdio.h>
// int main ()
// {
//     int a = 9;
//     int b = 6;
//     ft_swap(&a,&b);
//     printf("%d",a);
//     printf("%d",b);
// }
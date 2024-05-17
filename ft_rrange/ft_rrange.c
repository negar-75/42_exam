#include<stdlib.h>

int     *ft_rrange(int start, int end)
{
    int step = -1;
    int n = end - start + 1;
    if(n < 0)
        n *= -1;
    int *arr = malloc(sizeof(int)* n);
    if(start > end)
        step = 1;
    if(arr)
    {
        int i = 0;
        while(i < n)
        {
            arr[i] = end;
            end = end + step;
            i++;
        }
    }
    return arr;
}
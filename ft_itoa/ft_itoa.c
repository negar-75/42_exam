#include <stdlib.h>
#include<unistd.h>
#include<stdio.h>
int num_len(int num)
{
    int len = 0;
    if (num == 0)
        return 1;
    if(num < 0)
    {
        num *= -1;
        len++;
    }
    while(num)
    {
        num = num / 10;
        len++;
    }
    return len;
}

char	*ft_itoa(int nbr)
{
    int len  = num_len(nbr);
    char *nums = malloc(len + 1 * sizeof(char));
    nums[len] = '\0';
    if(nbr == 0)
    {
        nums[0] = '0';
        return nums;
    }
    if (nbr < 0)
	{
		nums[0] = '-';
		nbr = -(nbr);
	}
    len--;
    while(nbr)
    {
       nums[len] =  (nbr % 10 )+ '0';
       nbr = nbr / 10;
       len--;
    }
    return nums;  
}

// int main ()
// {
    
//     printf("%s",ft_itoa(-23));
//     return 0;
// }
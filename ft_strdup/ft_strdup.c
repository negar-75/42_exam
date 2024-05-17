#include<stdlib.h>

int	ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

char    *ft_strdup(char *src)
{
  char *arr = malloc(ft_strlen(src) + 1 * sizeof(char));
  if(arr == NULL)
    return 0;
  int i = 0;
  while(src[i] != '\0')
  {
    arr[i] = src[i];
    i++;
  }
  arr[i] = '\0';
  return arr;
}

#include<stdio.h>
int main ()
{
    char *test = "today is thursday";
    printf("%s",ft_strdup(test));
    return 0;
}
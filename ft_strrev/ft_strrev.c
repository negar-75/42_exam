#include<unistd.h>
#include<stdio.h>


char    *ft_strrev(char *str)
{
    int len = 0;
    char temp ;
    while(str[len])
        len++;
    printf("%d",len);
    int i = 0;
    while(i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
        i++; 
    }
    return str;     
}

int main() {
    char str[] = "hellodear"; // Declare a modifiable character array
    printf("%s", ft_strrev(str));
    return 0;
}
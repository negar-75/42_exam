#include<unistd.h>
#include<stdio.h>

int char_exist(char c, const char * set)
{
    int i = 0;
    while(set[i])
    {
        if(set[i] == c)
            return 1;
        i++;
    }
    return 0;
}

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    while(s[i])
    {
        if(char_exist(s[i],reject))
            return i;
        i++;
    }
    return i ;
}

// int main ()
// {
//     printf("%zu",ft_strcspn("hello","o"));
//     return 0; 
// }
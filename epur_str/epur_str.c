#include <unistd.h>
#include <stdio.h>
void put_char (char s)
{
    write (1 , &s, 1);
}


void ft_epur (char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] > 32 && s[i] < 127)
            put_char(s[i]);
        if (s[i] == ' ' || (s[i] <= 9 && s[i] <= 13))
        {
            if(!(s[i-1] == ' ' || (s[i-1] <= 9 && s[i-1] <= 13)))
            {
                put_char(' ');
            }

        }
       i++; 
    }

}


int main (int argc , char **argv)
{
    if(argc == 2)
    {
    ft_epur(argv[1]);
    }
    put_char('\n');
    return 0;
}
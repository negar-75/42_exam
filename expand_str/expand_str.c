#include <unistd.h>
#include <stdio.h>
void put_char (char s)
{
    write (1 , &s, 1);
}

void expand_str(char *s)
{   
    int i = 0;
    int flag = 0;
    while(s[i] == ' ' || (s[i] <= 9 && s[i] <= 13))
        i++;
     while(s[i] != '\0')
    {
      
        if (s[i] == ' ' || (s[i] <= 9 && s[i] <= 13))
        {
           flag = 1;
        }
        if(!(s[i] == ' ' || (s[i] <= 9 && s[i] <= 13)))
        {
         if(flag)
            {
                put_char(' ');
                put_char(' ');
                put_char(' ');
                flag = 0;
            }
           put_char(s[i]); 
        }
           
       i++; 
    }
}




int main (int argc , char **argv)
{
    if(argc == 2)
    {
    expand_str(argv[1]);
    }
    put_char('\n');
    return 0;
}
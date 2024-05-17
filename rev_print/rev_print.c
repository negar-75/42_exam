#include <unistd.h>
 void put_char (char s)
 {
    write (1 , &s, 1);
 }

 int	ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

 void rev_print (char *s)
 {
   int i = ft_strlen(s);
   i -= 1;
   while( i >= 0)
   {
    put_char(s[i]);
    i--;
   }
 }
int main (int argc , char **argv)
 {
    if(argc == 2)
    {
     rev_print(argv[1]);
    }
    put_char('\n');
    return 0;
 }
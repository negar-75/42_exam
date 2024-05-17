#include <unistd.h>
 void put_char (char s)
 {
    write (1 , &s, 1);
 }

 void ul_str(char *s)
 {
    int i = 0;
    while( s[i] != '\0')
    {
        if((s[i] >= 'a' && s[i] <= 'z'))
        {
           put_char(s[i] - 32);
        }else if (s[i] >= 'A' && s[i] <= 'Z')
        {
           put_char(s[i] + 32);
           
        }else
            put_char(s[i]);
      i++;  
    }
 }

 int main (int argc , char **argv)
 {
    if(argc == 2)
    {
     ul_str(argv[1]);
    }
    put_char('\n');
    return 0;
 }
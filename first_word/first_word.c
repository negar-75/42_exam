#include<unistd.h>

void put_char(char c)
{
    write(1,&c,1);
}

void first_word(char *s)
{
    while(*s && ((*s >= 9 && *s <= 13) || *s == ' '))
            s++;
     while(*s && !((*s >= 9 && *s <= 13) || *s == ' '))
     {
        put_char(*s);
        s++;
     }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        first_word(argv[1]);
    }
    put_char('\n');
    return(0);
}
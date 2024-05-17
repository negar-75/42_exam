#include<unistd.h>

void print_char(char c)
{
    write(1,&c,1);
}

void rotone (char *str)
{
    if(!str)
        return;
    while(*str)
    {
        if((*str >='a' && *str < 'z') || (*str >='A' && *str < 'Z'))
        {
            print_char(*str + 1);
        }
        else if(*str == 'z' || *str == 'Z'  )
        {
            print_char(*str - 25);
        }
        else
            print_char(*str);
        str++;
    }
}

int main(int argc, char ** argv)
{
    if( argc == 2)
    {
        rotone (argv[1]);
    }
    write(1,"\n",1);
    return (0);
}

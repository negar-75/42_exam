#include<unistd.h>
void put_char(char c)
{
    write(1,&c,1);
}

void rot_13(char *str)
{
    int i = 0;
    while(str[i])
    {
        if((str[i] >= 'a' && str[i] <= 'm' )|| (str[i] >= 'A' && str[i] <= 'M' ))
        {
            put_char(str[i] + 13);
        }
        else if((str[i] >= 'n' && str[i] <= 'z' )|| (str[i] >= 'N' && str[i] <= 'Z' ))
        {
            put_char(str[i] - 13);
        }
        else
        {
            put_char(str[i]);
        }
        i++;
    }
}

int main (int argc, char** argv)
{
    if(argc == 2)
    {
        rot_13(argv[1]);
    }
    put_char('\n');
    return(0);
}
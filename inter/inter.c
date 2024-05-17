#include<unistd.h>

void put_char(char c)
{
    write(1,&c,1);
}
int char_exist(char *set, char c, int len)
{
    int i = 0;
    while(i < len)
    {
        if(set[i] == c)
            return 1;
        i++;
    }
    return 0;
}
int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}

void inter(char *s1, char *s2)
{
    int i  = 0;
    while(s1[i])
    {
        if(char_exist(s1,s1[i],i) == 0)
        {
            if(char_exist(s2,s1[i],ft_strlen(s2)) == 1)
                put_char(s1[i]);      
        }
        i++;
    }
}






int main(int argc, char **argv)
{
    if(argc == 3)
    {
        inter(argv[1],argv[2]);
    }
    put_char('\n');
    return(0);
}
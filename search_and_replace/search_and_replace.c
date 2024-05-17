#include<unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}


void search_replace(char *str,char a, char b)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] == a)
            write(1,&b,1);
        else 
            write(1,&str[i],1);
        i++;
    }
}





int main(int argc, char **argv)
{
    if(argc == 4 && ft_strlen(argv[2]) == 1  && ft_strlen(argv[3]) == 1)
    {
        search_replace(argv[1],argv[2][0],argv[3][0]);
    }
    write(1,"\n",1);
    return 0;
}
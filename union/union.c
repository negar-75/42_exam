#include<unistd.h>

void put_char(char c)
{
    write(1,&c,1);
}

int char_exits(char *s,int i, char c)
{
    int j = 0;
    while(j < i && s[j])
    {
        if(s[j] == c)
            return 1;
        j++;   
    }
    return 0;
}
void ft_union(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    while(s1[i])
    {
        if(!char_exits(s1,i,s1[i]))
            put_char(s1[i]);
        i++;
    }
    
    while(s2[j])
    {
        if(!char_exits(s2,j,s2[j]) && !char_exits(s1,i,s2[j]))
            put_char(s2[j]);
        j++;
    }
}




int main(int argc, char **argv)
{
    if(argc == 3)
    {
        ft_union(argv[1],argv[2]);
    }
    put_char('\n');
    return(0);
}
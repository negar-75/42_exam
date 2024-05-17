#include <stdio.h>
int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}

int hidenp (char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while(s1[i] && s1[j])
    {
        if(s1[i] == s2[j])
        {
              i++;
        }
        j++;
    }

    if(i == ft_strlen(s1))
        return 1;
    else
        return 0;
}



int main(int argc, char** argv)
{
    if(argc == 3)
    {
        printf("%d",hidenp((argv[1]),(argv[2])));
    }
    printf("\n");
    return  0;
}
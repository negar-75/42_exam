#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void put_str(char* s)
{
    int i = 0;
    while(s[i])
    {
        write(1,&s[i],1);
        i++;
    }
}

int word_count(char *str)
{
    int i = 0;
    int count = 0;
    while(str[i])
    {
        while(str[i] == ' ')
            i++;
        if(str[i] && str[i] != ' ')
            count++;
        while(str[i] && str[i] != ' ')
            i++;
    }
    return count;
}
char*   word_allocation(char *str)
{
    int i = 0;
    char *word;
    
    while( str[i] && str[i] != ' ')
        i++;
    word = malloc((i + 1) * sizeof(char));
    if(!word)
        return NULL;
    i =  0 ;
    while(*str && *str != ' ')
    {
        word[i] = *str;
        i++;
        str++;
    }
    word[i] = '\0';
    return word;
}


void ft_split(char *str)
{
    int words = word_count(str);
    int j = 0;
    char **arr;

    arr = (char **)malloc((words + 1) * sizeof(char *));
    if(!arr)
        return;
    while(*str)
    {
        while(*str && *str == ' ')
            str++;
        if(*str)
        {
            arr[j] = word_allocation(str);
            // if(!arr[j])
            //     free_memory(arr,j);
            j++;
            while(*str && *str != ' ')
                str++;
        }
    }
    arr[j] = NULL;
    j--;
    while(j >= 0)
    {
        put_str(arr[j]);
        if(j != 0)
            write(1," ",1);
        j--;
    }

}

int main (int argc, char** argv)
{
    
    if(argc == 2)
    {
        ft_split(argv[1]);
    }
    write(1,"\n",1);
    return (0);
}
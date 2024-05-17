#include <stdlib.h>
#include<unistd.h>
#include<stdio.h>

void put_char(char c)
{
    write(1,&c,1);
}
void put_str(char *s)
{
    int i = 0;

    while(s[i])
    {
        put_char(s[i]);
        i++;
    }
}
int count_words(char *s)
{
    int i = 0;
    int count  = 0;
    while(s[i])
    {
        while(s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
            i++;
        if(s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
            count++;
        while(s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
            i++;
    }
    return count;
}



char* word_allocation(char *s)
{
    int i = 0;
    while(s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
        i++;
    char* word = malloc(sizeof(char) * (i + 1));
    i = 0;
    while(s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
    {
        word[i] = s[i];
        i++;
    }
    word[i] ='\0';
    return word;
}

void rostirng(char *s)
{
    int words = count_words(s);
    char **arr = malloc(sizeof(char *) * (words + 1));
    int flag = 0;
    int i = 0;

    while(*s)
    {
        while(*s && ((*s >= 9 && *s <= 13) || *s == ' '))
            s++;
        if(*s && !flag)
        {
            arr[words - 1] = word_allocation(s);
            flag = 1;
            
        }else if(*s && flag)
        {
            arr[i] = word_allocation(s);
            i++;
        }
        else
            continue;
        
        while(*s && !((*s >= 9 && *s <= 13) || *s == ' '))
            s++;
    }
    arr[i + 1] = NULL;
    i = 0;
    while(arr[i])
    {
        put_str(arr[i]);
        if(arr[i + 1] != NULL)
            put_char(' ');
        i++;
    }
}



int main(int argc, char **argv)
{
    if(argc >= 2)
    {
        rostirng(argv[1]);
    }
    put_char('\n');
    return(0);
}
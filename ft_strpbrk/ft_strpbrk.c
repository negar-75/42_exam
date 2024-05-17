

int char_exist(char c, const char * set)
{
    int i = 0;
    while(set[i])
    {
        if(set[i] == c)
            return 1;
        i++;
    }
    return 0;
}




char	*ft_strpbrk(const char *s1, const char *s2)
{
    char *tmp = s1;
    while(*s1)
    {
        if(*s1,s2)
            return s1;
        s1++;
    }
    return tmp;
}
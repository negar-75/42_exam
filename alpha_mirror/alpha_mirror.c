#include<stdio.h>
#include<unistd.h>

void print_char(char c)
{
    write(1,&c,1);
}
void alpha_mirror(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            print_char('z' - (str[i] - 'a'));
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            print_char('Z' - (str[i] - 'A'));
        }
        else
        {
            print_char(str[i]);
        }
        i++;
    }

}
int main(int argc, char** argv)
{
    if(argc == 2)
    {
        alpha_mirror(argv[1]);
    }
    write(1,"\n",1);
    return  0;
}
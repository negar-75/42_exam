#include<unistd.h>

void print_char(char c, int n)
{
    int i = 0;
    while (i <= n)
    {
        write(1,&c,1);
        i++;
    }

}

int main(int argc, char**argv)
{
    int i = 0;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
                print_char(argv[1][i], (argv[1][i] - 'a'));
            if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                print_char(argv[1][i], (argv[1][i] - 'A'));
            i++;
        }
    }
}
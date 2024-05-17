#include<stdio.h>
void	sort_int_tab(int *tab, unsigned int size)
{
    int temp = 0;
    int i = 0;
    int j = 0;

    while( i < size - 1)
    {
        j = 0;
        while(j < size  - i - 1)
        {
            if(tab[j] > tab[j+1])
            {
                temp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}
#include<stdio.h>
int main ()
{
    int tab[] = {2,4,3,6,3,9,7,4,3,5,3,2,6};
    sort_int_tab(tab,13);
    int i = 0;
    while(i < 13)
    {
        printf("%d",tab[i]);
        i++;
    }
    return 0;
}
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "sort_list.h"


void	swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
int		ascending(int a, int b)
{
    return(a <= b);		
}
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *head = lst;
    t_list *temp;
    while(lst)
    {
        temp = lst->next;
        while(temp)
        {
            printf("lst %d\n",*((int *)lst->data));
            printf("temp %d\n",*((int *)temp->data));
            if(!cmp((*(int *)lst->data),*((int *)temp->data)))
            {
                swap(&(*(int *)lst->data),&(*((int *)temp->data)));
            }
            temp = temp->next;
        }
        lst = lst->next;
    }
    return head;
}

#include <stdlib.h>

int		main(void)
{
	t_list *l;
	int		i;
	t_list	*t;
	t_list	*b;

	i = 10;
    l = malloc(sizeof(t_list));
    t = l;
    b = l;
    while (i)
    {
        l->data = malloc(sizeof(int)); // Allocate memory for integer data
        *((int*)(l->data)) = i % 3;
        l->next = malloc(sizeof(t_list));
        l = l->next;
        --i;
    }
    l->data = malloc(sizeof(int)); // Allocate memory for integer data
    *((int*)(l->data)) = 22;
    l->next = NULL;

	// while (t)
	// {
	// 	printf("%dinitial linked list \n", (*((int*)t->data)));
	// 	t = t->next;
	// 	++i;
	// }
	b = sort_list(b, ascending);
	while (b)
	{
		printf("%d  -> ", (*((int*)b->data)));
		b = b->next;
		++i;
	}
}
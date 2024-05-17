#include "ft_list_remove_if.h"
#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

int cmp(void *a, void *b) {
    // Compare the integers
    return (*(int*)a == *(int*)b);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *a, void *b))
{
   t_list *curr = *begin_list;
   t_list *pre = NULL;
   while(curr)
   {
		if(cmp(curr->data,data_ref) == 1)
		{
			if(pre == NULL)
			{
				*begin_list = curr->next;
				free(curr);
				curr = *begin_list;
			}
			else
			{
				pre->next = curr->next;
				free(curr);
				curr = pre->next;
			}
		}
		else
		{
			pre = curr;
			curr = curr->next;
		}
   }
   
}

void print_list(t_list *begin_list) {
    while (begin_list) {
        printf("%d -> ", *(int *)begin_list->data);
        begin_list = begin_list->next;
    }
    printf("NULL\n");
}

// Test function
void test_ft_list_remove_if() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    t_list *head = malloc(sizeof(t_list));
    head->data = malloc(sizeof(int));
    *(int *)(head->data) = 1;
    head->next = malloc(sizeof(t_list));
    head->next->data = malloc(sizeof(int));
    *(int *)(head->next->data) = 2;
    head->next->next = malloc(sizeof(t_list));
    head->next->next->data = malloc(sizeof(int));
    *(int *)(head->next->next->data) = 3;
    head->next->next->next = malloc(sizeof(t_list));
    head->next->next->next->data = malloc(sizeof(int));
    *(int *)(head->next->next->next->data) = 4;
    head->next->next->next->next = malloc(sizeof(t_list));
    head->next->next->next->next->data = malloc(sizeof(int));
    *(int *)(head->next->next->next->next->data) = 5;
    head->next->next->next->next->next = NULL;

    printf("Original list: ");
    print_list(head);

    int data_to_remove = 1;
    ft_list_remove_if(&head, &data_to_remove, cmp);

    printf("List after removing %d: ", data_to_remove);
    print_list(head);
}

int main() {
    test_ft_list_remove_if();
    return 0;
}
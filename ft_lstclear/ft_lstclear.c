#include "ft_lstclear.h"
#include "unistd.h"
#include "stdlib.h"
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
    if(!lst || !del)
        return;
    t_list *head = *lst;
    t_list *temp  = NULL; 

    while(head)
    {
        temp = head->next;
        del(head -> data);
        free(head);
        head = temp;
    }  
}
t_list	*ft_lstnew(void *content)
{
    t_list *new = malloc(sizeof(t_list));
    if(!new)
        return NULL;
    new->data = content;
    new->next = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    if(!*lst)
    {
        *lst = new;
    }
    else{
        t_list *head = *lst;
        while(head->next)
        {
            head = head->next;
        }
        head->next = new;
    }
    
} 

void	ft_lstadd_front(t_list **lst, t_list *new)
{
    if(!lst || !new)
        return; 
    new->next = *lst;
    *lst = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_head = NULL;
    t_list *node = NULL;
    void *new_content;

    while(lst)
    {
        new_content = f(lst->data);
        node = ft_lstnew(new_content);
        if(!node)
        {
            del(new_content);
            ft_lstclear(new_head,del);
            return new_head;
        }
        ft_lstadd_back(&new_head,node);
        lst = lst->next;
    }
}
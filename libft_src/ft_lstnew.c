#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list  *lst;

    lst = (t_list *) malloc(sizeof(t_list));
    if(!lst)
        return(NULL);
    lst->next = NULL;
    if(content)
        lst->content = content;
    else
        lst->content = NULL;
    return(lst);
}
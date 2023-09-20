#include "../libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *newlst;
    t_list  *new_elem;

    if(!(lst && f && del))
        return(NULL);
    newlst = ft_lstnew(f(lst->content));
    if(!newlst)
        return(NULL);
    lst = lst->next;
    while(lst)
    {
        if(!(new_elem = ft_lstnew(f(lst->content))))
        {
            ft_lstclear(&newlst, del);
            return(NULL);
        }
        ft_lstadd_back(&newlst, new_elem);
        lst = lst->next;
    }
    return(newlst);
}
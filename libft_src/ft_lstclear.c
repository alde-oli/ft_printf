#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *todel;
    t_list *next;

    if (lst && del)
    {
        todel = *lst;
        while (todel)
        {
            next = todel->next;
            ft_lstdelone(todel, del);
            todel = next;
        }
        *lst = NULL;
    }
}

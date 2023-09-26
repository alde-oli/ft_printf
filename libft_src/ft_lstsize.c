#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int lstnb;
    t_list *slow = lst;
    t_list *fast = lst;

    lstnb = 0;
    slow = lst;
    fast = lst;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return(0);
    }
    while(lst)
    {
        lstnb++;
        lst = lst->next;
    }
    return(lstnb);
}

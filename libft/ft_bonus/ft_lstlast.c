#include "../libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list *slow;
    t_list *fast;

    if (lst)
    {
        slow = lst;
        fast = lst->next;
        while (fast && fast->next)
        {
            if (slow == fast)
                return (NULL);
            slow = slow->next;
            fast = fast->next->next;
        }
        while (lst->next)
            lst = lst->next;
        return (lst);
    }
    else
        return (NULL);
}
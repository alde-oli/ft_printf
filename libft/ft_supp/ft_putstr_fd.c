#include "../libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	if(str)
		write(fd, str, ft_strlen(str));
}
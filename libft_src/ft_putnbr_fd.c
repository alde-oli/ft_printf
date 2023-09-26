#include "libft.h"

static void	writenbr_fd(int nb, int fd)
{
	char	digit;

	if(nb < 0)
		digit = -1 * (nb % 10) + '0';
	else
		digit = nb % 10 + '0';
	nb /= 10;
	if(nb != 0)
		writenbr_fd(nb, fd);
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if(nb < 0)
		write(fd, "-", 1);
	writenbr_fd(nb, fd);
}
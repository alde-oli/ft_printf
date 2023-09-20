#include "../libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	v;
	int	neg;

	neg = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\t')
		|| (str[i] == '\n' || str[i] == '\v')
		|| (str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	v = 0;
	while (47 < str[i] && str[i] < 58)
	{
		v *= 10;
		v = v + str[i] - '0';
		i++;
	}
	v *= neg;
	return (v);
}
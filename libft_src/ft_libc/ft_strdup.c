#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	ft_strlcpy(dest, src, ft_strlen(src) + 1);
	return(dest);
}
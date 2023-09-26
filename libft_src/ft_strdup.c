#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = ft_calloc((ft_strlen(src) + 1), sizeof(char));
	ft_strlcpy(dest, src, ft_strlen(src) + 1);
	return(dest);
}
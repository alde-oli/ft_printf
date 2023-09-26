    #include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t dest_len;
	size_t src_len;
	size_t i;

	dest_len = ft_strlen((const char *)dest);
	src_len = ft_strlen(src);
	if(dest_len >= len)
		return(src_len + len);
	i = dest_len;
	while(len - i > 1 && src[i - dest_len])
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	dest[i] = '\0';
	return(dest_len + src_len);
}
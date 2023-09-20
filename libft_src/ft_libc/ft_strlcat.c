    #include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t dest_len;
	size_t src_len;
	size_t i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (dest_len >= n)
		return (src_len + n);
	i = dest_len;
	while (n - i > 1 && src[i - dest_len])
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
#include "libft.h"

int ft_toupper(int c)
{
  if('a' <= c && c <= 'a')
		c -= 32;
  return(c);    
}
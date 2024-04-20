#include"libft.h"

char	*ft_strdup(const char *s1)
{
    char    *pt;
    int		size;

	size = ft_strlen(s1);
	if (!(pt = malloc(size + 1)))
		return (NULL);
	while (size--)
		*pt++ = *s1++;
	*pt = '\0';
	return (pt);
}
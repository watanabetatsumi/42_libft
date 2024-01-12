#include"libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*pt;
	int		size;

	size = ft_strlen(s);
	if (!(pt = malloc(len + 1)))
		return (NULL);
	if (size <= start || len == 0)
		return (pt);//??
	while (start--)
		s++;
	while (len--)
	{
		*(pt++) = *(s++);
		if (!(*s))
			break;
	}
	*pt = '\0';
	// null終端は?
}
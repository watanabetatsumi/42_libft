#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	if (dst == NULL && src == NULL)
		return (NULL);
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (n--)
	{
		*ds = *sr;
		ds++;
		sr++;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		str++;
		size ++;
	}
	return (size);
}

char *ft_strcat(char *dest, const char *src)
{
	int	index;

	index = ft_strlen(dest);
	while (*src)
		dest[index++] = *(src++);	
	dest[index] = '\0';
	return (dest);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int		size_1;
	int		size_2;
	int		sum;
	char	*pt;

	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	sum = size_1 + size_2;
	if (!(pt = malloc(sum + 1)))
		return (NULL);
	pt = (char *)ft_memcpy((void *)pt,s1,size_1);
	pt = ft_strcat(pt,s2);
	return (pt);
}

#include"stdio.h"
int main(void)
{
	char s1[] = "hello";
	char s2[] = "world";
	char *new_str = ft_strjoin(s1,s2);
	printf("%s", new_str);
	free (new_str);
 	return (0);
}
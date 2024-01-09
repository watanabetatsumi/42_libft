#include "libft.h"

size_t ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

char *ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char *flag;
	char *flag_2;
	int	len_s2;

	len_s2 = ft_strlen(s2);
	if (len_s2 == 0)
		return ((char *)s1);
	while (len-- >= len_s2)
	{
		if (*s1 == *s2)
		{
			flag = (char *)s1;
			flag_2 = (char *)s2;
			while (*flag++ == *flag_2++)
			{
				if (*flag_2 == '\0')
					return ((char *)s1);
				continue;	
			}
		}
		s1++;
	}
	return (NULL);
}

#include <stdio.h>
int main(void)
{
	char str1[] = "abcdefg";
	char str2[] = "fg";
	int size = ft_strlen(str1);
	printf("%p\n",ft_strnstr(str1,str2,size));
	return (0);
}

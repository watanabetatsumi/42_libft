#include "stdlib.h"

int	ft_putstr(char *str, int n, int index)
{
	char 	moji;
	int		num;
	int		nokori;

	num = n / 10;
	nokori = n % 10;
	if (num > 0)
	{
		index = ft_putstr(str,num,index);
	}
	moji = nokori + 48;
	str[index] = moji;
	return (index + 1);
}

int	ft_gauge(int n)
{
	int	len;
	int	fugou;

	len = 1;
	fugou = 0;
	if (n < 0)
	{
		fugou = 1;
		n = n*-1;
	}
	while (n > 9)
	{
		n = n/10;
		len++;
	}
	return (len + fugou);
}

char *ft_itoa(int n)
{
	int 	len;
	char	*str;
	int		index;

	len = ft_gauge(n);
	index = 0;
	if(!(str = (char *)malloc(len + 1)))
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		n = n * -1;
		index++;
	}
	index = ft_putstr(str,n,index);
	str[len] = '\0';
	return (str);
}

#include "stdio.h"
int	main(void)
{
	int n = -243344334;
	char *str = ft_itoa(n);
	printf("%s",str);
	return	(0);
}
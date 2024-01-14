#include"libft.h"

int ft_count(char const *s1, char sep)
{
    int count;
	int	flag;
	int	index;

	flag = 0;
	count = 0;
	index = 0;
    while (s1[index])
    {
		if ((s1[index] != '\0' && s1[index] != sep))
			flag = 1;
		else
			flag = 0;
		if ((s1[index+1] == '\0' || s1[index+1] == sep) && flag == 1)
			count++;
        index++;
    }
    return (count);
}

int	*ft_makelist(char const *s1, char sep, int *list)
{
	int len;
	int	flag;
	int	index;
	int *pt;//ここ重要

	flag = 0;
	len = 0;
	index = 0;
	pt = list;
    while (s1[index])
    {
		if ((s1[index] != '\0' && s1[index] != sep))
		{
			flag = 1;
			len++;
		}
		if ((s1[index+1] == '\0' || s1[index+1] == sep) && flag == 1)
		{
			*(list++) = len;
			len = 0;
			flag = 0;
		}
        index++;
    }
	*list = (int)'\0';
    return (pt);
}

char	**ft_makestr(char **str, int *list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		if (!(str[i] = (char *)malloc(list[i] + 1)))
		{
			j = 0;
			while (j < i)
				free(str[j]);
			free(str);
			free(list);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_putwords(char **str ,int *list, char const *s, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((*s != sep && *s != '\0'))
			str[i][j++] = *(s);
		if (j == list[i])
		{
			str[i][j] = '\0';
			j = 0;
			i++;
		}
		s++;//ここが重要
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
    int		count;
	char	**str;
	int		*list;

	count = ft_count(s,c);
	if (!(str = (char **)malloc(count + 1)))
		return (NULL);
	if (!(list = (int *)malloc(sizeof(int)*(count + 1))))
	{
	    free(str);
		return (NULL);
	}
	list = ft_makelist(s,c,list);
	str = ft_makestr(str,list);
    str = ft_putwords(str,list,s,c);
    free(list);
	return (str);
}

#include"stdio.h"
int main(void)
{
    char s1[] = "  a,s  ";
    char sep = ',';
    char **str = ft_split(s1,sep);
    int i = 0;
	while (str[i])
	{
		printf("%s\n",str[i]);
		free(str[i++]);
	}
	free(str);
    return (0);
}
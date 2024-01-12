#include"libft.h"
#include"stdio.h"

int ft_count(char const *s1, char const *set)
{
    int size;
    int index;

    while (*(s1))
    {
        index = 0;
        while(set[index])
        {
            if (*s1 == set[index])
            {
                size++;
                break;
            }
            index++;
        }
        s1++;
    }
    return (size);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char    *pt;
    int     index;
    int     j;

    if (!(pt = (char *)malloc(ft_count(s1,set) + 1)))
        return (NULL);
    j = 0;
    while (*s1)
    {
        index = 0;
        while(set[index])
        {
            if (*s1 == set[index++])
            {
                pt[j++] = *s1;
                break;
            }
        }
        s1++;
    }
    pt[j] = '\0';
    return(pt);
}

int main(void)
{
    char s1[] = "1234AAA1224";
    char set[] = "1234";
    char *new_str = ft_strtrim(s1,set);
    printf("%s",new_str);
    free(new_str);
    return (0);
}
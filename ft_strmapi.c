#include "libft.h"
#include "stdlib.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int num;
    char *words;
    int i;

    num = ft_strlen(s);
    if (!(words = malloc(num + 1)))
        return NULL;
    i = 0;
    while (i++ < num)
        words[i] = f(num,s[i]);
    words[i] = "\0";
    return (words);
}

int main(void)
{
    char s[] = "faafa";
    char (* p_func) (unsigned int,char) = ;
    ft_strmapi(s,p_func);
}
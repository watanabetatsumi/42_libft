#include <stdlib.h>
void *ft_calloc(size_t nmemb, size_t size)
{
    void *pt;
    size_t sum;

    sum  = nmemb * size;
    if (size == 0 || nmemb == 0)
        return (NULL);
    if (!(pt = malloc(sum)))
		return (NULL);
	pt = ft_bzero(pt, sum);
    // 全部ゼロで埋めたら、結局intだろうがcharだろうが、変わらない。
	return (pt);
}

int main(void)
{
	ft_calloc(1, 1);
	return (0);
}
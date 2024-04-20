#include"libft.h"

void ft_striteri(char *s, void (*f)(unsigned int,char*)){
    while (*s++)
        f(5,s);
}

int main(void){
    //
}
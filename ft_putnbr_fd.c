void ft_putnbr_fd(int n, int fd){
    char *str;

    str = ft_itoa(n);
    while (*str++)
        write(fd,str,1);
}

int main(void){
    //
}
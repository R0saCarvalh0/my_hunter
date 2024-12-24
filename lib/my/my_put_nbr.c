/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** return the number as a parameter
*/
#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0 && nb <= 9){
        nb += 48;
        my_putchar(nb);
        return 0;
    }
    if (nb / 10 > 0)
        my_put_nbr(nb / 10);
    my_putchar(48 + nb % 10);
    return 0;
}

/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** displays, one-by-one, the characters of a string.
*/
#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        write(1, &str[i], 1);
        i += 1;
    }
    return 0;
}

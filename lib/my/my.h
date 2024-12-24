/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** lib
*/

#ifndef MY_H
    #define MY_H

    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

int my_cat(char *name_file);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);

#endif /* MY_H */

/*
** EPITECH PROJECT, 2024
** my_cat.c
** File description:
** afffiche ce que contient un fichier
*/

#include "my.h"

int my_cat(char *name_file)
{
    int fd;
    char buffer[20];
    int size = 19;

    fd = open(name_file, O_RDONLY);
    if (fd == -1){
        return 84;
    }
    for (int i = 0; size == 19; i++){
        size = read(fd, buffer, 19);
        if (size == -1){
            return 84;
        }
        if (write(1, buffer, size) == -1){
            return 84;
        }
    }
    close(fd);
    return 0;
}

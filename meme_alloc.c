/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-louis.rollet
** File description:
** meme_alloc
*/
#include "my.h"

int fs_get_number_from_first_line( char const * filepath)
{
    int fd = open (filepath, O_RDONLY);
    if (fd == -1)
        return -1;
    char buff[30000];
    read(fd, buff, 30000);
    int r = 0;
    for (int i = 0; buff[i] != '\n' && buff[i] != '\0'; i++){
        if (buff[i] >= '0' && buff[i] <= '9'){
            r = (10 * r )+ (buff[i] - '0');
        }
    }
    close(fd);
    return r;
}

char **mem_alloc_2d_array ( int nb_rows , int nb_cols )
{
    char **result = malloc((nb_rows + 1) * sizeof(char *));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc((nb_cols + 1) * sizeof(char));
    return result;
}

/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-louis.rollet
** File description:
** more_files
*/

#include "my.h"

int is_square(t_square *square, char **tabl, int i, int j )
{
    int k = square->size;
    if (k <= 0)
        k = 1;
    for (; find_the_os(tabl, i, j, k) == 0; k++);
    k--;
    return k;
}

char **twod_array(int nb_rows, int nb_cols, char *buff, int l )
{
    int m = l + 1;
    char **result = malloc((nb_rows + 1) * sizeof(char *));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc((nb_cols + 1) * sizeof(char));
    for (int k = 0; k < nb_rows; k++){
        for (int j = 0; j < nb_cols; j++){
            result[k][j] = buff[m];
            m++;
        }
        result[k][nb_cols] = '\0';
    }
    result[nb_rows] = NULL;
    return result;
}

int line_pp(char **tabl, int x, int y)
{
    if (tabl[x][y] != '.') {
        return 1;
    }
    return 0;
}

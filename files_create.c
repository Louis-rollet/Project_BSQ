/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-louis.rollet
** File description:
** files_create
*/

#include "my.h"

char **form_file_next(char *buffer, int *e, int nb_cols, int nb_rows)
{
    int nb = 0;
    int l = 0;
    int q = 0;
    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '\n')
            nb++;
    }
    if (nb <= 1){
        *e = 1;
        return NULL;
    }
    for (; buffer[l] != '\n' && buffer[l] != '\0'; l++);
    for (int p = l + 1; buffer[p] != '\n' && buffer[p] != '\0'; p++, q++);
    nb_cols = q + 1;
    char **result = twod_array(nb_rows, nb_cols, buffer, l);
    return result;
}

char **load_2d_arr_from_file(char const * filepath, int *e)
{
    int file = open(filepath , O_RDONLY);
    if (file == -1)
        return NULL;
    struct stat st;
    int nb_rows = fs_get_number_from_first_line(filepath);
    int nb_cols = 0;
    int l = 0;
    int q = 0;
    stat(filepath , &st);
    int size = st.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    int a = read(file , buffer , size);
    buffer[size] = '\0';
    char **result = form_file_next(buffer, e, nb_cols, nb_rows);
    return result;
}

int more_l(char *o, int k)
{
    if (o[k] == '\0')
        k = 0;
    return k;
}

char **generate_map_from_string(int nb, char *o)
{
    char **map = malloc((nb + 1) * sizeof(char *));
    int k = 0;
    int j = 0;
    for (int i = 0; i < nb; i++)
        map[i] = malloc((nb + 1) * sizeof(char));
    int i = 0;
    for (; i < nb; i++) {
        for (; j < nb; j++) {
            map[i][j] = o[k];
            k++;
            k = more_l(o, k);
        }
    map[i][nb] = '\n';
    map[i][nb + 1] = '\0';
    j = 0;
    }
    map[i] = NULL;
    return map;
}

int find_the_os(char **tabl, int i, int j, int k)
{
    int a = 0;
    int b = 0;
    int r = 0;
    for (a = 0; a < k; a++) {
        if (tabl[i + a] == NULL) {
            return 2;
        }
        for (b = 0; tabl[i + a][j + b] != '\0' && b < k; b++) {
            int x = i + a;
            int y = j + b;
            r += line_pp(tabl, x, y);
        }
    }
    if (r >= 1)
        return 1;
    return 0;
}

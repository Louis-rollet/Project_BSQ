/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-louis.rollet
** File description:
** my
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_

typedef struct s_square{
    int x;
    int y;
    int size;
} t_square;

int fs_get_number_from_first_line( char const * filepath);
char **mem_alloc_2d_array ( int nb_rows , int nb_cols );
int my_getnbr(char const *str);
int my_strlen(char const *str);
char **twod_array(int nb_rows, int nb_cols, char *buff, int l);
char **load_2d_arr_from_file(char const * filepath, int *e);
char **generate_map_from_string(int nb, char *o);
int find_the_os(char **tabl, int i, int j, int k);
int is_square(t_square *square, char **tabl, int i, int j);
char **twod_array(int nb_rows, int nb_cols, char *buff, int l );
int line_pp(char **tabl, int x, int y);

#endif /* !MY_H_ */

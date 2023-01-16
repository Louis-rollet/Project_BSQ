/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-louis.rollet
** File description:
** bsq
*/
#include "my.h"

void find_largest_square(t_square *square, char **tabl, int i, int j )
{
    int size = 0;
    if (tabl[i][j] == '.'){
        size = is_square(square, tabl, i, j);
        if (size > square->size){
            square->x = i;
            square->y = j;
            square->size = size;
        }
    }
}

void find_square(t_square *square, char **tabl)
{
    for (int i = 0; tabl[i] != NULL; i++){
        for (int j = 0; tabl[i][j] != '\0' && tabl[i][j] != '\n'; j++){
            find_largest_square(square, tabl, i, j);
        }
    }
}

char **map_with_x(t_square *square, char **tabl)
{
    find_square(square, tabl);
    int x = square->x;
    int y = square->y;
    for (int i = 0; i < square->size; i++){
        for (int j = 0; j < square->size; j++){
            tabl[x + i][y + j] = 'x';
        }
    }
    return tabl;
}

int print_with_str(int a, char **argv, t_square *square)
{
    a = my_getnbr(argv[1]);
    if (a < 0)
        return 84;
    char **map_from_str = generate_map_from_string(a, argv[2]);
    map_from_str = map_with_x(square, map_from_str);
    for (int i = 0; i < a; i++){
        write(1, map_from_str[i], a);
        write(1, "\n", 1);
    }
    return 0;
}

int main(int argc, char **argv)
{
    int a = 0, j = 0, e = 0;
    struct s_square square;
    if (argv[1] == NULL)
        return (84);
    int fd = open(argv[1], O_RDONLY);
    if (argc == 3){
        return print_with_str(a, argv, &square);
    } else {
        a = fs_get_number_from_first_line(argv[1]);
        if (fd == -1 || a <= 0)
            return (84);
        char **map_from_file = load_2d_arr_from_file(argv[1], &e);
        if (e == 1)
            return 84;
        map_from_file = map_with_x(&square, map_from_file);
        for (; map_from_file[0][j] != '\n';j++);
        for (int i = 0; i < a; i++)
            write(1, map_from_file[i], j + 1);
    }
    return 0;
}

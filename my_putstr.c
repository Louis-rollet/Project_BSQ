/*
** EPITECH PROJECT, 2022
** Day04
** File description:
** Task02
*/
void my_putchar(char);

void my_putstr(char const *str )
{
    for (int i = 0; str[i] > 0 ; i ++){
        my_putchar(str[i]);
    }
}

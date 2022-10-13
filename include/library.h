/*
** EPITECH PROJECT, 2019
** library.h
** File description:
** this is mine library
*/

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stddef.h>

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

void my_putchar(char c);
int my_getnbr(char const *str);
char *my_itoa(long int number);
char *my_revstr(char *str);
int disp_stdarg(char *s, ... );
int special_printf(char *str, va_list ap, int printi);
int mine_printf_b(char *str, va_list ap, int *printi);
int mine_printf_c(char *str, va_list ap, int *printi);
int mine_printf_p(char *str, va_list ap, int *printi);
int mine_printf_ouxx(char *str, va_list ap, int *printi);
int checking_printf(char *str, va_list ap, int printi);
int mine_printf_s(char *str, va_list ap, int printi);
int mine_printf_di(char *str, va_list ap, int printi);
int print_nb_conv(int nb);

#endif
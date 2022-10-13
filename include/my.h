/*
** EPITECH PROJECT, 2019
** Header for libmy
** File description:
** Header file for libmy
*/

#ifndef MY_H
#define MY_H 1

#define OCTAL_BASE "01234567"
#define BINARY_BASE "01"
#define HEXADECIMAL_LOW "0123456789abcdef"
#define HEXADECIMAL_UPP "0123456789ABCDEF"

#define FLAGS_INT "dci"
#define FLAGS_STR "sSp"
#define FLAGS_UNSIGNED "bouxX"
#define FLAGS_FORMAT "+- #l0123456789"

#define LMY_STDIN 0
#define LMY_STDOUT 1
#define LMY_STDERR 2

#include <stdarg.h>

unsigned int get_int_size(int nbr);
unsigned int get_uint_size(unsigned int nbr);
unsigned int get_long_size(long nbr);
unsigned int get_ulong_size(unsigned long nbr);

int str_to_int(char *str);
long my_atoi(char *str);
unsigned int str_to_uint(char *str);
long str_to_long(char *str);
unsigned long str_to_ulong(char *str);

char *int_to_char(int nbr);
char *uint_to_char(unsigned int nbr);
char *long_to_char(long nbr);
char *ulong_to_char(unsigned long nbr);

void char_to_octal(int fd, char c, int index);
void my_putnbr_base_ulhex(int fd, unsigned long nbr, int *f_flags);
void my_putnbr_base_octal(int fd, unsigned int nbr, int *f_flags);
void my_putnbr_base_bin(int fd, unsigned int nbr, int *f_flags);
void my_putnbr_base_hex(int fd, unsigned int nbr, int *f_flags, int upp);
int flag_is_format(char flag);
int get_multiplier(char const *flag);
void get_format_nbr(int *formats, int *multiplier, char nb);
void add_single_f_flag(char flag, int *f_flags);
void skip_formats(char const **flag, int *formats);
// Done {
void null_pointer(int fd, int *f_flags);
void flag_handle_int(int fd, char flag, int arg, int *f_flags);
void flag_handle_str(int fd, char flag, void *arg, int *f_flags);
void flag_handle_unsigned(int fd, char flag, unsigned int arg, int *f_flags);
void flag_handle_unknown(int fd, char flag);
// }
int flag_is_int(char flag);
int flag_is_str(char flag);
int flag_is_unsigned(char flag);
char identify_type(char const *flag);
// Done {
void handle_flag(int fd, char const **flag, va_list val);
// }
// Done {
void place_alignement(int fd, int count, char c);
int do_alignement_space_bef(int fd, int *f_flags);
int do_alignement_zero_bef(int fd, int *f_flags);
int do_alignement_space_aft(int fd, int *f_flags);
// }
int is_there_sign(int nb, int *f_flags);
void display_sign(int fd, int nb, int *f_flags);
int is_there_base_prefix(unsigned int nb, unsigned int base_len, int *f_flags);
void display_base_prefix(int fd, int *f_flags, int u);
// Done {
void my_put_unbr(int fd, unsigned int nb, int *f_flags);
void my_put_nbr(int fd, int nb, int *f_flags);
// }
int is_last_udigit(unsigned int nb);
int is_last_digit(int nb);
void my_fputchar(int fd, char c);
void my_fputstr(int fd, char *str);
int my_printf(char const *format, ...);
int my_fprintf(int fd, char const *format, ...);

long my_compute_power(long nb, int p);
long my_compute_square_root(long nb);

char *my_working_strcat(char *a, char *b);
char *my_strcat(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *src);
char *my_strstr(char *str, char *to_find);

//int my_strncmp(char *s1, char *s2, int n);
//char *my_strncpy(char *dest, char *src, unsigned int n);
void my_putstr_octal(int fd, char *str);

void my_putchar(char c);
unsigned long my_strlen(char *str);
void my_putstr(char *str);
char *my_revstr(char *str);

unsigned int cnt_splt_elems(char *str, char delim);
char **my_splitstr(char *str, char delim);
void destroy_splitted(char **arr);
unsigned int count_chararr(char **arr);

//int my_strreplace(char **str, char *pattern, char *replace, int free_after);
int replace_all(char **str, char *pattern, char *replace);

#endif
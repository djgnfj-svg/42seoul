#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_info
{
    int minus;
    int zero;
    int width;
    int prec;
    char type;
    int num_base;
    int num_sign;
} t_info;

//printf.c
int ft_printf(const char *format, ...);
int ft_solution(va_list ap, char *input);
int ft_print_type(va_list ap, t_info *info);
void ft_check_info(va_list ap, char *input, t_info *info, int i);
int ft_check_type(char c, t_info *info);

//ft_print_char.c 함수한개로 줄일수있음
int ft_put_width(t_info *info);
int ft_print_char(int c, t_info *info);

//ft_print_string.c 내꺼함수로 변경하고 num에서 사용하는 함수를 내비두고 실험해보자
int ft_print_string(char *str, t_info *info);
char *ft_soultion_string(char *str, int end, char *buf, t_info *info);

//ft_print_num.c
int ft_print_num(unsigned long long num, t_info *info);
int ft_put_minus(int buf_len, t_info *info, char **buf);
char *ft_put_prec_str(unsigned long long num, t_info *info, char *buf, int buf_len);

//utils.c
void ft_init_info(t_info *info);
void ft_check_width_and_prec(va_list ap, char *input, t_info *info, int i);
char *ft_baseset(char type);
int ft_numlen(unsigned long long num, t_info *info);
char *ft_put_width_str(char *buf, t_info *info);
#endif
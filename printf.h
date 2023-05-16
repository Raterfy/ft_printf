/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:26:39 by robhak            #+#    #+#             */
/*   Updated: 2023/05/16 14:55:38 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

// int	ft_putchar(char c);
// int	ft_putstr(char *str);
// int	ft_putnbr(int n);
// int ft_putnbr_base(unsigned long long int n, char *base)
// int	print_char(char c);
// int	print_str(char *str);
// int	print_pointer(void *ptr);
// int	print_decimal(int n);
// int	print_unsigned_decimal(unsigned int n);
// int	print_hexadecimal(unsigned int n, const char *base);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_unsigned_nbr(unsigned long long int n);
int	ft_putnbr_base(unsigned long long int n, char *base);
int	print_c(va_list args);
int	print_s(va_list args);
int	print_p(va_list args);
int print_d_and_i(va_list args);
int print_u(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_percent(va_list args);

#endif
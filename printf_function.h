/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:26:39 by robhak            #+#    #+#             */
/*   Updated: 2023/05/15 15:32:56 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int ft_putnbr_base(unsigned int n, char *base);
int	print_char(char c);
int	print_str(char *str);
int	print_pointer(void *ptr);
int	print_decimal(int n);
int	print_unsigned_decimal(unsigned int n);
int	print_hexadecimal(unsigned int n, const char *base);

#endif
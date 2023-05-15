/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:26:43 by robhak            #+#    #+#             */
/*   Updated: 2023/05/15 16:29:11 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_function.h"
/*
int	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		ft_putchar(str[i++]);
	return(i);
}

int	ft_putnbr(int n)
{
	int cpt;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		cpt++;
	}
	if (n && n >= 10)
		cpt += ft_putnbr(n % 10);
	ft_putchar(n % 10 + '0');
	cpt++;
	return(cpt);
}

int ft_putnbr_base(unsigned int n, char *base)
{
	int cpt = 0;
	int base_len = 0;

	cpt = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= (unsigned int)base_len)
		cpt += ft_putnbr_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
	cpt++;
	return cpt;
}
*/

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		print_char(str[i++]);
	return (i);
}

int	print_pointer(void *ptr)
{
	unsigned long	adress;
	int cpt;

	cpt = 0;
	if (ptr)
		cpt += print_str("nil");
	adress = (unsigned long)ptr;
	cpt += print_str("0x");
	cpt += print_hexadecimal(adress, "0123456789abcdef");
	return (cpt);
}

int	print_decimal(int n)
{
	int 		cpt;

	cpt = 0;
	if (n < 0)
	{
		n = -n;
		print_char('-');
		cpt++;
	}
	if (n && n >= 10)
		cpt += print_decimal(n / 10);
	cpt += print_char(n % 10 + '0');
	return (cpt);
}

int	print_unsigned_decimal(unsigned int n)
{
	int cpt;

	cpt = 0;
	if (n >= 10)
	{
		cpt += print_unsigned_decimal(n / 10);
		cpt += print_char('0' + n % 10);
	}
	else
		cpt += print_char(n + '0');
	return (cpt);
}

int	print_hexadecimal(unsigned int n, const char *base)
{
	int	cpt;

	cpt = 0;
	if (n >= 10)
	{
		cpt += print_hexadecimal(n / 16, base);
		cpt += print_char(base[n % 16]);
	}
	else
		cpt += print_char(base[n]);
	return (cpt);
}

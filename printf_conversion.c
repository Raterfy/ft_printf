/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:06:35 by robhak            #+#    #+#             */
/*   Updated: 2023/05/16 17:13:07 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_c(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putchar(va_arg(args, int));
	return (cpt);
}

int	print_s(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putstr(va_arg(args, char *));
	return (cpt);
}

int	print_p(va_list args)
{
	int		cpt;
	void	*ptr;

	cpt = 0;
	ptr = va_arg(args, void *);
	if (ptr == NULL)
		cpt += ft_putstr("(nil)");
	else
	{
		cpt += ft_putstr("0x");
		cpt += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	}
	return (cpt);
}

int	print_d_and_i(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putnbr(va_arg(args, int));
	return (cpt);
}

int	print_u(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_unsigned_nbr(va_arg(args, unsigned int));
	return (cpt);
}

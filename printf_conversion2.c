/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:07:15 by robhak            #+#    #+#             */
/*   Updated: 2023/05/16 16:19:48 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_x(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putnbr_base(va_arg(args, unsigned int),
			"0123456789abcdef");
	return (cpt);
}

int	print_upper_x(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putnbr_base(va_arg(args, unsigned int),
			"0123456789ABCDEF");
	return (cpt);
}

int	print_percent(void)
{
	return (ft_putchar('%'));
}

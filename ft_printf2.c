/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:34:42 by robhak            #+#    #+#             */
/*   Updated: 2023/05/15 16:05:41 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_function.h"

//printf de null renvoie -1

int	print_format(const char *format, va_list args)
{
	int	i;
	int cpt;

	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				cpt += print_char(va_arg(args, int));
			else if (format[i] == 's')
				cpt += print_str(va_arg(args, char *));
			else if (format[i] == 'p')
				cpt += print_pointer(va_arg(args, void *));
			else if (format[i] == 'd' || format[i] == 'i')
				cpt += print_decimal(va_arg(args, int));
			else if (format[i] == 'u')
				cpt += print_unsigned_decimal(va_arg(args, unsigned int));
			else if (format[i] == 'x')
				cpt += print_hexadecimal(va_arg(args, unsigned int), "01233456789abcdef");
			else if (format[i] == 'X')
				cpt += print_hexadecimal(va_arg(args, unsigned int), "01233456789ABCDEF");
			else if (format[i] == '%')
				cpt += print_char('%');
		}
		else
			cpt += print_char(format[i]);
		i++;
	}
	return (cpt);
}

int	ft_printf(const char *format, ...);
{
	int	cpt;

	va_list args;
	va_start(args, format);
	if (!format)
		return (-1);
	cpt = 0;
	cpt += print_format(format, args);
	va_end(args);
	return (cpt);
}
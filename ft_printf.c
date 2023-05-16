/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:45:42 by robhak            #+#    #+#             */
/*   Updated: 2023/05/16 18:09:35 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_format2(const char format, va_list args)
{
	if (format == 'c')
		return (print_c(args));
	else if (format == 's')
		return (print_s(args));
	else if (format == 'p')
		return (print_p(args));
	else if (format == 'd' || format == 'i')
		return (print_d_and_i(args));
	else if (format == 'u')
		return (print_u(args));
	else if (format == 'x')
		return (print_x(args));
	else if (format == 'X')
		return (print_upper_x(args));
	else if (format == '%')
		return (print_percent());
	return (0);
}

//printf de null renvoie -1

int	print_format(const char *format, va_list args)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			cpt += print_format2(format[i], args);
		}
		else
			cpt += ft_putchar(format[i]);
		i++;
	}
	return (cpt);
}

int	ft_printf(const char *format, ...)
{
	int		cpt;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	cpt = 0;
	cpt += print_format(format, args);
	va_end(args);
	return (cpt);
}

// int main()
// {
// 	char c = 'A';
// 	char *str = "Hey";
// 	int num = -42;
// 	unsigned int unsignedNum = 12345;
// 	void *ptr = &num;
// 	char *n = NULL;

// 	ft_printf("=== Testing ft_printf ===\n");
// 	ft_printf("%%c: %c\n", c);
// 	ft_printf("%%s: %s\n", str);
// 	ft_printf("%%p: %p\n", ptr);
// 	ft_printf("%%d: %d\n", num);
// 	ft_printf("%%i: %i\n", num);
// 	ft_printf("%%u: %u\n", unsignedNum);
// 	ft_printf("%%x: %x\n", unsignedNum);
// 	ft_printf("%%X: %X\n", unsignedNum);
// 	ft_printf("%%%%: %%\n");
// 	ft_printf("NULL%sNULL\n", n);

// 	printf("=== Testing printf ===\n");
// 	printf("%%c: %c\n", c);
// 	printf("%%s: %s\n", str);
// 	printf("%%p: %p\n", ptr);
// 	printf("%%d: %d\n", num);
// 	printf("%%i: %i\n", num);
// 	printf("%%u: %u\n", unsignedNum);
// 	printf("%%x: %x\n", unsignedNum);
// 	printf("%%X: %X\n", unsignedNum);
// 	printf("%%%%: %%\n");
// 	printf("NULL%sNULL\n", n);

// 	return (0);
// }

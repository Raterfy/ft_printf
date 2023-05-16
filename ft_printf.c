/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:45:42 by robhak            #+#    #+#             */
/*   Updated: 2023/05/16 16:42:35 by robhak           ###   ########.fr       */
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

	va_start(args, format);
	if (!format)
		return (-1);
	cpt = 0;
	cpt += print_format(format, args);
	va_end(args);
	return (cpt);
}

int	main(void)
{
	printf(NULL);
	ft_printf(NULL);
	
	// char c = 'c';
	// char str[] = "je mange";
	// int num = 42;
    // int *ptr = &num;
	// int d = -100;
	// int i = 92013;
	// unsigned int x = 42;
	// unsigned int X = 255;

	// printf("_______%%c_______\n");
	// printf("Expected: %c\n", c);
	// ft_printf("%c\n", c);

	// printf("_______%%s_______\n");
	// printf("Expected: %s\n", str);
	// ft_printf("%s\n", str);

    // printf("_______%%p_______\n");
    // printf("Expected: %p\n", ptr);
	// ft_printf("%p\n", ptr);

	// printf("_______%%d_______\n");
	// printf("Expected: %d\n", d);
	// ft_printf("%d\n", d);

	// printf("_______%%i_______\n");
	// printf("Expected: %i\n", i);
	// ft_printf("%i\n", i);

	// printf("_______%%x_______\n");
	// printf("Expected: %x\n", x);
	// ft_printf("%x\n", x);

	// printf("_______%%X_______\n");
	// printf("Expected: %X\n", X);
	// ft_printf("%X\n", X);

	// printf("_______%%%%_______\n");
	// printf("Expected: %%\n");
	// ft_printf("%%\n");

	return 0;
}

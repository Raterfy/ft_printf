/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:34:42 by robhak            #+#    #+#             */
/*   Updated: 2023/05/15 23:35:30 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_function.h"

int	print_format2(const char format, va_list args)
{
	int	cpt;

	cpt = 0;
	if (format == 'c')
		cpt += print_char(va_arg(args, int));
	else if (format == 's')
		cpt += print_str(va_arg(args, char *));
	else if (format == 'p')
	{
		cpt += print_str("0x");
		cpt += ft_putnbr_base((unsigned long)va_arg(args, void *),
				"0123456789abcdef");
	}
	else if (format == 'd' || format == 'i')
		cpt += print_decimal(va_arg(args, int));
	else if (format == 'u')
		cpt += print_unsigned_decimal(va_arg(args, unsigned int));
	else if (format == 'x')
		cpt += print_hexadecimal(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (format == 'X')
		cpt += print_hexadecimal(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (format == '%')
		cpt += print_char('%');
	return (cpt);
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
			cpt += print_char(format[i]);
		i++;
	}
	return (cpt);
}

int	ft_printf(const char *format, ...)
{
	int		cpt;
	va_list args;

	va_start(args, format);
	if (!format)
		return (-1);
	cpt = 0;
	cpt += print_format(format, args);
	va_end(args);
	return (cpt);
}


int main(void)
{
	char c = 'c';
	char str[] = "je mange";
	int num = 42;
    int *ptr = &num;
	int d = -100;
	int i = 92013;
	unsigned int x = 42;
	unsigned int X = 255;

	printf("_______%%c_______\n");
	printf("Expected: %c\n", c);
	printf("Actual:   ");
	ft_printf("%c\n", c);

	printf("_______%%s_______\n");
	printf("Expected: %s\n", str);
	printf("Actual:   ");
	ft_printf("%s\n", str);

  
 	ft_printf("%p\n", ptr);
    printf("_______%%p_______\n");
    printf("Expected: %p\n", ptr);
    printf("Actual (ft_printf):     ");
   
    printf("Actual (printf):        ");
    printf("%p\n", ptr);

	printf("_______%%d_______\n");
	printf("Expected: %d\n", d);
	printf("Actual:   ");
	ft_printf("%d\n", d);

	printf("_______%%i_______\n");
	printf("Expected: %i\n", i);
	printf("Actual:   ");
	ft_printf("%i\n", i);

	printf("_______%%x_______\n");
	printf("Expected: %x\n", x);
	printf("Actual:   ");
	ft_printf("%x\n", x);

	printf("_______%%X_______\n");
	printf("Expected: %X\n", X);
	printf("Actual:   ");
	ft_printf("%X\n", X);

	printf("_______%%%%_______\n");
	printf("Expected: %%\n");
	printf("Actual:   ");
	ft_printf("%%\n");

	return 0;
}

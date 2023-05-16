/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:45:42 by robhak            #+#    #+#             */
/*   Updated: 2023/05/16 14:55:13 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i])
		cpt += ft_putchar(str[i++]);
	return (cpt);
}

int	ft_putnbr(int n)
{
	long long int nbr;
	int cpt;

	cpt = 0;
	nbr = (long long int)n;
	if (nbr < 0)
	{
		nbr = -nbr;
		write (1, "-", 1);
		cpt++;
	}
	if (nbr && nbr > 9)
		cpt += ft_putnbr(nbr / 10);
	cpt += ft_putchar (nbr % 10 + '0');
	return (cpt);
}

int	ft_unsigned_nbr(unsigned long long int n)
{
	int cpt;

	cpt = 0;
	if (n && n > 9)
		cpt += ft_putnbr(n / 10);
	cpt += ft_putchar (n % 10 + '0');
	return (cpt);
}

int	ft_putnbr_base(unsigned long long int n, char *base)
{
	int cpt;

	cpt = 0;
	if (n >= 16)
	{
		cpt += ft_putnbr_base(n / 16, base);
		cpt += ft_putchar(base[n % 16]);
	}
	else
		cpt += ft_putchar(base[n]);
	return (cpt);
}

int	print_c(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putchar(va_arg(args, int));
	return (cpt);
}

int	print_s(va_list args)
{
    int cpt;

	cpt = 0;
    cpt += ft_putstr(va_arg(args, char *));
    return (cpt);
}

int	print_p(va_list args)
{
    int cpt;

	cpt = 0;
    cpt += ft_putstr("0x");
    cpt += ft_putnbr_base((unsigned long)va_arg(args, void *),
			"0123456789abcdef");
    return (cpt);
}

int print_d_and_i(va_list args)
{
	int cpt;

	cpt = 0;
    cpt += ft_putnbr(va_arg(args, int));
    return (cpt);
}

int print_u(va_list args)
{
	int cpt;

	cpt = 0;
	cpt += ft_unsigned_nbr(va_arg(args, unsigned int));
    return (cpt);
}

int print_x(va_list args)
{
    int cpt;

	cpt = 0;
    cpt += ft_putnbr_base(va_arg(args, unsigned int),
		"0123456789abcdef");
    return (cpt);
}

int print_X(va_list args)
{
    int	cpt;

	cpt = 0;
    cpt += ft_putnbr_base(va_arg(args, unsigned int),
		"0123456789ABCDEF");
    return (cpt);
}

int print_percent(va_list args)
{
    int cpt;

	cpt = 0;
    cpt += ft_putchar('%');
    return (cpt);
}

int	print_format2(const char format, va_list args)
{
    int	cpt;

	cpt = 0;
	if (format == 'c')
		cpt += print_c(args);
	else if (format == 's')
		cpt += print_s(args);
	else if (format == 'p')
		cpt += print_p(args);
	else if (format == 'd' || format == 'i')
		cpt += print_d_and_i(args);
	else if (format == 'u')
		cpt += print_u(args);
	else if (format == 'x')
		cpt += print_x(args);
	else if (format == 'X')
		cpt += print_X(args);
	else if (format == '%')
		cpt += print_percent(args);

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
			cpt += ft_putchar(format[i]);
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
	ft_printf("%c\n", c);

	printf("_______%%s_______\n");
	printf("Expected: %s\n", str);
	ft_printf("%s\n", str);

    printf("_______%%p_______\n");
    printf("Expected: %p\n", ptr);
	ft_printf("%p\n", ptr);

	printf("_______%%d_______\n");
	printf("Expected: %d\n", d);
	ft_printf("%d\n", d);

	printf("_______%%i_______\n");
	printf("Expected: %i\n", i);
	ft_printf("%i\n", i);

	printf("_______%%x_______\n");
	printf("Expected: %x\n", x);
	ft_printf("%x\n", x);

	printf("_______%%X_______\n");
	printf("Expected: %X\n", X);
	ft_printf("%X\n", X);

	printf("_______%%%%_______\n");
	printf("Expected: %%\n");
	ft_printf("%%\n");

	return 0;
}

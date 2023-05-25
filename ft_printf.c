/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:45:42 by robhak            #+#    #+#             */
/*   Updated: 2023/05/25 13:05:18 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * print_format2 - Appelle la fonction d'impression appropriée 
 * en fonction du caractère  de format spécifié.
 * @format: Le caractère de format spécifiant le type d'argument à imprimer.
 * @args: La liste d'arguments contenant l'argument à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
int	print_format(const char format, va_list args)
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

/*
 * ft_printf - Imprime des arguments formatés à l'écran.
 * @format: La chaîne de format spécifiant les types d'arguments à imprimer.
 * @...: Les arguments à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
int	ft_printf(const char *format, ...)
{
	int		cpt;
	int		i;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	cpt = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			cpt += print_format(format[i], args);
		}
		else
			cpt += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (cpt);
}

// printf de null renvoie -1
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
// 	ft_printf("je mange\n");
// 	ft_printf("%d\n", ft_printf(NULL));
// 	ft_printf("%x\n",9223372036854775807LL);

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
// 	printf("je mange\n");
// 	printf("%d\n",printf(NULL));
// 	printf("%llx\n",9223372036854775807LL);

// 	return (0);
// }

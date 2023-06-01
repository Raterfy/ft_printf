/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:45:42 by robhak            #+#    #+#             */
/*   Updated: 2023/06/01 11:53:53 by robhak           ###   ########.fr       */
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
size_t	print_format(const char format, va_list args)
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

// int main()
// {
// 	char c = 'A';
// 	char *str = "Hey";
// 	int num = -42;
// 	int num2 = 42;
// 	int min = -2147483648;
// 	int max = 2147483647;
// 	unsigned int unsignedNum = 12345;
// 	unsigned int unsignedNum2 = -12345;
// 	void *ptr = &num;
// 	char *n = NULL;
// 	void *ptr2 = NULL;

// 	ft_printf("=== Testing ft_printf ===\n");
// 	ft_printf("%%c: %c\n", c);
// 	ft_printf("%%s: %s\n", str);
// 	ft_printf("je mange\n");
// 	ft_printf("%%p: %p\n", ptr);
// 	ft_printf("%%p: %p\n", ptr2);
// 	ft_printf("%%d: %d\n", num);
// 	ft_printf("%%d: %d\n", num2);
// 	ft_printf("%%d: %d\n", min);
// 	ft_printf("%%d: %d\n", max);
// 	ft_printf("%%i: %i\n", num);
// 	ft_printf("%%i: %i\n", num2);
// 	ft_printf("%%i: %i\n", min);
// 	ft_printf("%%i: %i\n", max);
// 	ft_printf("%%u: %u\n", unsignedNum);
// 	ft_printf("%%u: %u\n", unsignedNum2);
// 	ft_printf("%%x: %x\n", unsignedNum);
// 	ft_printf("%%x: %x\n", unsignedNum2);
// 	ft_printf("%%X: %X\n", unsignedNum);
// 	ft_printf("%%X: %X\n", unsignedNum2);
// 	ft_printf("%%%%: %%\n");
// 	ft_printf("NULL%sNULL\n", n);
// 	ft_printf("%d\n", ft_printf(NULL));

// 	printf("=== Testing printf ===\n");
// 	printf("%%c: %c\n", c);
// 	printf("%%s: %s\n", str);
// 	printf("%%p: %p\n", ptr);
// 	printf("%%p: %p\n", ptr2);
// 	printf("%%d: %d\n", num);
// 	printf("%%d: %d\n", num2);
// 	printf("%%d: %d\n", min);
// 	printf("%%d: %d\n", max);
// 	printf("%%i: %i\n", num);
// 	printf("%%i: %i\n", num2);
// 	printf("%%i: %i\n", min);
// 	printf("%%i: %i\n", max);
// 	printf("%%u: %u\n", unsignedNum);
// 	printf("%%u: %u\n", unsignedNum2);
// 	printf("%%x: %x\n", unsignedNum);
// 	printf("%%x: %x\n", unsignedNum2);
// 	printf("%%X: %X\n", unsignedNum);
// 	printf("%%X: %X\n", unsignedNum2);
// 	printf("%%%%: %%\n");
// 	printf("NULL%sNULL\n", n);
// 	printf("%d\n",printf(NULL));
// 	printf("je mange\n");

// 	return (0);
// }

// Elliot main
// #include "ft_printf.h"
// #include <limits.h>
// #include <stdarg.h>
// #include <stdio.h>
// #include <stdlib.h>
// #define RESET "\x1B[0m"
// #define RED "\x1B[31m"
// #define GREEN "\x1B[32m"
// #define YELLOW "\x1B[33m"
// #define BLUE "\x1B[34m"
// #define MAGENTA "\x1B[35m"
// #define CYAN "\x1B[36m"
// #define WHITE "\x1B[37m"

// int main(void)
// {
// 	char *s;
// 	void *ptr;
// 	void *nullptr;

// 	s = NULL;
// 	ptr = &s;
// 	nullptr = NULL;

// 	// dumb check
// 	printf("Idiot check NULL\n");
// 	// printf("printf_ret p=%d\n", printf(NULL));
// 	printf("ft_printf_ret p=%d\n", ft_printf(NULL));

// 	// c
// 	printf("PRINTING percent c\n");
// 	printf("printf_ret p=%d\n", printf("%c ", 0));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%c ", 0));
// 	printf("printf_ret p=%d\n", printf("%c ", 'b'));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%c ", 'b'));
// 	printf("============================================================================\n");
// 	// s
// 	printf("PRINTING percent s\n");
// 	printf("printf_ret p=%d\n", printf("%s ", "string1"));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%s ", "string1"));
// 	printf("printf_ret p=%d\n", printf("%s ", nullptr));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%s ", nullptr));
// 	printf("printf_ret p=%d\n", printf("%s ", "😀😀😀😀"));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%s ", "😀😀😀😀"));
// 	printf("printf_ret p=%d\n", printf("%s ",
// 									   "QWLEKLQWJJELQWKEQWLEKLQWJJELQWKEQWLEKLQWJJELQWKEQWLEKLQWJJELQWKEQWLEKLQWJJELQWKEQWLEKLQWJJELQWKE"));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%s ",
// 											 "QWLEKLQWJJELQWKEQWLEKLQWJJELQWKEQWLEKLQWJJELQWKEQWLEKLQWJJELQWKEQWLEKLQWJJELQWKEQWLEKLQWJJELQWKE"));
// 	printf("============================================================================\n");
// 	// p
// 	printf("PRINTING percent p\n");
// 	printf("printf_ret p=%d\n", printf("%p ", ptr));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%p ", ptr));
// 	printf("printf_ret p=%d\n", printf("%p ", nullptr));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%p ", nullptr));
// 	printf("printf_ret p=%d\n", printf("%p ", NULL));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%p ", NULL));
// 	printf("printf_ret p=%d\n", printf("%p ", (void *)16));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%p ", (void *)16));
// 	printf("printf_ret p=%d\n", printf("%p ", (void *)LONG_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%p ", (void *)LONG_MIN));
// 	printf("============================================================================\n");
// 	// d
// 	printf("PRINTING percent d\n");
// 	printf("printf_ret p=%d\n", printf("%d ", 42));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", 42));
// 	printf("printf_ret p=%d\n", printf("%d ", -42));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", -42));
// 	printf("printf_ret p=%d\n", printf("%d ", INT_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", INT_MAX));
// 	printf("printf_ret p=%d\n", printf("%d ", INT_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", INT_MIN));
// 	printf("printf_ret p=%d\n", printf("%d ", -1));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", -1));
// 	printf("printf_ret p=%d\n", printf("%d ", 0));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", 0));
// 		printf("printf_ret p=%d\n", printf("%d ", NULL));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", NULL));
// 	printf("printf_ret p=%d\n", printf("%d ", LONG_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", LONG_MAX));
// 	printf("printf_ret p=%d\n", printf("%d ", LONG_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", LONG_MIN));
// 	printf("printf_ret p=%d\n", printf("%d ", UINT_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", UINT_MAX));
// 	printf("printf_ret p=%d\n", printf("%d ", ULONG_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%d ", ULONG_MAX));
// 	printf("============================================================================\n");
// 	// i
// 	printf("PRINTING percent i\n");
// 	printf("printf_ret p=%d\n", printf("%i ", 42));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", 42));
// 	printf("printf_ret p=%d\n", printf("%i ", -42));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", -42));
// 	printf("printf_ret p=%d\n", printf("%i ", INT_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", INT_MAX));
// 	printf("printf_ret p=%d\n", printf("%i ", INT_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", INT_MIN));
// 	printf("printf_ret p=%d\n", printf("%i ", -1));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", -1));
// 	printf("printf_ret p=%d\n", printf("%i ", 0));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", 0));
// 		printf("printf_ret p=%d\n", printf("%i ", NULL));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", NULL));
// 	printf("printf_ret p=%d\n", printf("%i ", LONG_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", LONG_MAX));
// 	printf("printf_ret p=%d\n", printf("%i ", LONG_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", LONG_MIN));
// 	printf("printf_ret p=%d\n", printf("%i ", UINT_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", UINT_MAX));
// 	printf("printf_ret p=%d\n", printf("%i ", ULONG_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%i ", ULONG_MAX));
// 	printf("============================================================================\n");
// 	// x
// 	printf("PRINTING percent x\n");
// 	printf("printf_ret p=%d\n", printf("%x ", 42));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", 42));
// 	printf("printf_ret p=%d\n", printf("%x ", -42));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", -42));
// 	printf("printf_ret p=%d\n", printf("%x ", INT_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", INT_MAX));
// 	printf("printf_ret p=%d\n", printf("%x ", INT_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", INT_MIN));
// 	printf("printf_ret p=%d\n", printf("%x ", -1));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", -1));
// 	printf("printf_ret p=%d\n", printf("%x ", 0));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", 0));
// 		printf("printf_ret p=%d\n", printf("%x ", NULL));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", NULL));
// 	printf("printf_ret p=%d\n", printf("%x ", LONG_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", LONG_MAX));
// 	printf("printf_ret p=%d\n", printf("%x ", LONG_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", LONG_MIN));
// 	printf("printf_ret p=%d\n", printf("%x ", UINT_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", UINT_MAX));
// 	printf("printf_ret p=%d\n", printf("%x ", ULONG_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%x ", ULONG_MAX));
// 	printf("============================================================================\n");
// 	// X
// 	printf("PRINTING percent X\n");
// 	printf("printf_ret p=%d\n", printf("%X ", 42));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", 42));
// 	printf("printf_ret p=%d\n", printf("%X ", -42));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", -42));
// 	printf("printf_ret p=%d\n", printf("%X ", INT_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", INT_MAX));
// 	printf("printf_ret p=%d\n", printf("%X ", INT_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", INT_MIN));
// 	printf("printf_ret p=%d\n", printf("%X ", -1));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", -1));
// 	printf("printf_ret p=%d\n", printf("%X ", 0));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", 0));
// 		printf("printf_ret p=%d\n", printf("%X ", NULL));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", NULL));
// 	printf("printf_ret p=%d\n", printf("%X ", LONG_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", LONG_MAX));
// 	printf("printf_ret p=%d\n", printf("%X ", LONG_MIN));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", LONG_MIN));
// 	printf("printf_ret p=%d\n", printf("%X ", UINT_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", UINT_MAX));
// 	printf("printf_ret p=%d\n", printf("%X ", ULONG_MAX));
// 	printf("ft_printf_ret p=%d\n", ft_printf("%X ", ULONG_MAX));
// 	printf("============================================================================\n");
// 	return (0);
// }

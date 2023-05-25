/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:07:15 by robhak            #+#    #+#             */
/*   Updated: 2023/05/25 13:05:47 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * print_x - Imprime un entier non signé en base 16 (minuscules) 
 * passé en argument.
 * @args: La liste d'arguments contenant l'entier non signé à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
int	print_x(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putnbr_base(va_arg(args, unsigned int),
			"0123456789abcdef");
	return (cpt);
}

/*
 * print_upper_x - Imprime un entier non signé en base 16 (majuscules) 
 * passé en argument.
 * @args: La liste d'arguments contenant l'entier non signé à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
int	print_upper_x(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putnbr_base(va_arg(args, unsigned int),
			"0123456789ABCDEF");
	return (cpt);
}

/*
 * print_percent - Imprime le caractère '%'.
 *
 * Retourne: Le nombre de caractères imprimés (toujours 1).
 */
int	print_percent(void)
{
	return (ft_putchar('%'));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:34:42 by robhak            #+#    #+#             */
/*   Updated: 2023/05/15 15:20:29 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_function.h"

int	print_format(const char *format, va_list args)
{
	int	i;
	int cpt;

	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
		}
	}
}

int	ft_printf(const char *format, ...);
{
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:26:43 by robhak            #+#    #+#             */
/*   Updated: 2023/05/05 18:20:09 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<printf_function.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		ft_putchar(str[i++]);
	return(i);
}

int	ft_putnbr(int n)
{
	int count;
	if (n < 0)
	{
		
	}
}
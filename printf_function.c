/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:26:43 by robhak            #+#    #+#             */
/*   Updated: 2023/05/05 18:30:53 by robhak           ###   ########.fr       */
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
	int cpt;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		cpt++;
	}
	if (n && n >= 10)
		cpt += ft_putnbr(n % 10);
	ft_putchar(n % 10 + '0');
	cpt++;
	return(cpt);
}

int ft_putnbr_base(unsigned int n, char *base)
{
	int cpt = 0;
	int base_len = 0;

	cpt = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= (unsigned int)base_len)
		cpt += ft_putnbr_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
	cpt++;
	return cpt;
}

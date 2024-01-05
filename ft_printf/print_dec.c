/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:19:08 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/24 16:10:11 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(int nbr)
{
	long	nb;
	char	s;
	int		counter;

	nb = nbr;
	counter = 0;
	if (nb < 0)
	{
		counter += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		counter += print_dec(nb / 10);
		counter += print_dec(nb % 10);
	}
	if (nb <= 9)
	{
		s = nb + '0';
		counter += write(1, &s, 1);
	}
	return (counter);
}

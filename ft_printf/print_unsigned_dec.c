/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:16:35 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/22 20:16:31 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_dec(unsigned int nbr)
{
	int		counter;
	char	s;

	counter = 0;
	if (nbr > 9)
	{
		counter += print_unsigned_dec(nbr / 10);
		counter += print_unsigned_dec(nbr % 10);
	}
	if (nbr <= 9)
	{
		s = nbr + '0';
		counter += write(1, &s, 1);
	}
	return (counter);
}

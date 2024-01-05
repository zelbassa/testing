/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_uc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:47:06 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/22 19:14:18 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_uc(int nb)
{
	int				counter;
	unsigned int	nbr;
	char			*hex_arr;

	counter = 0;
	hex_arr = "0123456789ABCDEF";
	nbr = (unsigned int)nb;
	if (nbr >= 16)
		counter += print_hex_uc(nbr / 16);
	counter += write(1, &hex_arr[nbr % 16], 1);
	return (counter);
}

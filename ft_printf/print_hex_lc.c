/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:46:23 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/22 19:12:03 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_lc(int nb)
{
	int				counter;
	unsigned int	nbr;
	char			*hex_arr;

	counter = 0;
	hex_arr = "0123456789abcdef";
	nbr = (unsigned int)nb;
	if (nbr >= 16)
		counter += print_hex_lc(nbr / 16);
	counter += write(1, &hex_arr[nbr % 16], 1);
	return (counter);
}

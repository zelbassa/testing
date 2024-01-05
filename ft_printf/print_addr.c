/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:22:30 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/27 17:01:08 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_address_hex(unsigned long long nbr)
{
	int		counter;
	char	*hex_arr;

	counter = 0;
	hex_arr = "0123456789abcdef";
	if (nbr >= 16)
		counter += print_address_hex(nbr / 16);
	counter += write(1, &hex_arr[nbr % 16], 1);
	return (counter);
}

int	print_addr(void *ptr)
{
	int		counter;

	counter = 0;
	if (ptr == 0)
	{
		counter += write(1, "0x0", 3);
		return (counter);
	}
	counter += write(1, "0x", 2);
	counter += print_address_hex((unsigned long long)ptr);
	return (counter);
}

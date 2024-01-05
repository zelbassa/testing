/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:40:04 by zelbassa          #+#    #+#             */
/*   Updated: 2023/12/28 19:27:22 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(const char *str, va_list ptr)
{
	int	counter;

	counter = 0;
	if (*str == 'c')
		counter += print_char(va_arg(ptr, int));
	if (*str == 's')
		counter += print_str(va_arg(ptr, char *));
	if (*str == 'd' || *str == 'i')
		counter += print_dec(va_arg(ptr, int));
	if (*str == 'u')
		counter += print_unsigned_dec(va_arg(ptr, unsigned int));
	if (*str == 'x')
		counter += print_hex_lc(va_arg(ptr, unsigned int));
	if (*str == 'X')
		counter += print_hex_uc(va_arg(ptr, unsigned int));
	if (*str == 'p')
		counter += print_addr(va_arg(ptr, void *));
	if (*str == '%')
		counter += print_percent();
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		counter;

	counter = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) != '\0')
			{
				counter += handle_specifier(str + 1, ptr);
				str ++;
			}
			str += 1;
		}
		else
			counter += print_char(*str++);
	}
	va_end(ptr);
	return (counter);
}

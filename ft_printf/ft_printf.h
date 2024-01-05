/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:46:13 by zelbassa          #+#    #+#             */
/*   Updated: 2023/11/24 16:09:53 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_dec(int n);
int	print_percent(void);
int	print_unsigned_dec(unsigned int n);
int	print_addr(void *ptr);
int	print_hex_lc(int n);
int	print_hex_uc(int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:21:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/05 22:33:28 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**fill_arguments(char **av, int ac)
{
	char	**stack;
	char	**tokens;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		while (tokens[j])
			j++;
		free(tokens);
		i ++;
	}
	stack = malloc(sizeof(char *) * (j + 1));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (tokens)
		{
			j = 0;
			while (tokens[j])
			{
				stack[j] = strdup(tokens[j]);
				free(tokens[j]);
				j++;
			}
			free(tokens);
		}
		i ++;
	}
	stack[j] = NULL;
	return (stack);
}

int	main(int ac, char **av)
{
	int		i;
	char	**stack;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack = fill_arguments(av, ac);
	i = 0;
	while (stack[i])
	{
		ft_printf("%s\n", (*stack)[i]);
		i ++;
	}
	i = 0;
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
	return (0);
}
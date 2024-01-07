/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:21:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/07 11:56:48 by zelbassa         ###   ########.fr       */
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

int	within_range(const char *str)
{
	const char	*int_max = "2147483647";
	const char	*int_min = "-2147483648";
	
	if (*str == '-')
	{
		if ((ft_strlen(str) >= ft_strlen(int_min)) && ft_strcmp(str, int_min) > 0)
			return (0);
	}
	else
	{
		if (ft_strlen(str) >= ft_strlen(int_max) && ft_strcmp(str, int_max) > 0)
			return (0);
	}
	return (1);
}

void	free_stack(int **stack)
{
	free(*stack);
	*stack = NULL;
}

int	fill_single_argument(char **av, int **stack)
{
	int		i;
	char	**tokens;

	i = 0;
	tokens = ft_split(av[1], ' ');
	if (tokens)
	{
		while (tokens[i])
		{
			if (is_int(tokens[i]) && within_range(tokens[i]))
				i++;
			else
				return (0);
		}
	}
	if (i < 2)
		return (0);
	*stack = malloc(sizeof(int) * i);
	if (*stack == NULL)
		return (0);
	i = 0;
	while (tokens[i])
	{
		(*stack)[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (i);
}

void	fill_multiple_arguments(char **av, int ac, int **stack)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	*stack = malloc(sizeof(int) * (ac - 1));
	if (*stack == NULL)
		return ;
	while (j < ac)
	{
		if (is_int(av[j]) && within_range(av[j]))
		{
			(*stack)[i] = ft_atoi(av[j]);
			i++;
		}
		else
		{
			free_stack(stack);
			return ;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	length;
	int	*stack;

	length = ac - 1;
	stack = NULL;
	i = 0;
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ac == 2)
		length = fill_single_argument(av, &stack);
	else
		fill_multiple_arguments(av, ac, &stack);
	if (stack == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	while (i < length)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
	free_stack(&stack);
	return (0);
}

//int	*fill_arguments(char **av)
//{
//	int		i;
//	int		*stack;
//	char	**tokens;
//
//	i = 1;
//	tokens = ft_split(av[1], ' ');
//	if (!tokens)
//		return (0);
//	while(tokens[i])
//	{
//		if (is_int(tokens[i]))
//			i++;
//		else
//		{
//			free(tokens);
//			return (0);
//		}
//	}
//	stack = malloc(sizeof(int) * (i + 1));
//	i = 0;
//	while (tokens[i])
//	{
//		stack[i] = ft_atoi(ft_strdup(tokens[i]));
//		i ++;
//	}
//    if (stack[1] == '\0')
//        return (0);
//	stack[i] = '\0';
//	return (stack);
//}
//
//int	*fill_list(char **av, int ac)
//{
//	int		i;
//	int		*stack;
//
//	stack = malloc(sizeof(int) * ac);
//	i = 0;
//	while (i < ac)
//	{
//		stack[i] = ft_atoi(av[i + 1]);
//		i ++;
//	}
//	stack[i] = 0;
//	return (stack);
//}
//
//int	main(int ac, char **av)
//{
//	int		i;
//	int			*stack;
//
//	stack = NULL;
//	if (ac < 2)
//	{
//		ft_printf("Error\n");
//		return (0);
//	}
//	if (ac == 2)
//		stack = fill_arguments(av);
//	else
//		stack = fill_list(av, ac);
//	if (!stack)
//	{
//		printf("Error\n");
//		return (0);
//	}
//	i = 0;
//	while (stack[i])
//	{
//		ft_printf("%d\n", stack[i]);
//		i ++;
//	}
//	free(stack);
//	return (0);
//}
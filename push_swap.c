/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:21:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/07 21:59:39 by zelbassa         ###   ########.fr       */
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

void	ft_rotate(int **stack, char id, int length)
{
	int	i;
	int	j;

	j = 0;
	i = (*stack)[length - 1];
	while (j < length - 1)
	{
		(*stack)[j + 1] = (*stack)[j];
		j ++;
	}
	(*stack)[j + 1] = i;
	if (id == 'a')
		ft_printf("ra\n");
	else if (id == 'b')
		ft_printf("rb\n");
}

void	ft_swap(int **stack, char id)
{
	int	i;

	i = (*stack)[1];
	(*stack)[1] = (*stack)[0];
	(*stack)[0] = i;
	if (id == 'a')
		ft_printf("sa\n");
	if (id == 'b')
		ft_printf("sb\n");
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

int findClosest(int arr[], int n, int target) {
    int closestNum = arr[0];

    for (int i = 0; i < n; i++) {
        if (abs(target - closestNum) > abs(target - arr[i])) {
            closestNum = arr[i];
        }
    }
    return closestNum;
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
	int mid_point = mid_number(&stack, length);
	printf("MID_POINT: %d", mid_point);
	ft_swap(&stack, 'a');
	ft_rotate(&stack, 'a', length);
	while (i < length)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
	free_stack(&stack);
	return (0);
}

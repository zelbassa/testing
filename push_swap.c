/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:21:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/09 10:29:57 by zelbassa         ###   ########.fr       */
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

void	ft_push_b(int **stack_a, int **stack_b, int len_a, int length)
{
	int	i;
	int	len_b;
	int	a_element;

	i = 0;
	if (!(*stack_a))
		return ;
	a_element = (*stack_a)[0];
	while (i < len_a)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		i++;
	}
	len_b = length - len_a;
	i = 0;
	while (len_b > 0)
	{
		(*stack_b)[len_b] = (*stack_b)[len_b - 1];
		len_b--;
	}
	(*stack_b)[0] = a_element;
	printf("pb\n");
}

void	ft_push_a(int **stack_a, int **stack_b, int len_b, int length)
{
	int	i;
	int	len_a;
	int	b_element;

	i = 0;
	if (!(*stack_b))
		return ;
	b_element = (*stack_b)[0];
	while (i < len_b)
	{
		(*stack_b)[i] = (*stack_b)[i + 1];
		i++;
	}
	len_a = length - len_b;
	i = 0;
	while (len_a > 0)
	{
		(*stack_a)[len_a] = (*stack_a)[len_a - 1];
		len_a--;
	}
	(*stack_a)[0] = b_element;
	printf("pa\n");
}

void	ft_reverse_rotate(int **stack, char id, int length)
{
	int	i;
	int	j;

	i = (*stack)[length - 1];
	j = length - 1;
	while (j > 0)
	{
		(*stack)[j] = (*stack)[j - 1];
		j--;
	}
	(*stack)[0] = i;
	if (id == 'a')
		ft_printf("rra\n");
	else if (id == 'b')
		ft_printf("rrb\n");
}

void	ft_rotate(int **stack, char id, int length)
{
	int	i;
	int	j;

	j = 0;
	i = (*stack)[0];
	while (j < length - 1)
	{
		(*stack)[j] = (*stack)[j + 1];
		j++;
	}
	(*stack)[length - 1] = i;
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
	const char	*int_max;
	const char	*int_min;

	int_max = "2147483647";
	int_min = "-2147483648";
	if (*str == '-')
	{
		if ((ft_strlen(str) >= ft_strlen(int_min)) && ft_strcmp(str,
				int_min) > 0)
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

int	findClosest(int arr[], int n, int target)
{
	int	closestNum;

	closestNum = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (abs(target - closestNum) > abs(target - arr[i]))
		{
			closestNum = arr[i];
		}
	}
	return (closestNum);
}

int	is_sorted(int **stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if ((*stack)[i] < (*stack)[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_sort_three(int **stack_a)
{
	if (((*stack_a)[0] > (*stack_a)[1]) && ((*stack_a)[0] > (*stack_a)[2]))
		ft_rotate(stack_a, 'a', 3);
	else if (((*stack_a)[1] > (*stack_a)[0]) && ((*stack_a)[1] > (*stack_a)[2]))
		ft_reverse_rotate(stack_a, 'a', 3);
	if ((*stack_a)[0] > (*stack_a)[1])
		ft_swap(stack_a, 'a');
	if (is_sorted(stack_a, 3))
		return ;
	else
	{
		ft_printf("Not yet sorted\n");
		ft_sort_three(stack_a);
	}
}

void	ft_push_swap(int *stack, int length)
{
	int	*stack_a;
	int	*stack_b;
/* 	int	len_a;
	int	len_b;

	len_a = length;
	len_b = 0; */
	stack_a = malloc(sizeof(int) * length);
	stack_b = malloc(sizeof(int) * length);
	int i = 0;
	while (i < length)
	{
		stack_a[i] = stack[i];
		i ++;
	}
	i = 0;
	while (i < length)
	{
		stack_b[i] = 0;
		i ++;
	}
	ft_sort_three(&stack_a);
/* 	ft_push_a(stack_a, stack_b, &len_a, &len_b, length); */
/* 	ft_push_b(stack_a, stack_b, &len_a, &len_b, length); */
	if (is_sorted(&stack_a, length))
	{
		printf("Stack is sorted!!");
		free(stack_a);
		free(stack_b);
		exit(1);
	}
/* 	ft_swap(&stack_a, 'a');
	ft_rotate(&stack_a, 'a', 3); */
	for (int i = 0; i < length; i++)
		printf("Stack_a[%d]: %d\n", i, stack_a[i]);
	ft_printf("-------------\n");
	for (int i = 0; i < length; i++)
		printf("Stack_b[%d]: %d\n", i, stack_b[i]);
}

int	has_duplicates(int **stack, int len)
{
	int	i;
	int	j;

	i = 0;
	if (stack == NULL)
		return (1);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*stack)[i] != (*stack)[j])
				j ++;
			else
			{
				printf("STACK HAS DUPLICATE VALUES!!");
				return (1);
			}
		}
		i ++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	//int	i;
	int	length;
	int	*stack;
	//int	mid_point;

	length = ac - 1;
	stack = NULL;
	//i = 0;
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ac == 2)
		length = fill_single_argument(av, &stack);
	else
		fill_multiple_arguments(av, ac, &stack);
	if (stack == NULL || has_duplicates(&stack, length))
	{
		ft_printf("Error\n");
		free_stack(&stack);
		return (0);
	}
	//mid_point = mid_number(&stack, length);
	// ft_push_swap(stack, length);
	free_stack(&stack);
	return (0);
}

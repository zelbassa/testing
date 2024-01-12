/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:21:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/12 23:23:32 by zelbassa         ###   ########.fr       */
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

void	ft_push_b(int **src, int **dest, int *len_src, int *len_dest)
{
	int	i;
	int	j;
	int	placeholder;

	i = 0;
	j = 0;
	if (!(*src))
		return ;
	placeholder = (*src)[0];
	while (i < (*len_src) - 1)
	{
		(*src)[i] = (*src)[i + 1];
		i++;
	}
	j = *len_dest;
	i = 0;
	while (j > 0)
	{
		(*dest)[j] = (*dest)[j - 1];
		j--;
	}
	(*src)[*len_src - 1] = 0;
	(*len_src)--;
	(*len_dest)++;
	(*dest)[0] = placeholder;
	ft_printf("pb\n");
}

void	ft_push_a(int **dest, int **src, int *len_src, int *len_dest)
{
	int	i;
	int	j;
	int	placeholder;

	j = 0;
	i = 0;
	if (!(*src))
		return ;
	placeholder = (*src)[0];
	while (i < (*len_src) - 1)
	{
		(*src)[i] = (*src)[i + 1];
		i++;
	}
	i = 0;
	j = *len_dest;
	while (j > 0)
	{
		(*dest)[j] = (*dest)[j - 1];
		j--;
	}
	(*src)[*len_src - 1] = 0;
	(*len_src)--;
	(*len_dest)++;
	(*dest)[0] = placeholder;
	ft_printf("pa\n");
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

int	is_sorted(int **stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if ((*stack)[i] > (*stack)[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	show_stack(int **stack_a, int **stack_b, int length)
{
	if (stack_a)
	{
		for (int i = 0; i < length; i++)
			ft_printf("Stack_a[%d]: %d\n", i, (*stack_a)[i]);
	}
	if (stack_b)
	{
		ft_printf("-------------\n");
		for (int i = 0; i < length; i++)
			ft_printf("Stack_b[%d]: %d\n", i, (*stack_b)[i]);
	}
}

/* void	sort_three(int **stack)
{
	if ((*stack)[0])
} */

void	sort_b(int *sorted_stack, int **stack_b, int len_b, int length)
{
	if ((*stack_b[0] > sorted_stack[length/3]))
		ft_rotate(stack_b, 'b', len_b);
}

void	divide_elements(int **stack_a, int **stack_b, int length)
{
	int	len_a;
	int	len_b;
	int	i;
	int	*sorted_stack;

	len_a = length;
	len_b = 0;
	i = 0;
	sorted_stack = malloc(sizeof(int) * length);
	sorted_stack = selection_sort(*stack_a, length);
	show_stack(&sorted_stack, NULL, length);
/* 	while (len_a > sorted_stack[length/3])
	{
		if ((*stack_a)[i] > length/3)
			ft_push_b(stack_a, stack_b, &len_a, &len_b);
		else
			ft_rotate(stack_a, 'a', len_a);
	}
	printf("END OF PHASE 1\n----------------\n");
	show_stack(NULL, stack_b, len_b); */
	while (len_a > (length/3) * 2)
	{
		if ((*stack_a)[i] < sorted_stack[length/3])
		{
			ft_push_b(stack_a, stack_b, &len_a, &len_b);
			sort_b(sorted_stack, stack_b, len_b, length);
		}
		else
			ft_rotate(stack_a, 'a', len_a);
	}
	printf("END OF PHASE 1\n----------------\n");
	show_stack(NULL, stack_b, len_b);
	while (len_a > 3)
	{
		if ((*stack_a)[i] > sorted_stack[length/3])
			ft_push_b(stack_a, stack_b, &len_a, &len_b);
		else
			ft_rotate(stack_a, 'a', len_a);
	}
	printf("END OF PHASE 1\n----------------\n");
	show_stack(NULL, stack_b, len_b);
}

/* void	divide_elements(int **stack_a, int **stack_b, int length)
{
	int	len_a;
	int	len_b;

	len_a = length;
	len_b = 0;
	if (!is_sorted(stack_a, len_a))
	{
			while (len_a != 0)
			{
				ft_push_b(stack_a, stack_b, &len_a, &len_b);
			}
			while (len_b > 0)
			{
				if (len_b == 1)
				{
					ft_push_a(stack_a, stack_b, &len_b, &len_a);
					show_stack(stack_a, stack_b, length);
				}
				else
				{
					if ((*stack_b)[0] > (*stack_b)[len_b - 1])
					{
						ft_reverse_rotate(stack_b, 'b', len_b);
						ft_push_a(stack_a, stack_b, &len_b, &len_a);
					}
					else
					{
						ft_push_a(stack_a, stack_b, &len_b, &len_a);
						ft_reverse_rotate(stack_b, 'b', len_b);
					}
					ft_push_a(stack_a, stack_b, &len_b, &len_a);
				}
			}
	}
	merge_sort(stack_a, stack_b, &len_a, &len_b);
	printf("--------------------\n");
	show_stack(stack_a, stack_b, length);
} */

/* void	ft_sort(int **stack_a, int **stack_b, int length)
{
	int	mid_point;
	int	len_a;
	int	len_b;
	int	i;

	len_a = length;
	len_b = 0;
	if (is_sorted(stack_a, len_a) && len_a == length)
		exit(1);
	mid_point = mid_number(stack_a, length);
	i = 0;
} */

void	ft_push_swap(int *stack, int length)
{
	int	*stack_a;
	int	*stack_b;
	int	i;

	stack_a = malloc(sizeof(int) * length);
	stack_b = malloc(sizeof(int) * length);
	i = 0;
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
	if (is_sorted(&stack_a, length))
	{
		free(stack_a);
		free(stack_b);
		exit(1);
	}
	else
		divide_elements(&stack_a, &stack_b, length);
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
				return (1);
		}
		i ++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	length;
	int	*stack;

	length = ac - 1;
	stack = NULL;
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
	ft_push_swap(stack, length);
	// show_stack(stack, NULL, length);
	free_stack(&stack);
	return (0);
}

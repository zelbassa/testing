/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:21:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/20 13:00:05 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	treat_output(char **cmd)
{
	if (cmd[0] && cmd[1] && strncmp(cmd[0], cmd[1], 1) == 0 
	&& cmd[0][0] != 'p')
	{
		if ((strcmp(cmd[0], "sa") == 0) && (ft_strcmp(cmd[1], "sb") == 0))
			ft_printf("ss\n");
		else if ((ft_strcmp(cmd[0], "rra") == 0) && (ft_strcmp(cmd[1], "rrb") == 0))
			ft_printf("rrr\n");
		else if ((ft_strcmp(cmd[0], "ra") == 0) && (ft_strcmp(cmd[1], "rb") == 0))
			ft_printf("rr\n");

		free(cmd[0]);
		free(cmd[1]);
		cmd[0] = NULL;
		cmd[1] = NULL;
	}
	else
	{
		if (cmd[0])
		{
			ft_printf("%s\n", cmd[0]);
			free(cmd[0]);
			cmd[0] = cmd[1];
			cmd[1] = NULL;
		}
	}
}

void	process_remaining_commands(char **cmd)
{
	if (cmd[0])
	{
		ft_printf("%s\n", cmd[0]);
		free(cmd[0]);
		cmd[0] = NULL;
	}
}

void	command_stack(char *new_cmd)
{
	static char	*cmd[2] = {NULL, NULL};

	if (new_cmd == NULL)
	{
		process_remaining_commands(cmd);
		return;
	}

	if (cmd[0] == NULL)
		cmd[0] = ft_strdup(new_cmd);
	else if (cmd[1] == NULL)
		cmd[1] = ft_strdup(new_cmd);
	else
	{
		treat_output(cmd);
		cmd[1] = ft_strdup(new_cmd);
	}
} */

int		is_int(const char *str)
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
	// command_stack("pb");
}

void	ft_push_a(int **dest, int **src, int *len_src, int *len_dest)
{
	int	i;
	int	j;
	int	placeholder;

	j = 0;
	i = 0;
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
	// command_stack("pa");
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
	{
		ft_printf("rra\n");
		// command_stack("rra");
	}
	else if (id == 'b')
	{
		ft_printf("rrb\n");
		// command_stack("rrb");
	}
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
	{
		ft_printf("ra\n");
		// command_stack("ra");
	}
	else if (id == 'b')
	{
		ft_printf("rb\n");
		// command_stack("rb");
	}
}

void	ft_swap(int **stack, char id)
{
	int	i;

	i = (*stack)[1];
	(*stack)[1] = (*stack)[0];
	(*stack)[0] = i;
	if (id == 'a')
	{
		ft_printf("sa\n");
		// command_stack("sa");
	}
	if (id == 'b')
	{
		ft_printf("sb\n");
		// command_stack("sb");	
	}
}

int		within_range(const char *str)
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

int		fill_single_argument(char **av, int **stack)
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

int		is_sorted(int **stack, int len)
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

int		find_min(int **stack, int len)
{
	int	i;
	int	k;
	int	min_value;

	i = 0;
	k = 1;
	min_value = 0;
	while (i < len - 1 && k + i < len)
	{
		if ((*stack)[i] < (*stack)[i + k])
			k ++;
		else
		{
			i = k;
			k ++;
		}
		min_value = i;
	}
	return (min_value);
}

void	ft_sort_three(int **stack, char id)
{
	if (((*stack)[0] > (*stack)[1]) && ((*stack)[0] > (*stack)[2]))
		ft_rotate(stack, id, 3);
	if (((*stack)[1] > (*stack)[0]) && ((*stack)[1] > (*stack)[2]))
		ft_reverse_rotate(stack, id, 3);
	if ((*stack)[0] > (*stack)[1])
		ft_swap(stack, id);
}

void	ft_sort_four(int **stack_a, int **stack_b, int	*len_a, int *len_b)
{
	int	min_index;

	min_index = find_min(stack_a, 4);
	printf("The minimum index: %d\n", min_index);
	if (min_index < 2)
	{
		if (min_index == 1)
			ft_swap(stack_a, 'a');
		if (!is_sorted(stack_a, 4))
			ft_push_b(stack_a, stack_b, len_a, len_b);
		else
			return ;
	}
	else
	{
		if (min_index == 2)
			ft_reverse_rotate(stack_a, 'a', 4);
		ft_reverse_rotate(stack_a, 'a', 4);
		if (!is_sorted(stack_a, 4))
			ft_push_b(stack_a, stack_b, len_a, len_b);
		else
			return ;
	}
	ft_sort_three(stack_a, 'a');
	ft_push_a(stack_a, stack_b, len_b, len_a);
}

void	ft_sort_five(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	min_index;

	min_index = find_min(stack_a, 5);
	if (min_index < 2)
	{
		if (min_index == 1)
			ft_swap(stack_a, 'a');
		if (!is_sorted(stack_a, 5))
			ft_push_b(stack_a, stack_b, len_a, len_b);
		else
			return ;
	}
	else
	{
		if (min_index == 2)
			ft_reverse_rotate(stack_a, 'a', 5);
		ft_reverse_rotate(stack_a, 'a', 5);
		if (!is_sorted(stack_a, 5))
			ft_push_b(stack_a, stack_b, len_a, len_b);
		else
			return ;
	}
	ft_sort_four(stack_a, stack_b, len_a, len_b);
	ft_push_a(stack_a, stack_b, len_b, len_a);
}

void	sort_b(int **stack_b, int len_b)
{
	if (len_b > 1 && (*stack_b)[0] < (*stack_b)[1])
		ft_rotate(stack_b, 'b', len_b);
}

int		ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i ++;
	}
	return (i - 1);
}

/* void	special_sort(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	// int	hold_first;
	// int	hold_second;
	int chunk;
	// int	i;
	// int	k;
	(void)stack_b;
	(void)stack_a;
	(void)len_b;
	(void)len_a;

	// i = 0;
	// k = 0;
	chunk = ft_sqrt(*len_a);
	printf("the chunk: %d\n", chunk);
	printf("The length of A: %d\n", *len_a);
	// show_stack(stack_a, NULL, *len_a);
} */

int	mid_point_in_stack(int **stack, int len, int mid_point)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (mid_point == (*stack)[i])
			return (1);
	}
	return (0);
}

/*  void	mid_point_a(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
	int	*sorted_stack;
	int	total_len;
	int	i;
	int	*placeholder;
	static int	*chunk;
	
	chunk = 0;
	total_len = *len_a;
	i = 0;
	sorted_stack = malloc(sizeof(int) * (*len_a));
	placeholder = malloc(sizeof(int) * (*len_a));
	while(i < (*len_a))
	{
		placeholder[i] = (*stack_a)[i];
		i ++;
	}
	sorted_stack = selection_sort(placeholder, *len_a);
	int	mid_point = sorted_stack[(*len_a)/2];
	// printf("mid_point: %d\n", mid_point);
	i = 0;
	while (i < (total_len)/2)
	{
		if ((*stack_a)[0] < mid_point)
		{
			ft_push_b(stack_a, stack_b, len_a, len_b);
			sort_b(stack_b, *len_b, mid_point);
			i ++;
		}
		else if ((*stack_a)[*len_a - 1] < mid_point)
		{
			ft_reverse_rotate(stack_a, 'a', *len_a);
			ft_push_b(stack_a, stack_b, len_a, len_b);
			i ++;
		}
		else
			ft_rotate(stack_a, 'a', *len_a);
	}
	// chunk[]
	if (*len_a > 2)
		mid_point_a(stack_a, stack_b, len_a, len_b);
	if ((*stack_a)[0] > (*stack_a)[1])
		ft_swap(stack_a, 'a');
	printf("len_a: %d\n", *len_a);
	printf("len_b: %d\n", *len_b);
}*/

/* void	mid_point(int **stack, int length)
{
	int	*sorted_stack;
	int	i;
	int	*placeholder;

	i = 0;
	sorted_stack = malloc(sizeof(int) * length);
	placeholder = malloc(sizeof(int) * length);
	while(i < length)
	{
		placeholder[i] = stack[i];
		i ++;
	}
	sorted_stack = selection_sort(placeholder, length);
	mid_point_algo(stack, length, sorted_stack);
} */

/* void	mid_point_algo(int **stack, int length, int sorted_stack)
{
	int	i;

	i = 0;
	
} */

int	find_max(int **stack, int length)
{
	int	i;
	int	max_index;

	max_index = 0;
	i = 1;
	while (i < length)
	{
		if ((*stack)[i] > (*stack)[max_index])
			max_index = i;
		i ++;
	}
	return (max_index);
}

void	push_up(int **stack_b, int *len_b, int index)
{
	int	i = 0;

	if (index == 0)
		return ;
	while (i < index)
	{
		ft_rotate(stack_b, 'b', *len_b);
		i ++;
	}
}

void	push_down(int **stack_b, int *len_b, int index)
{
	int	i = 0;

	while (i < index)
	{
		ft_reverse_rotate(stack_b, 'b', *len_b);
		i ++;
	}
}

void	sort_to_a(int **stack_a, int **stack_b, int *len_b, int *len_a)
{
	int	i;
	// int	length = *len_b;

	// show_stack(stack_a, stack_b, length);
	while (*len_b >= 0)
	{
		i = find_max(stack_b, *len_b);
/* 		printf("THE MAX OF STACK_B: %d\n", i);
		printf("THE LENGTH OF B: %d\n", *len_b);
		show_stack(stack_a, stack_b, length); */
		if (*len_b - i >= i)
		{
			// printf("PUSH UP IS AFFECTED\n");
			push_up(stack_b, len_b, i);
		}
		else
		{
			// printf("PUSH DOWN IS AFFECTED\n");
			push_down(stack_b, len_b, *len_b - i);
		}
			ft_push_a(stack_a, stack_b, len_b, len_a);
	}
}

void	three_part_sort(int **stack_a, int **stack_b, int *len_a, int *len_b)
{
    int	*sorted_stack;
    int	*placeholder;
    int	i;
	int	chunks;

	if (*len_a < 100)
		chunks = 5;
	else if (*len_a < 500)
		chunks = 10;
	else
		chunks = 18;
	i = 0;
	int	length = *len_a;
	placeholder = malloc(sizeof(int) * (*len_a));
	sorted_stack = malloc(sizeof(int) * (*len_a));
	while (i < *len_a)
	{
		placeholder[i] = (*stack_a)[i];
		i ++;
	}
	sorted_stack = selection_sort(placeholder, *len_a);
	while (*len_a != 0)
	{
		if ((*stack_a)[0] <= sorted_stack[chunks])
		{
			ft_push_b(stack_a, stack_b, len_a, len_b);
			if (chunks < length - 1)
				chunks++;
			sort_b(stack_b, *len_b);
		}
		else
			ft_rotate(stack_a, 'a', *len_a);
		// printf("(*stack_a)[0]: %d\n is less than sorted_stack[chunks]: %d\n", (*stack_a)[0], sorted_stack[chunks]);
	}
	sort_to_a(stack_a, stack_b, len_b, len_a);
}

void	divide_elements(int **stack_a, int **stack_b, int length)
{
	int	len_a;
	int	len_b;
	int	i;
	int	*sorted_stack;
	int	*placeholder;

	len_a = length;
	len_b = 0;
	i = 0;
	sorted_stack = malloc(sizeof(int) * length);
	placeholder = malloc(sizeof(int) * length);
	while(i < length)
	{
		placeholder[i] = (*stack_a)[i];
		i ++;
	}
	i = 0;
	sorted_stack = selection_sort(placeholder, length);
	// int	k = length/3; // 10
	// int	l = k * 2; // 20
/* 	if (len_a == 5)
	{
		ft_sort_five(stack_a, stack_b, &len_a, &len_b);
		// exit(1);
	}
	else if (len_a == 4)
	{
		ft_sort_four(stack_a, stack_b, &len_a, &len_b);
		// exit(1);
	}
	else if (len_a == 3)
	{
		ft_sort_three(stack_a, 'a');
		// exit(1);
	}
	else if (len_a == 2)
	{
		if ((*stack_a)[0] > (*stack_a)[1])
			ft_swap(stack_a, 'a');
		// exit(1);
	}
	else if (length <= 15)
	{
		while (len_a > k + 1) // while (len_a > 10)
		{
			// printf("the length of len_a: %d\nk: %d", len_a, k);
			if ((*stack_a)[0] <= sorted_stack[l]) // if the first element of stack_a is lower than the two third's elemnt of the sorted one
			{
				ft_push_b(stack_a, stack_b, &len_a, &len_b);
				sort_b(stack_b, len_b, sorted_stack[k]);
			}
			else
			{
				ft_rotate(stack_a, 'a', len_a);
			}
		}
		while (len_a > 3)
		{
			if ((*stack_a)[0] < sorted_stack[length - 3])
				ft_push_b(stack_a, stack_b, &len_a, &len_b);
			else
				ft_rotate(stack_a, 'a', len_a);
			if (len_a%2==1)
				ft_rotate(stack_b, 'b', len_b);
		}
		if (len_a == 3)
		{
			ft_sort_three(stack_a, 'a');
		}
		while (len_a < length)
		{
			if ((*stack_b[0]) < (*stack_b)[len_b - 1])
			{
				ft_reverse_rotate(stack_b, 'b', len_b);
			}
			ft_push_a(stack_a, stack_b, &len_b, &len_a);
			while ((*stack_a)[0] > (*stack_a)[1])
			{
				ft_swap(stack_a, 'a');
				ft_rotate(stack_a, 'a', len_a);
				i ++;
			}
			while (i > 0)
			{
				ft_reverse_rotate(stack_a, 'a', len_a);
				i --;
			}
		}
	}
	else */
	three_part_sort(stack_a, stack_b, &len_a, &len_b);
	// show_stack(stack_a, stack_b, length);
	exit(1);
}

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
	// show_stack(&stack_a, &stack_b, length);
	// mid_point_a(&stack_a, &stack_b, &len_a, &len_b);
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
	// show_stack(&stack, NULL, length);
	free_stack(&stack);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:21:54 by zelbassa          #+#    #+#             */
/*   Updated: 2024/01/06 21:32:30 by zelbassa         ###   ########.fr       */
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

void    free_stack(int **stack)
{
    free(*stack);
    *stack = NULL;
}

void    fill_single_argument(char **av, int **stack)
{
    int     i;
    char    **tokens;

    i = 0;
    tokens = ft_split(av[1], ' ');
    if (tokens)
    {
        while (tokens[i])
            if (is_int(tokens[i]))
                i ++;
            else
                return ;
    }
    if (i < 2)
        return ;
    *stack = malloc(sizeof(int) * i);
    i = 0;
    while (tokens[i])
    {
        (*stack)[i] = ft_atoi(ft_strdup(tokens[i]));
        i ++;
    }
}

void    fill_multiple_arguments(char **av, int ac, int **stack)
{
    int     i;

    i = 0;
    *stack = malloc(sizeof(int) * (ac - 1));
    while (i < ac)
    {
        if (is_int(av[i]))
            (*stack)[i] = ft_atoi(av[i]);
        else
        {
            free_stack(stack);
            return ;
        }
        i ++;
    }
}

int main(int ac, char **av)
{
    int i;
    int *stack;

    stack = NULL;
    i = 0;
    if (ac < 2)
    {
        ft_printf("Error\n");
        return (0);
    }
    if (ac == 2)
        fill_single_argument(av, &stack);
    else
        fill_multiple_arguments(av, ac, &stack);
    if (!stack)
        ft_printf("Error\n");
    while (stack[i])
    {
        ft_printf("%d\n", stack[i]);
        i ++;
    }
    i = 0;
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
//	int	    *stack;
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
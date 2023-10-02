/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:59:15 by abelrodr          #+#    #+#             */
/*   Updated: 2023/10/02 14:48:33 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Parsing for Push_Swap proyect, created by abelrodr 42 student.*/

#include "../../inc/push_swap.h"

static t_stack	*ft_process_one_arg(char **argv);
static t_stack	*ft_process_args(int argc, char **argv);
static int		ft_atoi_ps(const char *str, t_stack **stack_a);

t_stack	*ft_parser(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		exit(1);
	else if (argc == 2)
		stack_a = ft_process_one_arg(argv);
	else
		stack_a = ft_process_args(argc, argv);
	return (stack_a);
}

static t_stack	*ft_process_one_arg(char **argv)
{
	t_stack	*stack_a;
	char	**aux;
	int		i;
	int		value;

	stack_a = NULL;
	i = 0;
	aux = ft_split(argv[1], 32);
	while (aux[i])
	{
		if (ft_is_digit_sign(aux, i))
			value = ft_atoi_ps(aux[i], &stack_a);
		else
		{
			ft_memfree_all(aux);
			ft_error("Error: Invalid argument", &stack_a, NULL);
		}
		stack_add_back(&stack_a, stack_new(value));
		i++;
	}
	ft_memfree_all(aux);
	return (stack_a);
}

static t_stack	*ft_process_args(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		value;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_is_digit_sign(argv, i))
			value = ft_atoi_ps(argv[i], &stack_a);
		else
			ft_error("Error: Invalid argument", &stack_a, NULL);
		stack_add_back(&stack_a, stack_new(value));
		i++;
	}
	return (stack_a);
}

static int	ft_atoi_ps(const char *str, t_stack **stack_a)
{
	long	atoi;
	int		sign;

	atoi = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		atoi *= 10;
		atoi += *str - '0';
		str++;
	}
	if (ft_isalpha(*str))
		ft_error("Error: Invalid argument", stack_a, NULL);
	if (atoi * sign > 2147483647 || atoi * sign < -2147483648)
		ft_error("Error: Integer overflow", stack_a, NULL);
	return (atoi * sign);
}

int	ft_duplicates(t_stack *stack_a)
{
	t_stack	*aux;

	while (stack_a)
	{
		aux = stack_a->next;
		while (aux)
		{
			if (stack_a->value == aux->value)
				return (1);
			aux = aux->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

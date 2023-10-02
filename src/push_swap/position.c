/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:21:17 by abelrodr          #+#    #+#             */
/*   Updated: 2023/10/02 15:12:30 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	position(t_stack *stack);
static int	target(t_stack **a, int b_index);
static int	botton_target(t_stack **a, int target_index, int target_pos);

int	lower_position(t_stack **stack)
{
	t_stack	*aux;
	int		lower_index;
	int		lower_pos;

	position(*stack);
	aux = *stack;
	lower_index = INT_MAX;
	lower_pos = aux->pos;
	while (aux)
	{
		if (aux->index < lower_index)
		{
			lower_index = aux->index;
			lower_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (lower_pos);
}

void	target_position(t_stack **a, t_stack **b)
{
	t_stack	*aux_b;

	position(*a);
	position(*b);
	aux_b = *b;
	while (aux_b)
	{
		aux_b->target_pos = target(a, aux_b->index);
		aux_b = aux_b->next;
	}
}

static void	position(t_stack *stack)
{
	int	i;

	i = -1;
	while (stack)
	{
		stack->pos = ++i;
		stack = stack->next;
	}
}

static int	target(t_stack **a, int b_index)
{
	t_stack	*aux_a;
	int		target_index;
	int		target_pos;

	aux_a = *a;
	target_index = INT_MAX;
	target_pos = 0;
	while (aux_a)
	{
		if (aux_a->index > b_index && aux_a->index < target_index)
		{
			target_index = aux_a->index;
			target_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	else
		return (botton_target(a, target_index, target_pos));
}

static int	botton_target(t_stack **a, int target_index, int target_pos)
{
	t_stack	*aux_a;

	aux_a = *a;
	while (aux_a)
	{
		if (aux_a->index < target_index)
		{
			target_index = aux_a->index;
			target_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	return (target_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:51:00 by abelrodr          #+#    #+#             */
/*   Updated: 2023/10/02 15:35:32 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	save_three_a(t_stack **a, t_stack **b, int size)
{
	while (stack_size(*b) < size / 2 && stack_size(*a) > 3)
	{
		if ((*a)->index <= size / 2)
			pb(a, b);
		else
			ra(a);
	}
	while (stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
}

void	cost(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	aux = *b;
	while (aux)
	{
		aux->cost_b = aux->pos;
		if (aux->pos > stack_size(*b) / 2)
			aux->cost_b = (stack_size(*b) - aux->pos) * -1;
		aux->cost_a = aux->target_pos;
		if (aux->target_pos > stack_size(*a) / 2)
			aux->cost_a = (stack_size(*a) - aux->target_pos) * -1;
		aux = aux->next;
	}
}

void	cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*aux;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	aux = *b;
	cheapest = INT_MAX;
	while (aux)
	{
		if (ft_iabs(aux->cost_a) + ft_iabs(aux->cost_b) < ft_iabs(cheapest))
		{
			cost_a = aux->cost_a;
			cost_b = aux->cost_b;
			cheapest = ft_iabs(cost_b) + ft_iabs(cost_a);
		}
		aux = aux->next;
	}
	move(a, b, cost_a, cost_b);
}

void	final_offset(t_stack **a)
{
	int	lower_pos;

	lower_pos = lower_position(a);
	if (lower_pos > stack_size(*a) / 2)
	{
		while (lower_pos < stack_size(*a))
		{
			rra(a);
			lower_pos++;
		}
	}
	else
	{
		while (lower_pos > 0)
		{
			ra(a);
			lower_pos--;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:47:02 by abelrodr          #+#    #+#             */
/*   Updated: 2023/10/02 15:35:24 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*aux;
	int		highest;

	aux = *stack;
	highest = aux->value;
	while (aux)
	{
		if (aux->value > highest)
			highest = aux->value;
		aux = aux->next;
	}
	if ((*stack)->value == highest)
		ra(stack);
	else if ((*stack)->next->value == highest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_all(t_stack **a, t_stack **b)
{
	save_three_a(a, b, stack_size(*a));
	while (*b)
	{
		target_position(a, b);
		cost(a, b);
		cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		final_offset(a);
}

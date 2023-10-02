/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:11:31 by abelrodr          #+#    #+#             */
/*   Updated: 2023/10/02 14:49:25 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/********************************* LIBS ***************************************/

# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <memory.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/********************************* MACROS *************************************/

# define ERR_STACK "error stack"

/********************************* STRUCTS ************************************/

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/********************************* FUNCTIONS *********************************/

// Utils
void				free_stack(t_stack **stack);
void				ft_error(char *msg, t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack *stack);
// Checks_args
t_stack				*ft_parser(int argc, char **argv);
int					ft_duplicates(t_stack *stack_a);
// Stack
t_stack				*stack_last(t_stack *lst);
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **lst, t_stack *new);
int					stack_size(t_stack *lst);
// Algorithim
void				sort_three(t_stack **stack);
void				sort_all(t_stack **a, t_stack **b);
// Algorithim utils
void				save_three_a(t_stack **a, t_stack **b, int size);
void				cost(t_stack **stack_a, t_stack **stack_b);
void				cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				final_offset(t_stack **stack_a);
// Move
void				move(t_stack **a, t_stack **b, int cost_a, int cost_b);
// Position
int					lower_position(t_stack **stack);
void				target_position(t_stack **a, t_stack **b);

// Rotate
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
// Push
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
// Swap
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
// Reverse rotate
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif
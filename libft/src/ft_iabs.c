/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:11:41 by abelrodr          #+#    #+#             */
/*   Updated: 2023/09/21 17:32:32 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_iabs(int nb)
// This function returns the absolute value of an integer.
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

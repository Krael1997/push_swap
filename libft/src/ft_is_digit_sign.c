/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelrodr <abelrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:19:47 by abelrodr          #+#    #+#             */
/*   Updated: 2023/09/21 13:20:32 by abelrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_is_digit_sign(char **str, int i)
{
	int	j;

	j = 0;
	if (ft_issign(str[i][j]))
		j++;
	while (str[i][j])
	{
		if (!ft_isdigit(str[i][j]))
			return (0);
		j++;
	}
	return (1);
}

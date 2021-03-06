/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:49:29 by glima-de          #+#    #+#             */
/*   Updated: 2022/02/13 15:44:59 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	in_order(t_stack *s)
{
	size_t	i;

	i = 1;
	while (i < s->size)
	{
		if (s->array[i] < s->array[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	in_reverse_order(t_stack *s)
{
	size_t	i;

	i = 1;
	while (i < s->size)
	{
		if (s->array[i] > s->array[i - 1])
			return (0);
		i++;
	}
	return (1);
}

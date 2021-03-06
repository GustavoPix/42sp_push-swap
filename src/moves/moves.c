/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:02:40 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 21:05:38 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack *s)
{
	int	x;

	if (s->size >= 2)
	{
		x = s->array[0];
		s->array[0] = s->array[1];
		s->array[1] = x;
	}
}

void	push(t_stack *ori, t_stack *dest)
{
	int	s_dest;
	int	s_ori;

	s_dest = sizeof(int) * dest->size;
	s_ori = sizeof(int) * (ori->size - 1);
	if (ori->size >= 1)
	{
		ft_memmove(&dest->array[1], &dest->array[0], s_dest);
		dest->array[0] = ori->array[0];
		ft_memmove(&ori->array[0], &ori->array[1], s_ori);
		ori->array[ori->size - 1] = 0;
		ori->size--;
		dest->size++;
	}
}

void	rotate(t_stack *s)
{
	int	x;

	if (s->size >= 2)
	{
		x = s->array[0];
		ft_memmove(&s->array[0], &s->array[1], sizeof(int) * (s->size - 1));
		s->array[s->size - 1] = x;
	}
}

void	rev_rotate(t_stack *s)
{
	int	x;

	if (s->size >= 2)
	{
		x = s->array[s->size - 1];
		ft_memmove(&s->array[1], &s->array[0], sizeof(int) * (s->size - 1));
		s->array[0] = x;
	}
}

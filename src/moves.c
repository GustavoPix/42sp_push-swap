/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:02:40 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/14 20:39:45 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap(t_stack *s)
{
	int x;

	if (s->size >= 2)
	{
		x = s->array[0];
		s->array[0] = s->array[1];
		s->array[1] = x;
	}
}

void push(t_stack *ori, t_stack *dest)
{
	if (ori->size >= 1)
	{
		ft_memmove(&dest->array[1], &dest->array[0], sizeof(int) * dest->size);
		dest->array[0] = ori->array[0];
		ft_memmove(&ori->array[0], &ori->array[1], sizeof(int) * (ori->size - 1));
		ori->array[ori->size - 1] = 0;
		ori->size--;
		dest->size++;
	}
}

void rotate(t_stack *s)
{
	int x;

	if (s->size >= 2)
	{
		x = s->array[0];
		ft_memmove(&s->array[0], &s->array[1], sizeof(int) * (s->size - 1));
		s->array[s->size - 1] = x;
	}
}

void rev_rotate(t_stack *s)
{
	int x;

	if (s->size >= 2)
	{
		x = s->array[s->size - 1];
		ft_memmove(&s->array[1], &s->array[0], sizeof(int) * (s->size - 1));
		s->array[0] = x;
	}
}

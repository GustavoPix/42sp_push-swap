/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:48:35 by glima-de          #+#    #+#             */
/*   Updated: 2022/02/13 15:46:34 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reduce(t_stack *s)
{
	int		*aux;
	size_t	ordened;
	size_t	i;
	int		minnor;
	int		last_minnor;

	aux = malloc(sizeof(int) * s->size);
	ordened = 0;
	while (ordened < s->size)
	{
		i = 0;
		minnor = 2147483647;
		while (i < s->size)
		{
			if (s->array[i] < minnor)
			{
				if (ordened == 0 || s->array[i] > last_minnor)
				{
					minnor = s->array[i];
					aux[i] = ordened;
				}
			}
			i++;
		}
		last_minnor = minnor;
		ordened++;
	}
	i = 0;
	while (i < s->size)
	{
		s->array[i] = aux[i];
		i++;
	}
	free(aux);
}

static int	check_order_stacks(t_stacks *s)
{
	if (in_reverse_order(&s->b) && in_order(&s->a))
		if (s->b.array[0] < s->a.array[0])
			return (1);
	return (0);
}

void	radix_a(t_stacks *s, int ib)
{
	size_t	i;
	size_t	asize;

	i = 0;
	asize = s->a.size;
	{
		while (i < asize)
		{
			if (check_order_stacks(s))
				break ;
			if ((s->a.array[0] >> ib) & 1)
				rotate_a(s);
			else
				push_b(s);
			i++;
		}
	}
}

void	radix_b(t_stacks *s, int ib)
{
	size_t	i;
	size_t	bsize;

	i = 0;
	bsize = s->b.size;
	while (i < bsize)
	{
		if (check_order_stacks(s))
			break ;
		if ((s->b.array[0] >> ib) & 1)
			push_a(s);
		else
			rotate_b(s);
		i++;
	}
}

void	radix_sort(t_stacks *s)
{
	int	ib;

	ib = 0;
	reduce(&s->a);
	while (!in_order(&s->a) || s->b.size)
	{
		radix_a(s, ib);
		if (check_order_stacks(s))
		{
			while (s->b.size)
				push_a(s);
			continue ;
		}
		else
		{
			ib++;
			radix_b(s, ib);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:48:35 by glima-de          #+#    #+#             */
/*   Updated: 2022/02/12 16:56:24 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void reduce(t_stack *s)
{
	int *aux;
	size_t ordened;
	size_t i;
	int minnor;
	int last_minnor;

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

int has_moviment(t_stack *s, int ib)
{
	size_t i;

	i = 0;

	while (i < s->size)
	{
		if (!((s->array[i] >> ib) & 1))
			return (1);
		i++;
	}
	return (0);
}

void radix_sort(t_stacks *s, int size)
{
	size_t i;
	size_t j;
	int ib;

	ib = 0;
	size_t bsize;
	size_t asize;
	size = 1;
	reduce(&s->a);
	while (!in_order(&s->a) || s->b.size)
	{
		i = 0;
		asize = s->a.size;
		if (has_moviment(&s->a, ib))
		{
			while (i < asize)
			{
				if ((s->a.array[0] >> ib) & 1)
					rotate_a(s);
				else
					push_b(s);
				i++;
			}
		}
		j = 0;
		bsize = s->b.size;
		// print_stacks(s);
		// getchar();
		if (in_reverse_order(&s->b) && in_order(&s->a))
		{
			if (s->b.array[0] < s->a.array[0])
				while (s->b.size)
					push_a(s);
			continue;
		}
		ib++;
		if (has_moviment(&s->b, ib))
		{
			while (j < bsize)
			{
				if ((s->b.array[0] >> ib) & 1)
					push_a(s);
				else
					rotate_b(s);
				j++;
			}
		}
		// print_stacks(s);
		// getchar();
	}
}

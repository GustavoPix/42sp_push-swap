/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:48:35 by glima-de          #+#    #+#             */
/*   Updated: 2022/02/13 16:54:40 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	index_lower_number(t_stack *s, int lower)
{
	size_t	i;
	int		r;
	int		l_lower;

	l_lower = 2147483647;
	i = 0;
	while (i < s->size)
	{
		if (s->array[i] >= lower && s->array[i] < l_lower)
		{
			l_lower = s->array[i];
			r = (int)i;
		}
		i++;
	}
	return (r);
}

static void	reduce(t_stack *s)
{
	int		*aux;
	int		i;
	int		l_result;
	size_t	ordened;

	aux = malloc(sizeof(int) * s->size);
	ordened = 0;
	l_result = -2147483648;
	while (ordened < s->size)
	{
		i = index_lower_number(s, l_result);
		aux[i] = ordened;
		l_result = s->array[i] + 1;
		ordened++;
	}
	i = 0;
	while (i < (int)s->size)
	{
		s->array[i] = aux[i];
		i++;
	}
	free(aux);
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

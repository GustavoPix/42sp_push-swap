/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:56:21 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/06 19:56:21 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int inOrder(t_stack *s)
{
	size_t i;

	i = 1;
	while (i < s->size)
	{
		if (s->array[i] < s->array[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void big_push_swap(t_stacks *s, int size)
{
	int i;
	int ib;

	ib = 0;
	while ((!inOrder(&s->a) || s->b.size))
	{
		i = 0;
		while (i < size)
		{
			if (((s->a.array[0] >> ib) & 1))
				rotate_a(s);
			else
				push_b(s);
			i++;
		}
		while (s->b.size)
			push_a(s);
		ib++;
	}
}

int convert_binarie(int num)
{
	size_t i;
	int d;
	int aux;

	i = 0;
	d = 1;
	aux = 0;
	while (num > 0)
	{
		aux += num % 2 * d;
		d *= 10;
		num /= 2;
	}
	return (aux);
}

void push_swap(t_stacks *s)
{
	int m;

	m = 0;
	while ((!inOrder(&s->a) || s->b.size))
	{
		if (s->a.array[1] < s->a.array[0])
			swap_a(s);
		else if (s->a.array[0] > s->a.array[s->a.size - 1])
			rotate_a(s);
		else if (!inOrder(&s->a))
			push_b(s);
		if (s->b.size > 1)
		{
			if (s->b.array[0] < s->b.array[s->b.size - 1])
				rotate_b(s);
			else if (s->b.array[0] < s->b.array[1])
				swap_b(s);
		}
		if (inOrder(&s->a) && s->b.size)
			push_a(s);
		m++;
	}
}

void normalize(t_stack *s)
{
	size_t i;
	int minnor;

	i = 0;
	minnor = 0;
	while (i < s->size)
	{
		if (s->array[i] < minnor)
			minnor = s->array[i];
		i++;
	}
	i = 0;
	minnor *= -1;
	while (i < s->size)
	{
		s->array[i] += minnor;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stacks s;
	int i;

	s.a.array = malloc(sizeof(int) * argc - 1);
	s.b.array = malloc(sizeof(int) * argc - 1);
	s.a.size = argc - 1;
	s.b.size = 0;
	i = 0;

	while (i < argc - 1)
	{
		s.a.array[i] = (int)ft_atoi(argv[i + 1]);
		s.b.array[i] = 0;
		i++;
	}
	i = 0;
	// while (i < argc - 1)
	//{
	//	printf("%d -> %x -> %d\n", s.a.array[i], (s.a.array[i]), (s.a.array[i] >> 0) & 1);
	//	i++;
	// }
	// print_stacks(&s);
	normalize(&s.a);
	big_push_swap(&s, argc - 1);

	// print_stacks(&s);

	clear(&s);

	return (0);
}

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
		s.a.array[i] = ft_atoi(argv[i + 1]);
		s.b.array[i] = 0;
		i++;
	}
	// print_stacks(&s);
	push_swap(&s);
	// print_stacks(&s);

	clear(&s);

	return (0);
}

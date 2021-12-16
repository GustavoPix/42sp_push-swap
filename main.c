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

int outOrder(t_stack *s)
{
	int qty;
	size_t i;

	i = 1;
	qty = 0;
	while (i < s->size)
	{
		if (s->array[i] < s->array[i - 1])
			qty++;
		i++;
	}
	return (qty);
}

int rev_outOrder(t_stack *s)
{
	int qty;
	size_t i;

	i = 1;
	qty = 0;
	while (i < s->size)
	{
		if (s->array[i] > s->array[i - 1])
			qty++;
		i++;
	}
	return (qty);
}

int rev_inOrder(t_stack *s)
{
	size_t i;

	i = 1;
	while (i < s->size)
	{
		if (s->array[i] > s->array[i - 1])
			return (0);
		i++;
	}
	return (1);
}

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
	// custom_order(&s);
	radix_sort2(&s, argc - 1);
	// bubble(&s);
	// print_stacks(&s);

	clear(&s);

	return (0);
}

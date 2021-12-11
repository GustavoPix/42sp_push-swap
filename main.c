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

int main(void)
{
	t_stacks s;
	int i;

	s.a.array = malloc(sizeof(int) * 10);
	s.b.array = malloc(sizeof(int) * 10);
	s.a.size = 10;
	s.b.size = 0;
	i = 0;

	while (i < 10)
	{
		s.a.array[i] = i + 1;
		s.b.array[i] = 0;
		i++;
	}
	print_stacks(&s);
	push_b(&s);
	print_stacks(&s);
	push_b(&s);
	print_stacks(&s);
	push_b(&s);
	print_stacks(&s);
	swap_a(&s);
	print_stacks(&s);
	swap_b(&s);
	print_stacks(&s);
	rotate_a(&s);
	print_stacks(&s);
	rotate_b(&s);
	print_stacks(&s);
	push_a(&s);
	print_stacks(&s);
	rev_rotate_a(&s);
	print_stacks(&s);
	rotate_r(&s);
	print_stacks(&s);
	rev_rotate_b(&s);
	print_stacks(&s);
	rev_rotate_r(&s);
	print_stacks(&s);

	clear(&s);

	return (0);
}

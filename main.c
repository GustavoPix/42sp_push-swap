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
	t_stack a;
	t_stack b;
	int	i;

	a.array = malloc(sizeof(int) * 10);
	b.array = malloc(sizeof(int) * 10);
	a.size = 10;
	b.size = 0;
	i = 0;

	while(i < 10)
	{
		a.array[i] = i;
		b.array[i] = 0;
		i++;
	}
	print_stacks(&a, &b);

	clear(&a, &b);

	return (0);
}

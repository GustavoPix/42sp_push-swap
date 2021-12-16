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

static void	push_swap(int argc, char **argv, t_stacks *s)
{
	int	i;

	s->a.array = malloc(sizeof(int) * argc - 1);
	s->b.array = malloc(sizeof(int) * argc - 1);
	s->a.size = argc - 1;
	s->b.size = 0;
	i = 0;
	while (i < argc - 1)
	{
		s->a.array[i] = ft_atoi(argv[i + 1]);
		s->b.array[i] = 0;
		i++;
	}
	if (checker(argc, argv, s))
	{
		if (argc < 50)
			custom_order(s);
		else if (argc < 100)
			insert(s);
		else if (argc < 150)
			radix_sort2(s, argc - 1);
		else
			radix_sort(s, argc - 1);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	push_swap(argc, argv, &s);
	clear(&s);
	return (0);
}

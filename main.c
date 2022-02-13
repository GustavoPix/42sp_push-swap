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

static void push_swap(int argc, char **argv, t_stacks *s)
{
	int i;

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
		if (argc <= 20)
			custom_order(s);
		//  else if (argc < 100)
		//	insert(s);
		//  else if (argc < 150)
		//	radix_sort2(s, argc - 1);
		else
			radix_sort(s, argc - 1);
	}
}

static char **split_string(char **strs)
{
	char *aux;

	aux = ft_strjoin(strs[0], strs[1]);
	aux[ft_strlen(strs[0]) - 1] = ' ';
	strs = ft_split(aux, ' ');
	free(aux);
	return (strs);
}

int main(int argc, char **argv)
{
	t_stacks s;

	if (argc == 2)
	{
		argc = 0;
		argv = split_string(argv);
		while (argv[argc])
			argc++;
		push_swap(argc, argv, &s);
		clear_matrix(argv);
	}
	else
		push_swap(argc, argv, &s);
	clear(&s);
	return (0);
}

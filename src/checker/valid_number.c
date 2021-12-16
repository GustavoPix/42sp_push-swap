/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:51:16 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/16 19:09:44 by glima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int is_valid_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (i > 0 && str[i] > '-')
				return (0);
		}
		i++;
	}
	return (1);
}

int is_valid_numbers(char **strs, int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (!is_valid_number(strs[i]))
			return (0);
		i++;
	}
	return (1);
}

int duplicate_number(t_stack *s)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			if (s->array[i] == s->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int min_valid_value(t_stack *s, char **str)
{
	size_t i;

	i = 0;
	while (i < s->size)
	{
		if (ft_strncmp(str[i + 1], ft_itoa(s->array[i]), ft_strlen(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

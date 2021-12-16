/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima-de <glima-de@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:51:16 by glima-de          #+#    #+#             */
/*   Updated: 2021/12/15 22:19:40 by glima-de         ###   ########.fr       */
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
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

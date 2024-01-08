/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:51:19 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/08 12:36:24 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		chunk_size;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (0);
	setup_stack(&a, argv, argc);
	chunk_size = 20 + ((size(&a) - 100) / 16);
	if (chunk_size < size(&a))
		insertion_sort(&a, &b, chunk_size);
	else
		insertion_sort(&a, &b, chunk_size);
	clear_stack(&a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:51:19 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/15 00:12:33 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		chunk;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	setup_stack(&a, argv, argc);
	chunk = 18;
	if (size(&a) > 2 || !stack_is_sorted(a))
	{
		if (chunk > size(&a))
			shaker_sort(&a, &b);
		else
			smash_sort(&a, &b, chunk);
	}
	clear_stack(&a);
	return (0);
}

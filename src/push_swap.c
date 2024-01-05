/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:51:19 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 11:24:55 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **a, t_stack **b)
{
	t_operation	*instructions;

	instructions = init_instructions();
	perform_and_log(a, b, instructions[RA]);
	perform_and_log(a, b, instructions[RRA]);
	perform_and_log(a, b, instructions[PB]);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (0);
	setup_stack(&a, argv, argc);
	insertion_sort(&a, &b);
	return (0);
}

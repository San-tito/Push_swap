/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:13:33 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/07 15:42:50 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_stack *stack, t_stack *wanted)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if (current == wanted)
			break ;
		current = (*current).next;
		index++;
	}
	return (index);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*current;

	while (!stack_is_sorted(*a))
	{
		min = *a;
		current = (**a).next;
		while (current)
		{
			if ((*current).value < (*min).value)
				min = current;
			current = (*current).next;
		}
		while (*a != min)
		{
			if ((size(a) / 2) < get_index(*a, min))
				perform_and_log(a, b, RRA);
			else
				perform_and_log(a, b, RA);
		}
		perform_and_log(a, b, PB);
	}
	while (*b)
		perform_and_log(a, b, PA);
}

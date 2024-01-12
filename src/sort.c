/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:13:33 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/12 13:25:41 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of(t_stack *stack, int wanted)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if ((*current).value == wanted)
			break ;
		current = (*current).next;
		index++;
	}
	return (index);
}

t_stack	*minimum(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;

	current = stack;
	min = current;
	while (current)
	{
		if ((*current).value < (*min).value)
			min = current;
		current = current->next;
	}
	return (min);
}

int	sorted_index_of(t_stack *stack, int index)
{
	t_stack	*min;
	t_stack	*prev;
	t_stack	*current;

	current = stack;
	min = minimum(current);
	while (current && index--)
	{
		if (min == current)
			current = (*current).next;
		else
		{
			prev = current;
			while ((*prev).next != min)
				prev = (*prev).next;
			(*prev).next = (*min).next;
		}
		min = minimum(current);
	}
	return (index_of(stack, (*min).value));
}

void	insertion_sort(t_stack **a, t_stack **b, int chunk)
{
	t_stack	*min;

	(void)chunk;
	while (*a)
	{
		min = minimum(*a);
		while (*a != min)
		{
			if ((size(a) / 2) < index_of(*a, (*min).value))
				perform_and_log(a, b, RRA);
			else
				perform_and_log(a, b, RA);
		}
		perform_and_log(a, b, PB);
	}
	while (*b)
		perform_and_log(a, b, PA);
}

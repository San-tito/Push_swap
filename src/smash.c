/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:13:33 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/14 17:57:55 by sguzman          ###   ########.fr       */
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

int	sorted_value_at(t_stack **a, t_stack **b, int index)
{
	t_stack	*current;
	t_stack	*copy;
	int		value;

	copy = copy_stack(*a);
	if (!copy)
		wipe(a, b);
	bubble_sort(copy);
	current = copy;
	while ((*current).next && index--)
		current = (*current).next;
	value = (*current).value;
	clear_stack(&copy);
	return (value);
}

void	cheaper_move_to_top(t_stack **a, t_stack **b, int chunk)
{
	int	min_distance;
	int	min_value;
	int	value;
	int	distance;

	min_distance = size(a);
	while (chunk--)
	{
		value = sorted_value_at(a, b, chunk);
		distance = index_of(*a, value);
		if ((size(a) / 2) < index_of(*a, value))
			distance++;
		if (distance < min_distance)
		{
			min_distance = distance;
			min_value = value;
		}
	}
	while (min_distance--)
	{
		if ((size(a) / 2) < index_of(*a, min_value))
			perform_and_log(a, b, RRA);
		else
			perform_and_log(a, b, RA);
	}
}

#include <stdio.h>

void	smart_move(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		index;
	int		value;
	int		difference;
	int		min_difference;

	min_difference = size(b);
	current = *b;
	while (current)
	{
		difference = (**a).value - (*current).value;
		if (difference < min_difference)
		{
			min_difference = difference;
			value = (*current).value;
		}
		current = (*current).next;
	}
	if (min_difference == size(b))
		return ;
	index = index_of(*b, value);
	while (index)
	{
		if ((size(b) / 2) < index)
			perform_and_log(a, b, RRB);
		else
			perform_and_log(a, b, RB);
		index = index_of(*b, value);
	}
}

void	smash_sort(t_stack **a, t_stack **b, int chunk)
{
	t_stack	*max;

	while (*a)
	{
		cheaper_move_to_top(a, b, chunk);
		max = maximum(*b);
		while (*b != max)
		{
			if ((size(b) / 2) < index_of(*b, (*max).value))
				perform_and_log(a, b, RRB);
			else
				perform_and_log(a, b, RB);
		}
		perform_and_log(a, b, PB);
	}
	while (*b)
	{
		max = maximum(*b);
		while (*b != max)
		{
			if ((size(b) / 2) < index_of(*b, (*max).value))
				perform_and_log(a, b, RRB);
			else
				perform_and_log(a, b, RB);
		}
		perform_and_log(a, b, PA);
	}
}

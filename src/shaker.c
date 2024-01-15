/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:46:49 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/15 09:14:22 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*maximum(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;

	current = stack;
	min = current;
	while (current)
	{
		if ((*current).value > (*min).value)
			min = current;
		current = (*current).next;
	}
	return (min);
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

void	bubble_sort(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;
	int		swap;

	current = stack;
	while (current)
	{
		next = (*current).next;
		while (next)
		{
			if ((*current).value > (*next).value)
			{
				swap = (*current).value;
				(*current).value = (*next).value;
				(*next).value = swap;
			}
			next = (*next).next;
		}
		current = (*current).next;
	}
}

void	trident_sort(t_stack **a, t_stack **b)
{
	int	first;
	int	second;
	int	third;

	first = (**a).value;
	second = (*(**a).next).value;
	third = (*(*(**a).next).next).value;
	if (first < second && third > second && third > first)
		perform_and_log(a, b, SA);
	else if (first > second && third > second && first > third)
		perform_and_log(a, b, RA);
	else if (second > first && second > third && first > third)
		perform_and_log(a, b, RRA);
	else if (second > first && second > third && third > first)
	{
		perform_and_log(a, b, SA);
		perform_and_log(a, b, RA);
	}
	else if (first > second && second > third && first > third)
	{
		perform_and_log(a, b, SA);
		perform_and_log(a, b, RRA);
	}
}

void	shaker_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;

	if (size(a) == 2 && (**a).value > ((*(**a).next).value))
		return (perform_and_log(a, b, SA));
	while (size(a) > 3)
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
	trident_sort(a, b);
	while (*b)
		perform_and_log(a, b, PA);
}

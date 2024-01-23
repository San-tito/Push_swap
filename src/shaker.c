/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:46:49 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/23 07:02:10 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_value_at(t_stack *stack, int wanted)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if (index == wanted)
			break ;
		current = (*current).next;
		index++;
	}
	return ((*current).value);
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
	if (first > second && third > second && third > first)
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

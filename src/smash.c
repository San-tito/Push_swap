/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:13:33 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/23 06:26:56 by sguzman          ###   ########.fr       */
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

int	find_prev(t_stack **a, t_stack **b, int value)
{
	t_stack	*current;
	t_stack	*copy;
	int		prev;

	copy = copy_stack(*b);
	if (!copy)
		wipe(a, b);
	push(&copy, value);
	if (!copy)
		wipe(a, b);
	bubble_sort(copy);
	current = copy;
	while ((*current).next && (*(*current).next).value != value)
		current = (*current).next;
	prev = (*current).value;
	clear_stack(&copy);
	return (prev);
}

int	find_following(t_stack **a, t_stack **b, int value)
{
	t_stack	*current;
	t_stack	*copy;
	int		follow;

	copy = copy_stack(*a);
	if (!copy)
		wipe(a, b);
	push(&copy, value);
	if (!copy)
		wipe(a, b);
	bubble_sort(copy);
	current = copy;
	while ((*current).value != value)
		current = (*current).next;
	if ((*current).next)
		follow = (*(*current).next).value;
	else
		follow = (*minimum(*a)).value;
	clear_stack(&copy);
	return (follow);
}

void	cheaper_move(t_stack **a, t_stack **b)
{
	int	index;
	int	value;
	int	moves_value;
	int	prev;
	int	moves_prev;
	int	min_moves;
	int	min_value;
	int	min_prev;

	if (!*b)
		return ;
	index = -1;
	min_moves = size(a) + size(b);
	while (index++ < (size(a) - 1))
	{
		value = get_value_at(*a, index);
		if ((size(a) / 2) < index_of(*a, value))
			moves_value = size(a) - index_of(*a, value);
		else
			moves_value = index_of(*a, value);
		prev = find_prev(a, b, value);
		if ((size(b) / 2) < index_of(*b, prev))
			moves_prev = size(b) - index_of(*b, prev);
		else
			moves_prev = index_of(*b, prev);
		if (min_moves > (moves_value + moves_prev))
		{
			min_moves = (moves_value + moves_prev);
			min_value = value;
			min_prev = prev;
		}
	}
	while((**b).value != min_prev && (size(b) / 2) < index_of(*b, min_prev) && (**a).value != min_value && (size(a) / 2) < index_of(*a, min_value))
			perform_and_log(a, b, RRR);
	while((**b).value != min_prev && (size(b) / 2) > index_of(*b, min_prev) && (**a).value != min_value && (size(a) / 2) > index_of(*a, min_value))
			perform_and_log(a, b, RR);
	while ((**b).value != min_prev)
		if ((size(b) / 2) < index_of(*b, min_prev))
			perform_and_log(a, b, RRB);
		else
			perform_and_log(a, b, RB);
	while ((**a).value != min_value)
		if ((size(a) / 2) < index_of(*a, min_value))
			perform_and_log(a, b, RRA);
		else
			perform_and_log(a, b, RA);
}

void	economic_move(t_stack **a, t_stack **b)
{
	int	index;
	int	value;
	int	moves_value;
	int	follow;
	int	moves_follow;
	int	min_moves;
	int	min_value;
	int	min_follow;

	index = -1;
	min_moves = size(a) + size(b);
	while (index++ < (size(b) - 1))
	{
		value = get_value_at(*b, index);
		if ((size(b) / 2) < index_of(*b, value))
			moves_value = size(b) - index_of(*b, value);
		else
			moves_value = index_of(*b, value);
		follow = find_following(a, b, value);
		if ((size(a) / 2) < index_of(*a, follow))
			moves_follow = size(a) - index_of(*a, follow);
		else
			moves_follow = index_of(*a, follow);
		if (min_moves > (moves_value + moves_follow))
		{
			min_moves = (moves_value + moves_follow);
			min_value = value;
			min_follow = follow;
		}
	}
	while((**a).value != min_follow && (size(a) / 2) < index_of(*a, min_follow) && (**b).value != min_value && (size(b) / 2) < index_of(*b, min_value))
			perform_and_log(a, b, RRR);
	while((**a).value != min_follow && (size(a) / 2) > index_of(*a, min_follow) && (**b).value != min_value && (size(b) / 2) > index_of(*b, min_value))
			perform_and_log(a, b, RR);
	while ((**a).value != min_follow)
		if ((size(a) / 2) < index_of(*a, min_follow))
			perform_and_log(a, b, RRA);
		else
			perform_and_log(a, b, RA);
	while ((**b).value != min_value)
		if ((size(b) / 2) < index_of(*b, min_value))
			perform_and_log(a, b, RRB);
		else
			perform_and_log(a, b, RB);
}

void	smash_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;

	if (size(a) == 2 && (**a).value > ((*(**a).next).value))
		return (perform_and_log(a, b, SA));
	while (size(a) > 3 && !stack_is_sorted(*a))
	{
		cheaper_move(a, b);
		perform_and_log(a, b, PB);
	}
	trident_sort(a, b);
	while (*b)
	{
		economic_move(a, b);
		perform_and_log(a, b, PA);
	}
	min = minimum(*a);
	while (*a != min)
	{
		if ((size(a) / 2) < index_of(*a, (*min).value))
			perform_and_log(a, b, RRA);
		else
			perform_and_log(a, b, RA);
	}
}

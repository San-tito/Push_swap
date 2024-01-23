/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:13:33 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/23 07:42:17 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	look_for_cheaper(t_stack **a, t_stack **b)
{
	int	value;
	int	prev;
	int	moves;
	int	index;
	int	min_moves;
	int	cheap_value;

	index = -1;
	min_moves = size(a) + size(b);
	cheap_value = (**a).value;
	while (index++ < (size(a) - 1))
	{
		value = get_value_at(*a, index);
		if ((size(a) * 0.5) < index_of(*a, value))
			moves = size(a) - index_of(*a, value);
		else
			moves = index_of(*a, value);
		prev = find_prev(a, b, value);
		if ((size(b) * 0.5) < index_of(*b, prev))
			moves += size(b) - index_of(*b, prev);
		else
			moves += index_of(*b, prev);
		if (min_moves > moves)
		{
			min_moves = moves;
			cheap_value = value;
		}
	}
	return (cheap_value);
}

static void	cheaper_move(t_stack **a, t_stack **b)
{
	int	value;
	int	prev;

	if (!*b)
		return ;
	value = look_for_cheaper(a, b);
	prev = find_prev(a, b, value);
	while ((**b).value != prev && (size(b) * 0.5) < index_of(*b, prev)
		&& (**a).value != value && (size(a) * 0.5) < index_of(*a, value))
		perform_and_log(a, b, RRR);
	while ((**b).value != prev && (size(b) * 0.5) > index_of(*b, prev)
		&& (**a).value != value && (size(a) * 0.5) > index_of(*a, value))
		perform_and_log(a, b, RR);
	while ((**b).value != prev)
		if ((size(b) * 0.5) < index_of(*b, prev))
			perform_and_log(a, b, RRB);
		else
			perform_and_log(a, b, RB);
	while ((**a).value != value)
		if ((size(a) * 0.5) < index_of(*a, value))
			perform_and_log(a, b, RRA);
		else
			perform_and_log(a, b, RA);
}

static int	look_for_economic(t_stack **a, t_stack **b)
{
	int	value;
	int	follow;
	int	moves;
	int	index;
	int	min_moves;
	int	cheap_value;

	index = -1;
	min_moves = size(a) + size(b);
	cheap_value = (**b).value;
	while (index++ < (size(b) - 1))
	{
		value = get_value_at(*b, index);
		if ((size(b) * 0.5) < index_of(*b, value))
			moves = size(b) - index_of(*b, value);
		else
			moves = index_of(*b, value);
		follow = find_following(a, b, value);
		if ((size(a) * 0.5) < index_of(*a, follow))
			moves += size(a) - index_of(*a, follow);
		else
			moves += index_of(*a, follow);
		if (min_moves > moves)
		{
			min_moves = moves;
			cheap_value = value;
		}
	}
	return (cheap_value);
}

static void	economic_move(t_stack **a, t_stack **b)
{
	int	value;
	int	follow;

	value = look_for_economic(a, b);
	follow = find_following(a, b, value);
	while ((**a).value != follow && (size(a) * 0.5) < index_of(*a, follow)
		&& (**b).value != value && (size(b) * 0.5) < index_of(*b, value))
		perform_and_log(a, b, RRR);
	while ((**a).value != follow && (size(a) * 0.5) > index_of(*a, follow)
		&& (**b).value != value && (size(b) * 0.5) > index_of(*b, value))
		perform_and_log(a, b, RR);
	while ((**a).value != follow)
		if ((size(a) * 0.5) < index_of(*a, follow))
			perform_and_log(a, b, RRA);
		else
			perform_and_log(a, b, RA);
	while ((**b).value != value)
		if ((size(b) * 0.5) < index_of(*b, value))
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
		if ((size(a) * 0.5) < index_of(*a, (*min).value))
			perform_and_log(a, b, RRA);
		else
			perform_and_log(a, b, RA);
	}
}

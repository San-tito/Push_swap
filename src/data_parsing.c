/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:22:46 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/23 16:31:38 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(unsigned char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

static int	ft_isdigit(int c)
{
	return (48 <= c && c <= 57);
}

int	ft_atoi(char *str, int *has_error)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
		n = (n * 10) + (*str++ - '0');
	n *= sign;
	if (INT_MIN > n || n > INT_MAX)
		*has_error = 1;
	return (n);
}

void	validate_syntax(char *str, int *has_error)
{
	int	i;

	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	i = 0;
	while (ft_isdigit(*(str + i)))
		i++;
	if (*(str + i) || i > 10)
		*has_error = 1;
}

void	search_for_duplicate(t_stack *stack, int value, int *has_error)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if ((*current).value == value)
			*has_error = 1;
		current = (*current).next;
	}
}

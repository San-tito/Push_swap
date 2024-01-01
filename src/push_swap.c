/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:51:19 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/01 19:11:16 by sguzman          ###   ########.fr       */
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
	{
		n = (n * 10) + (*str++ - '0');
		if (INT_MIN > n || n > INT_MAX)
			*has_error = 1;
	}
	return (n * sign);
}

void	validate_syntax(char *str, int *has_error)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str)
		*has_error = 1;
}

void	setup_stack(t_stack *stack, char **argv)
{
	int	has_error;

	has_error = 0;
	while (*argv)
	{
		validate_syntax(*argv, &has_error);
		ft_atoi(*argv, &has_error);
		if (has_error)
			exit(1);
		argv++;
	}
	(void)stack;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 3 || !*argv)
		return (1);
	setup_stack(&a, argv + 1);
	(void)b;
	return (0);
}

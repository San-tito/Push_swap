/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:58:28 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/05 10:01:43 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	display_colored(char *s, char *color, int fd)
{
	ft_putstr(color, fd);
	ft_putstr(s, fd);
	ft_putstr(RESET, fd);
}

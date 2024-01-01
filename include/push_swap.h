/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:49:26 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/01 19:27:21 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                Stack definition                            */
/* ************************************************************************** */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* ************************************************************************** */
/*                          Argument parsing functions                        */
/* ************************************************************************** */
int					ft_atoi(char *str, int *has_error);
void				validate_syntax(char *str, int *has_error);

#endif

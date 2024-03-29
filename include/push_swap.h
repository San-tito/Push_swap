/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:49:26 by sguzman           #+#    #+#             */
/*   Updated: 2024/01/23 07:24:07 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[m"

/* ************************************************************************** */
/*                           Definition of the Stack Structure                */
/* ************************************************************************** */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_operation
{
	char			*order;
	void			(*command)(t_stack **, t_stack **);
}					t_operation;

/* ************************************************************************** */
/*                          Argument Parsing Functions                        */
/* ************************************************************************** */
char				*get_next_line(int fd);
int					ft_atoi(char *str, int *has_error);
void				validate_syntax(char *str, int *has_error);
void				search_for_duplicate(t_stack *stack, int value,
						int *has_error);

/* ************************************************************************** */
/*                              Stack Methods                                 */
/* ************************************************************************** */
void				push(t_stack **stack, int value);
void				pop(t_stack **stack);
void				clear_stack(t_stack **stack);
int					size(t_stack **stack);

/* ************************************************************************** */
/*                               Stack Setup                                  */
/* ************************************************************************** */
void				setup_stack(t_stack **stack, char **argv, int argc);
int					stack_is_sorted(t_stack *stack);
t_operation			*init_instructions(void);
void				wipe(t_stack **a, t_stack **b);
t_stack				*copy_stack(t_stack *stack);

/* ************************************************************************** */
/*                           Output-related Functions                         */
/* ************************************************************************** */
void				display_colored(char *s, char *color, int fd);
void				perform_and_log(t_stack **a, t_stack **b, int index);

/* ************************************************************************** */
/*                               Sorting Algorithm                            */
/* ************************************************************************** */
void				smash_sort(t_stack **a, t_stack **b);
void				trident_sort(t_stack **a, t_stack **b);
void				bubble_sort(t_stack *stack);

/* ************************************************************************** */
/*                                 Sorting Utils                              */
/* ************************************************************************** */
t_stack				*minimum(t_stack *stack);
int					get_value_at(t_stack *stack, int wanted);
int					index_of(t_stack *stack, int wanted);
int					find_prev(t_stack **a, t_stack **b, int value);
int					find_following(t_stack **a, t_stack **b, int value);

/* ************************************************************************** */
/*                                Operations                                  */
/* ************************************************************************** */
void				sa(t_stack **a, t_stack **b);
void				sb(t_stack **a, t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a, t_stack **b);
void				rb(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, t_stack **b);
void				rrb(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* ************************************************************************** */
/*                           Macros for Command Indices                       */
/* ************************************************************************** */
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

#endif

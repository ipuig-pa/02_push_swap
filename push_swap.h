/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:06:02 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/06 12:54:51 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
//eliminar stdio.h
#include "stdio.h"
//# include "libft.h"
//eliminar atoi i strlen daqui si es posa libft

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int		display_error(void);
int		is_valid_input(int argc, char **argv, int *arr);
int		is_int(char *str);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

t_stack	*ft_lstlast(t_stack *stack);
int		ft_lstsize(t_stack *stack);
int		ft_lstpos(t_stack *current, t_stack *interrogated);
t_stack	*clear_stack(t_stack *stack);

int		main(int argc, char **argv);
t_stack	*parse_in_stack(int argc, int *arr);
void	sort_stack_a(t_stack **stack_top, t_stack **st_a, t_stack **st_b);
void	sort_stack_b(t_stack **stack_top, t_stack **st_a, t_stack **st_b);
void	exec_and_print(char *command, t_stack **st_a, t_stack **st_b);

void	swap(t_stack **stack);
void	push(t_stack **stack_source, t_stack **stack_destination);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

#endif

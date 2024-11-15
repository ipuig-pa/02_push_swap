/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:06:02 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/15 14:59:38 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
//eliminar stdio.h
# include <stdio.h>
//# include "libft.h"
//eliminar atoi i strlen daqui si es posa libft

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		display_error(void);
int		is_valid_input(int argc, char **argv, int *arr);
int		is_int(char *str);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_sqrt(int nb);

t_stack	*ft_lstlast(t_stack *stack);
int		ft_lstsize(t_stack *stack);
int		ft_lstpos(t_stack *current, t_stack *interrogated);
t_stack	*clear_stack(t_stack *stack);
int		is_order(t_stack *stack);
int		is_arr_order(int *arr, int size);
int		is_inverse_order(t_stack *stack);

int		main(int argc, char **argv);
t_stack	*parse_in_stack(int argc, int *arr);
void	assign_index(t_stack *stack);
void	sort_stack_a(t_stack **st_a, t_stack **st_b);
//void	sort_stack_b(t_stack **st_a, t_stack **st_b);
//void	prepare_b_to_recieve(t_stack **st_a, t_stack **st_b);
void	exec_and_print(char *command, char stack_id, t_stack **st_a, t_stack **st_b);
char	*print_command (char *previous_command, char *command, char previous_id, char stack_id);

void	swap(t_stack **stack);
void	push(t_stack **stack_source, t_stack **stack_destination);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

#endif

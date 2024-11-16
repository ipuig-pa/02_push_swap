/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:06:02 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/16 13:32:00 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		display_error(void);
int		handle_error(int flag, char **argv, int *arr);
int		arrlen(char **arr);
int		valid_input_to_arr(int count, char **argv, int *arr);
int		is_int(char *str);
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
t_stack	*assign_index(t_stack *stack);
void	sort_stack_a(t_stack **st_a);
void	small_size_sort(int size, t_stack **st_a);
void	big_size_sort(int size, t_stack **st_a);
t_stack	**move_to_b(int size, t_stack **st_a, t_stack **st_b);
void	back_to_a(int size, t_stack **st_a, t_stack **st_b);
void	exec_and_print(char *comm, char st_id, t_stack **st_a, t_stack **st_b);
char	*print(char *prev_comm, char *comm, char prev_id, char st_id);



void	swap(t_stack **stack);
void	push(t_stack **stack_source, t_stack **stack_destination);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

#endif

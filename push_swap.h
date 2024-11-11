/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:06:02 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/11 10:38:20 by ipuig-pa         ###   ########.fr       */
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

int		display_error(void);
int		create_array(int argc, char **argv, int *arr);
int		is_int(char *str);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

int		main(int argc, char **argv);
void	sort_stack_a(int *st_a, int *st_b, int a_size, int b_size);
void	sort_stack_b(int *st_a, int *st_b, int a_size, int b_size);
void	exec_and_print(char *command, char stack_id, int *st_a, int *st_b, int a_size, int b_size);
char	*print_command (char *previous_command, char *command, char previous_id, char stack_id);

int		a_is_in_order(int *stack, int size);
void	swap(int *stack);
void	push(int *stack_destination, int *stack_source, int s_size, int d_size);
void	rotate(int *stack, int size);
void	reverse_rotate(int *stack, int size);
void	push_index(int *stack, char c, int size);

#endif

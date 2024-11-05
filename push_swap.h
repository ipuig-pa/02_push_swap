/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:06:02 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/05 14:47:56 by ipuig-pa         ###   ########.fr       */
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
//eliminar atoi daqui si es posa libft

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int		display_error(void);
int		is_valid_input(int argc, char **argv, int *arr);
int		is_int(char *str);
int		ft_atoi(const char *str);

t_stack	*clear_stack(t_stack *stack);

int		main(int argc, char **argv);
t_stack	*parse_in_stack(int argc, int *arr);

#endif

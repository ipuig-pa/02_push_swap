/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:56:32 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/07 12:12:14 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*command;

	somehow call push_swap program with the argument of the checker and wait;
	command = get_next_line(); //posar get_next_line a libft;
	if (!command_is_valid)
		display_error;
	exec(command, st_a, st_b);
	if (st_b == NULL)
	{
		current = st_a;
		while (current->next != NULL)
		{
			if (current->content > current->next->content)
			{
				return ;
				printf("KO\n");
			}
			current = current->next;
		}
		printf("OK\n");
	}

}
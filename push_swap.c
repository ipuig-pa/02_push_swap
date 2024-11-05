/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/11/05 18:13:32 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//eliminar stdio.h, canviar printf per ft_printf

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*current;
	int		*arr;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (!arr || !is_valid_input(argc, argv, arr))
	{
		if (arr)
			free(arr);
		return (display_error());
	}
	stack_a = parse_in_stack(argc, arr);
	free(arr);
	if (!stack_a)
		return (display_error());
	get_instructions(stack_a, stack_a);
	// current = stack_a;
	// while (current != NULL)
	// {
	// 	printf("%i, ", current->content);
	// 	current = current->next;
	// }
	// clear_stack(stack_a);
	return (0);
}

t_stack	*parse_in_stack(int argc, int *arr)
{
	t_stack	*stack_a;
	t_stack	*current;
	t_stack	*new;
	int		i;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->content = arr[0];
	i = 1;
	current = stack_a;
	while (i + 1 < argc)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (clear_stack(stack_a));
		new->content = arr[i];
		current->next = new;
		current = new;
		i++;
	}
	current->next = NULL;
	return (stack_a);
}

void	get_instructions(t_stack *stack_top, t_stack *current)
{
	t_stack	*current;
	t_stack	*bottom;
	int		size;
	int		node_pos;

	current = stack_top;
	if (current->content > (current->next)->content)
	{
		stack_bottom = ft_lstlast(stack_top);
		size = ft_lstsize(stack_top);
		node_position = ft_lstpos(current);
		if (stack_top->conent > stack_bottom->content)
		{
			//Agrupar en una funcio rotate que valori internament si hem de fer normal o reverse rotate
			if (node_position < size / 2)
			{
				while (node_position >= 1)
				{
					ra(stack_top);
					node_position--;
				}
			}
			else
			{
				while (node_position < size)
				{
					rra(stack_top);
					node_position++;
				}
			}
		}
		else
		{
			//mirar si es mes alt que el del pilo B i si cal correr el pilo B, cap amunt o cap avall
			if (curr_a)
			//mirar si cal posar coses anteriors a B? --> tot el que queda per sobre del conflictiu
			while (i < curr_a)
			{
				pb;
				b_length++;
				//cada vegada que passi algun a B he de tornar a fer l-algoritme de B per mirar si s-han de reordenar a B (ordenar a la inversa de A)
				i++;
			}
			stack_top = swap(stack_top, a);
		}
	}
	if (current < size)
		get_instructions(stack_top, current);
	else
	{
		while (b_length > 0)
		{
			pa;
			i++;
		}
	}
	return (stack_top)
}

t_stack	*swap(t_stack	*stack_top, char c)
{
	t_stack *temp;

	//posar d-alguna manera segons si c es a, b o s. 
	temp = stack_top->next;
	stack_top->next = stack_top->next->next;
	temp->next = stack_top;
	stack_top = temp;
	printf("s%c\n", c);
	return (stack_top);
}


	return (stack_top)
	
	if (stack == 'a')
	{
		
		printf("sa");
	}
	else if (stack == 'b')
	{
		printf("sb");
	}
	else
	{
		printf("ss")
	}
}

t_stack	*push(t_stack *stack_top)
{
	//addatstart of B node stack_top
	

	if (stack == 'a')

	else if (stack == 'b')
}
void	rotate(char	stack)
{
	if (stack == 'a' || stack == 'r')

	if (stack == 'b' || stack == 'r')

}

void	reverse_rotate(char	stack)
{
	if (stack == 'a' || stack == 'r')

	if (stack == 'b' || stack == 'r')

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:52:07 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/15 13:31:34 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_message(t_list *s_a, t_list *s_b, char *filename, char **strs)
{
	int i;

	i = 0;
	ft_printf_2("Error\n");
	free_stack(s_a);
	free_stack(s_b);
	if(filename == NULL)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++
		}
		free(strs);
	}
	exit(0);
}

void	free_stack(t_list *stack)
{
	t_list *tmp;
	
	if(stack != NULL && stack != NULL)
	{
		while(stack && stack)
		{
			tmp = stack;
			stack = stack->next;
			free(tmp);
		}
	}
}

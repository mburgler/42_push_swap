/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:52:07 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/26 19:13:36 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*free_null(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	return (NULL);
}

void	error_message(t_msc *msc)
{
	ft_printf_2("Error\n");
	free_finished(msc);
}

void	free_finished(t_msc *msc)
{
	int	i;

	i = 0;
	free_stack(msc->s_a);
	free_stack(msc->s_b);
	if (msc->strs_split != NULL)
	{
		while (msc->strs_split[i])
		{
			msc->strs_split[i] = free_null(msc->strs_split[i]);
			i++;
		}
		free_null(msc->strs_split);
	}
	free_null(msc);
	exit(1);
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	if (stack != NULL)
	{
		while (stack)
		{
			tmp = stack;
			stack = stack->next;
			free_null(tmp);
		}
	}
}

void	msc_alloc_fail(t_msc *msc)
{
	if (msc == NULL)
	{
		ft_printf_2("Error\nAllocation failed\n");
		exit(1);
	}
}

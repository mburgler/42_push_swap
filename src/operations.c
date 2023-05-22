/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:06:35 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/21 14:46:39 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// t_list indicates to which stack to push
void	push(t_msc *msc, t_list *pushto, t_list *pushfrom)
{
	t_list	*new_node;
	t_list	*tmp;
	
	if(pushfrom == NULL)
		return ;
	new_node = calloc_check_error(1, sizeof(t_list));
	new_node->data = pushfrom->data;
	new_node->index = pushfrom->index;
	new_node->next = pushto;
	if(msc->s_a == pushto)
	{
		msc->s_a = new_node;
		tmp = msc->s_b;
		msc->s_b = msc->s_b->next;
		free_null(tmp);
	}
	else if(msc->s_b == pushto)
	{
		msc->s_b = new_node;
		tmp = msc->s_a;
		msc->s_a = msc->s_a->next;
		free_null(tmp);
	}
}

// t_list indicates which stack to rotate
void	rotate(t_msc *msc, t_list *stack)
{
	t_list *new_bottom;

	if(stack == NULL || stack->next == NULL)
		return ;
	new_bottom = stack;
	while(new_bottom->next)
		new_bottom = new_bottom->next;
	new_bottom->next = stack;
	if(msc->s_a == stack)
		msc->s_a = stack->next;
	else if(msc->s_b == stack)
		msc->s_b = stack->next;
	new_bottom->next->next = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:06:35 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/25 21:10:23 by mburgler         ###   ########.fr       */
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
		ft_printf("pa\n");
	}
	else if(msc->s_b == pushto)
	{
		msc->s_b = new_node;
		tmp = msc->s_a;
		msc->s_a = msc->s_a->next;
		free_null(tmp);
		ft_printf("pb\n");
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
	{
		msc->s_a = stack->next;
		ft_printf("ra\n");
	}
	else if(msc->s_b == stack)
	{
		msc->s_b = stack->next;
		ft_printf("rb\n");
	}
	new_bottom->next->next = NULL;
}

void	swap_a(t_msc *msc)
{
	t_list *tmp;

	if(msc->s_a == NULL || msc->s_a->next == NULL)
		return ;
	tmp = msc->s_a->next;
	msc->s_a->next = tmp->next;
	tmp->next = msc->s_a;
	msc->s_a = tmp;
	ft_printf("sa\n");
}

void	rra(t_msc *msc)
{
	t_list *tmp;
	t_list *new_bottom;

	if(msc->s_a == NULL || msc->s_a->next == NULL)
		return ;
	new_bottom = msc->s_a;
	while(new_bottom->next->next)
		new_bottom = new_bottom->next;
	tmp = new_bottom->next;
	new_bottom->next = NULL;
	tmp->next = msc->s_a;
	msc->s_a = tmp;
	ft_printf("rra\n");
}

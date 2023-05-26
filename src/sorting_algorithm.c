/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:42:24 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/26 16:32:52 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	elements_in_stack(t_list *stack)
{
	t_list	*tmp;
	int		nb_of_elements;

	tmp = stack;
	nb_of_elements = 0;
	while (tmp)
	{
		nb_of_elements++;
		tmp = tmp->next;
	}
	return (nb_of_elements);
}

int	check_if_sorted(t_msc *msc)
{
	t_list	*tmp;

	if (msc->s_a == NULL)
		return (1);
	tmp = msc->s_a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	if (msc->s_b == NULL)
		return (1);
	tmp = msc->s_b;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	binary_radix_sort(t_msc *msc)
{
	int	bitshift;
	int	nb_elements;

	bitshift = 0;
	while (bitshift < msc->nb_bits)
	{
		nb_elements = elements_in_stack(msc->s_a);
		while (nb_elements != 0)
		{
			if (check_if_sorted(msc) == 1)
				return ;
			if (((msc->s_a->index >> bitshift) & 1) == 0)
				push(msc, msc->s_b, msc->s_a);
			else
				rotate(msc, msc->s_a);
			nb_elements--;
		}
		nb_elements = elements_in_stack(msc->s_b);
		binary_radix_sort_p2(msc, nb_elements, bitshift);
		bitshift++;
	}
}

void	binary_radix_sort_p2(t_msc *msc, int nb_elements, int bitshift)
{
	while (nb_elements != 0)
	{
		if (check_if_sorted(msc) == 1)
			return ;
		if (((msc->s_b->index >> (bitshift + 1)) & 1) == 1)
			push(msc, msc->s_a, msc->s_b);
		else
			rotate(msc, msc->s_b);
		nb_elements--;
	}
}

void	push_back(t_msc *msc)
{
	int	nb_elements;

	nb_elements = elements_in_stack(msc->s_b);
	while (nb_elements != 0)
	{
		push(msc, msc->s_a, msc->s_b);
		nb_elements--;
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:42:24 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/21 21:03:36 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	index_stack(t_msc *msc)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = msc->s_a;
	while(tmp)
	{
		tmp2 = msc->s_a;
		while(tmp2)
		{
			if(tmp->data < tmp2->data)
				tmp2->index++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	nmb_bits(msc);
}

void	nmb_bits(t_msc *msc)
{
	t_list	*tmp;
	int		highest_index;

	tmp = msc->s_a->next;
	msc->nb_of_indexes = 0;
	msc->nb_bits = 0;
	while(tmp)
	{
		msc->nb_of_indexes++;
		tmp = tmp->next;
	}
	tmp = msc->s_a;
	highest_index = msc->nb_of_indexes;
	while(highest_index)
	{
		msc->nb_bits++;
        highest_index >>= 1;
	}
}

void	binary_radix_sort(t_msc *msc)
{
	int		nb_count;
	int		shift;
	int		controlled_index;
	t_list	*tmp;

	shift = 0;
	nb_count = msc->nb_of_indexes;
	tmp = msc->s_a;
	while(nb_count)
	{
		while(nb_of_indexes)
		{
			controlled_index = tmp->index;
			if((tmp->index >> shift) & 1)
				push_b(msc, msc->s_a);
			else
				rotate_a(msc, msc->s_a);
			msc->nb_bits--;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:42:24 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/24 18:00:00 by mburgler         ###   ########.fr       */
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

int	elements_in_stack(t_list *stack)
{
	t_list	*tmp;
	int		nb_of_elements;

	tmp = stack;
	nb_of_elements = 0;
	while(tmp)
	{
		nb_of_elements++;
		tmp = tmp->next;
	}
	return (nb_of_elements);
}

void	binary_radix_sort(t_msc *msc)
{
// 	int		nb_count;
// 	int		shift;
// 	int		controlled_index;
// 	t_list	*tmp;

// 	shift = 0;
// 	nb_count = msc->nb_of_indexes;
// 	tmp = msc->s_a;
// 	while(nb_count)
// 	{
// 		while(nb_of_indexes)
// 		{
// 			controlled_index = tmp->index;
// 			if((tmp->index >> shift) & 1)
// 				push_b(msc, msc->s_a);
// 			else
// 				rotate_a(msc, msc->s_a);
// 			msc->nb_bits--;
// 		}
// 	}
// // OLD ABOVE

	int	bitshift;
	int	nb_elements;

	bitshift = 0;
	while(bitshift < msc->nb_bits)
	{
		nb_elements = elements_in_stack(msc->s_a);
		while(nb_elements != 0)
		{
			if((msc->s_a->index >> bitshift) & 1)
				push(msc, msc->s_b, msc->s_a); //push_to; push_from
			else
				rotate(msc, msc->s_a);
			nb_elements--;
		}
		nb_elements = elements_in_stack(msc->s_b);
		while(nb_elements != 0)
		{
			if((msc->s_b->index >> (bitshift + 1)) & 0)
				push(msc, msc->s_a, msc->s_b); //push_to; push_from
			else
				rotate(msc, msc->s_b);
			nb_elements--;
		}
		bitshift++;
	}
	nb_elements = elements_in_stack(msc->s_b);
	while (nb_elements != 0)
	{
		push(msc, msc->s_a, msc->s_b);
		nb_elements--;
	}	
}


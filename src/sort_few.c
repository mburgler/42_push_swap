/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:08:39 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/26 18:01:45 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_few(t_msc *msc, t_list *s_a)
{
	if (check_if_sorted(msc) == 1)
		push_back(msc);
	if (msc->nb_of_indexes + 1 == 2)
		swap_a(msc);
	else if (msc->nb_of_indexes + 1 == 3)
		sort_three(msc, s_a, 0);
	else if (msc->nb_of_indexes + 1 == 4)
	{
		min_to_top_push(msc, 0);
		sort_three(msc, msc->s_a, 1);
		push(msc, msc->s_a, msc->s_b);
	}
	else if (msc->nb_of_indexes + 1 == 5)
	{
		min_to_top_push(msc, 0);
		min_to_top_push(msc, 1);
		sort_three(msc, msc->s_a, 2);
		push(msc, msc->s_a, msc->s_b);
		push(msc, msc->s_a, msc->s_b);
	}
	push_back(msc);
}

void	min_to_top_push(t_msc *msc, int index)
{
	if (msc->s_a->index == index || msc->s_a->next->index == index
		|| msc->s_a->next->next->index == index)
	{
		while (msc->s_a->index != index)
			rotate(msc, msc->s_a);
	}
	else
	{
		while (msc->s_a->index != index)
			rra(msc);
	}
	push(msc, msc->s_b, msc->s_a);
}

void	sort_three(t_msc *msc, t_list *s_a, int f)
{
	int	sn;
	int	snn;

	sn = s_a->next->index;
	snn = s_a->next->next->index;
	if (s_a->index == (1 + f) && sn == (0 + f) && snn == (2 + f))
		swap_a(msc);
	else if (s_a->index == (2 + f) && sn == (1 + f) && snn == (0 + f))
	{
		swap_a(msc);
		rra(msc);
	}
	else if (s_a->index == (2 + f) && sn == (0 + f) && snn == (1 + f))
		rotate(msc, msc->s_a);
	else if (s_a->index == (0 + f) && sn == (2 + f) && snn == (1 + f))
	{
		swap_a(msc);
		rotate(msc, msc->s_a);
	}
	else if (s_a->index == (1 + f) && sn == (2 + f) && snn == (0 + f))
		rra(msc);
}

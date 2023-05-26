/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:07:15 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/26 19:13:09 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_doubles(t_msc *msc)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = msc->s_a;
	tmp2 = msc->s_a;
	if (!tmp)
		error_message(msc);
	while (tmp->next)
	{
		while (tmp2->next)
		{
			if (tmp->data == tmp2->next->data)
				error_message(msc);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp;
	}
}

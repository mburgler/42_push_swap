/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteobuergler <matteobuergler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:07:15 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/15 22:40:43 by matteobuerg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_doubles(t_msc *msc)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = msc->s_a;
	tmp2 = msc->s_a;
	while(tmp->next)
	{
		while(tmp2->next)
		{
			if(tmp->data == tmp2->next->data)
				error_message("Double detected\n", msc);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp;
	}
}

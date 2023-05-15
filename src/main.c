/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteobuergler <matteobuergler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:43 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/15 17:00:58 by matteobuerg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init(t_msc *msc)
{
	msc->s_a = NULL;
	msc->s_b = NULL;
	msc->strs_split = NULL;
}

int	main(int argc, char **argv)
{
	t_msc	*msc;

	msc = ft_calloc(1, sizeof(t_msc));	
	init(msc);
	if (argc == 1)
		error_message("Missing arguments", msc);
	else if (argc == 2)
	{
		msc->strs_split = ft_split(argv[1], ' ');
		parsing(msc->strs_split, msc);
	}
	else
		parsing(argv, msc);
	msc->s_b = ft_calloc(1, sizeof(t_list));
	if(!msc->s_b)
		error_message("Allocation fault", msc);
	
	//TESTER
	t_list *tmp;
	tmp = msc->s_a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	error_message("NO ERROR, just to free", msc);
	return (0);
}

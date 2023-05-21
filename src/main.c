/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:43 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/19 19:25:50 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init(t_msc *msc)
{
	msc->s_a = NULL;
	msc->s_b = NULL;
	msc->strs_split = NULL;
}

void *calloc_check_error(int nmemb, int size)
{
	void *ptr;
	ptr = ft_calloc(nmemb, size);
	if (ptr == NULL)
	{
		write(2, "Error\nAllocation failed\n", 24);
		exit(1);
	}
	return(ptr);
}

int	main(int argc, char **argv)
{
	t_msc	*msc;

	msc = NULL;
	msc = calloc_check_error(1, sizeof(t_msc));	
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
	msc->s_b = calloc_check_error(1, sizeof(t_list));
	index_stack(msc);
	//TESTER
	t_list *tmp;
	tmp = msc->s_a;
	while (tmp)
	{
		ft_printf("###DEBUG STACK A### no %d mit index %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
	tmp = msc->s_b;
	while (tmp)
	{
		ft_printf("###DEBUG STACK B### no %d mit index %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
	ft_printf("\n### AFTER PUSH ###\n\n");
	push(msc, msc->s_b, msc->s_a);
	rotate(msc, msc->s_a);
	tmp = msc->s_a;
	while (tmp)
	{
		ft_printf("###DEBUG STACK A### no %d mit index %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
	tmp = msc->s_b;
	while (tmp)
	{
		ft_printf("###DEBUG STACK B### no %d mit index %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
	ft_printf("###DEBUG### nb of indexes %d\n", msc->nb_of_indexes);
	ft_printf("###DEBUG### nb of bits %d\n", msc->nb_bits);
	error_message("NO ERROR, just to free", msc);
	return (0);
}

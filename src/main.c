/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:43 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/26 01:33:35 by mburgler         ###   ########.fr       */
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

	if (argc == 1)
		exit(1);
	msc = NULL;
	msc = calloc_check_error(1, sizeof(t_msc));	
	init(msc);
	if (argc == 2)
	{
		msc->strs_split = ft_split(argv[1], ' ');
		parsing(msc->strs_split, msc);
	}
	else
		parsing(argv, msc);
	index_stack(msc);
	if( msc->nb_of_indexes + 1 <= 5)
		sort_few(msc, msc->s_a);
	else
	{
		binary_radix_sort(msc);
		push_back(msc);
	}
	free_finished(msc);
	return (0);
}

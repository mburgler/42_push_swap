/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:43 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/25 16:04:57 by mburgler         ###   ########.fr       */
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
	index_stack(msc);
	binary_radix_sort(msc);
	return (0);
}

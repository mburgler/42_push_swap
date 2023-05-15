/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:43 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/15 13:35:20 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*s_a;
	t_list	*s_b;
	char	*filename;
	char	**strs;

	s_a = NULL;
	s_b = NULL;
	filename = NULL;
	strs = NULL;
	if (argc == 1)
		error_message(NULL, NULL, NULL, NULL);
	else if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		s_a = parsing(strs, s_a, s_b, filename);
	}
	else
	{
		filename = argv[0];
		s_a = parsing(argv, s_a, s_b, filename);
	}
	s_b = ft_calloc(1, sizeof(t_list));
	if(!s_b)
		error_message(s_a, s_b, filename, strs);
	
	//TESTER
	while (s_a)
	{
		ft_printf("%d\n", s_a->data);
		s_a = s_a->next;
	}
	error_message(s_a, s_b, filename, strs);
	return (0);
}

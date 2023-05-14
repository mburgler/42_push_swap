/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:43 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/14 17:52:01 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*s_a;
	t_list	*s_b;

	s_a = NULL;
	s_b = NULL;
	if (argc == 1)
		error_message("Too few arguments\n", NULL, NULL);
	if (argc == 2)
		s_a = parsing(ft_split(argv[1], ' '), s_a, s_b, NULL);
	else
		s_a = parsing(argv, s_a, s_b, argv[0]);
	s_b = ft_calloc(1, sizeof(t_list));
	if(!s_b)
		error_message("Allocating stacks failed\n", s_a, s_b);
	
	//TESTER
	while (s_a)
	{
		ft_printf("%d\n", s_a->data);
		s_a = s_a->next;
	}
	error_message("NO ERROR -> statement just for freeing\n", s_a, s_b);
	return (0);
}

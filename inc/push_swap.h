/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:52 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/26 19:12:56 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../MY_LIB/ft_printf/ft_printf.h"
# include "../MY_LIB/ft_printf2/ft_printf2.h"
# include "../MY_LIB/get_next_line/get_next_line_bonus.h"

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}			t_list;

typedef struct s_msc
{
	t_list	*s_a;
	t_list	*s_b;
	char	*filename;
	char	**strs_split;
	int		nb_of_indexes;
	int		nb_bits;

}			t_msc;

//main.c
void	init(t_msc *msc);
void	*calloc_check_error(t_msc *msc, int nmemb, int size);

//error_handler.c
void	error_message(t_msc *msc);
void	free_finished(t_msc *msc);
void	free_stack(t_list *stack);
void	*free_null(void *ptr);
void	msc_alloc_fail(t_msc *msc);

//parsing.c
int		plus_minus_space(char *str, int i);
void	forbidden_character(char *str, t_msc *msc);
int		check_int_min_max(char *str, int nb);
void	append_node(char *str, t_msc *msc);
void	parsing(char **strs, t_msc *msc);

//check_doubles.c
void	check_doubles(t_msc *msc);

//indexing.c
void	index_stack(t_msc *msc);
void	nmb_bits(t_msc *msc);

//sort_few.c
void	sort_few(t_msc *msc, t_list *s_a);
void	min_to_top_push(t_msc *msc, int index);
void	sort_three(t_msc *msc, t_list *s_a, int f);

//sorting_agorithm.c
int		elements_in_stack(t_list *stack);
int		check_if_sorted(t_msc *msc);
void	binary_radix_sort(t_msc *msc);
void	binary_radix_sort_p2(t_msc *msc, int nb_elements, int bitshift);
void	push_back(t_msc *msc);

//operations.c
void	push(t_msc *msc, t_list *pushto, t_list *pushfrom);
void	rotate(t_msc *msc, t_list *stack);
void	swap_a(t_msc *msc);
void	rra(t_msc *msc);

#endif

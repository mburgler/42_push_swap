/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:52 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/19 19:25:46 by mburgler         ###   ########.fr       */
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
	int	data;
	int	index;
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
void *calloc_check_error(int nmemb, int size);

//error_handler.c
void	error_message(char *message, t_msc *msc);
void	free_stack(t_list *stack);
void *free_null(void *ptr);

//parsing.c
int	plus_minus_space(char *str, int i);
void	forbidden_character(char *str, t_msc *msc);
int	check_int_min_max(char *str, int nb);
void	append_node(char *str, t_msc *msc);
void	parsing(char **strs, t_msc *msc);

//check_doubles.c
void	check_doubles(t_msc *msc);

//sorting_agorithm.c
void	index_stack(t_msc *msc);
void	nmb_bits(t_msc *msc);

//operations.c
void	push(t_msc *msc, t_list *pushto, t_list *pushfrom);
void	rotate(t_msc *msc, t_list *stack);

#endif

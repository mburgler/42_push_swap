/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteobuergler <matteobuergler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:52 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/15 16:55:40 by matteobuerg      ###   ########.fr       */
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

}			t_msc;


//main.c
void	init(t_msc *msc);

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

#endif
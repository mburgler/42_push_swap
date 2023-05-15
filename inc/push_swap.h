/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:39:52 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/15 13:28:49 by mburgler         ###   ########.fr       */
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

// typedef struct s_msc
// {
// 	struct s_list	*s_a;
// 	struct s_list	*s_b;
// 	struct s_list	*tmp;
// }			t_msc;


//main.c

//error_handler.c
void	error_message(t_list *s_a, t_list *s_b, char *filename, char **strs);
void	free_stack(t_list *stack);

//parsing.c
int	plus_minus_space(char *str, int i);
void	forbidden_character(char *str, t_list *s_a, t_list *s_b, char *filen);
int	check_int_min_max(char *str, int nb, t_list *s_a, t_list *s_b);
t_list	*append_node(t_list *s_a, t_list *s_b, char *str, char *filename);
t_list	*parsing(char **strs, t_list *s_a, t_list *s_b, char *filename);

#endif
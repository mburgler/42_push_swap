/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:04:35 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/14 19:15:25 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	plus_minus_space(char *str, int i)
{
	int	j;

	j = 0;
	while (1)
	{
		if (!"0123456789"[j])
			return (-1);
		if (str[i + 1] == "0123456789"[j++])
			break ;
	}
	return (1);
}

void	forbidden_character(char *str, t_list *s_a, t_list *s_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!"+-0123456789"[j])
			error_message("Forbidden character\n", s_a, s_b);
		if (str[i] == "+-0123456789"[j++])
		{
			if (str[i] == '+' || str[i] == '-')
			{
				if(plus_minus_space(str, i) == -1)
					error_message("Forbidden character after + or -\n", s_a, s_b);
			}
			j = 0;
			i++;
		}
	}
}

void	check_int_min_max(char *str, int nb, t_list *s_a, t_list *s_b)
{
	int	i;
	int	sign;
	int	j;

	sign = 1;
	j = 0;
	if (str[j] == '-')
	{
		sign = -1;
		j++;
	}
	while (str[j] == '+' || str[j] == '0')
		j++;
	i = ft_strlen(str) - 1;
	while (i >= j)
	{
		if (str[i] - '0' != sign * (nb % 10))
			error_message("Max/ min int violated\n", s_a, s_b);
		i--;
		nb = nb / 10;
	}
}

t_list	*append_node(t_list *s_a, t_list *s_b, char *str)
{
	int		nb;
	t_list	*new_node;
	t_list	*tmp;

	forbidden_character(str, s_a, s_b);
	nb = ft_atoi(str);
	check_int_min_max(str, nb, s_a, s_b);
	new_node = ft_calloc(1, sizeof(t_list));
	if (!new_node)
		error_message("Allocating stacks failed\n", s_a, s_b);
	new_node->data = nb;
	new_node->next = NULL;
	if (!s_a)
		return (new_node);
	tmp = s_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (s_a);
}

t_list	*parsing(char **strs, t_list *s_a, t_list *s_b, char *filename)
{
	int	i;

	i = 0;
	if (filename)
		i = 1;
	while (strs[i])
	{
		s_a = append_node(s_a, s_b, strs[i]);
		free(strs[i]);
		i++;
		//FREE IN ERROR FUNCTIONS
	}
	free(strs);
	return (s_a);
}

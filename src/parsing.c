/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:04:35 by mburgler          #+#    #+#             */
/*   Updated: 2023/05/26 19:14:02 by mburgler         ###   ########.fr       */
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

void	forbidden_character(char *str, t_msc *msc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!"+-0123456789"[j])
			error_message(msc);
		if (str[i] == "+-0123456789"[j++])
		{
			if (str[i] == '+' || str[i] == '-')
			{
				if (plus_minus_space(str, i) == -1)
					error_message(msc);
			}
			j = 0;
			i++;
		}
	}
}

int	check_int_min_max(char *str, int nb)
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
			return (-1);
		i--;
		nb = nb / 10;
	}
	return (0);
}

void	append_node(char *str, t_msc *msc)
{
	int		nb;
	t_list	*new_node;
	t_list	*tmp;

	forbidden_character(str, msc);
	nb = ft_atoi(str);
	if (check_int_min_max(str, nb) == -1)
		error_message(msc);
	new_node = calloc_check_error(msc, 1, sizeof(t_list));
	new_node->data = nb;
	new_node->index = 0;
	new_node->next = NULL;
	if (!msc->s_a)
	{
		msc->s_a = new_node;
		return ;
	}
	tmp = msc->s_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	parsing(char **strs, t_msc *msc)
{
	int	i;

	i = 0;
	if (msc->strs_split == NULL)
		i = 1;
	while (strs[i])
	{
		if (!strs[i][0])
			error_message(msc);
		append_node(strs[i], msc);
		i++;
	}
	check_doubles(msc);
}

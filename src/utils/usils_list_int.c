/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usils_list_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:20:34 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/13 22:05:12 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_int.h"

void	free_int_list(t_list_int *list)
{
	t_list_int	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_list_int	*init_int_list(void)
{
	t_list_int	*list;

	list = malloc(sizeof(t_list_int));
	if (!list)
		return (NULL);
	list->i = 0;
	list->content = 0;
	list->next = NULL;
	return (list);
}

int	add_int_list(t_list_int **list, t_list_int *new)
{
	t_list_int	*tmp;

	if (!new)
		return (-1);
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->i = tmp->i + 1;
	return (new->i);
}

t_list_int	*get_int_list(t_list_int **list, int i)
{
	t_list_int	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->i == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	supr_id_int_list(t_list_int **list, int i)
{
	t_list_int	*tmp;
	t_list_int	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		if (tmp->i == i)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*list = tmp->next;
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:25:10 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/15 00:38:38 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_INT_H
# define LIST_INT_H


# include <stdlib.h>
# include "libft.h"

typedef struct s_list_int
{
	int					i;
	int					content;
	struct s_list_int	*next;
}		t_list_int;

t_list_int	*init_int_list(void);
t_list_int	*get_int_list(t_list_int **list, int i);
int			add_int_list(t_list_int **list, t_list_int *new);
void		free_int_list(t_list_int *list);
void		supr_id_int_list(t_list_int **list, int i);

#endif
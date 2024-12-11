/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:34:25 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/11 03:35:48 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_stack	*ft_stacknew(int x, int y)
{
	t_stack	*stak;

	stak = malloc(sizeof(t_stack));
	if (!stak)
		return (NULL);
	stak->next = NULL;
	stak->vex = malloc(sizeof(t_point));
	if (!stak->vex)
		return (free(stak), NULL);
	stak->vex->x = x;
	stak->vex->y = y;
	return (stak);
}

void	ft_stackadd(t_stack **stak, t_stack *new)
{
	if (!stak || !new)
		return ;
	new->next = *stak;
	*stak = new;
}

t_point *ft_stackpop(t_stack **stack)
{
	t_stack	*top;
	t_point	*vex;

	if (!stack || !*stack)
		return (NULL);

	top = *stack;
	vex = top->vex;
	*stack = top->next;
	free(top);
	return (vex);
}

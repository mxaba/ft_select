/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:03:35 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/21 09:04:44 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		go_up(t_select *select)
{
	int		current;
	int		max;
	int		min;

	current = select->pos;
	max = select->n_items;
	min = 0;
	if (current == min)
		select->pos = max - 1;
	else
		select->pos = select->pos - 1;
	save_load(select, 0);
	print_list(select);
}

void		go_down(t_select *select)
{
	int		current;
	int		max;
	int		min;

	current = select->pos;
	max = select->n_items;
	min = 0;
	if (current == (max - 1))
		select->pos = min;
	else
		select->pos = select->pos + 1;
	save_load(select, 0);
	print_list(select);
}

t_select	*save_load(t_select *select, int mode)
{
	static t_select	*tmp = NULL;

	if (mode == 0)
		tmp = select;
	return (tmp);
}

void		free_memory(t_select *select)
{
	int		i;

	i = 0;
	while ((select->items)[i] != NULL)
	{
		free((select->items)[i]);
		i++;
	}
	free(select->items);
	free(select->selected);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:22:59 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/21 12:13:49 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		add_list(t_select *select, int n, char **list)
{
	int		i;

	i = 0;
	select->items = (char**)malloc(sizeof(char*) * (n + 1));
	select->selected = (int*)malloc(sizeof(int) * (n + 1));
	if (select->items == NULL || select->selected == NULL)
		return ;
	(select->items)[n] = NULL;
	(select->selected)[n] = (int)'\0';
	select->n_items = n;
	select->pos = 0;
	while (i < n)
	{
		(select->items)[i] = ft_strdup(list[i]);
		i++;
	}
	ioctl(FILE_DS, TIOCGWINSZ, &(select->win));
}

void		select_item(t_select *select)
{
	int		pos;

	pos = select->pos;
	if (select->selected[pos] == 1)
		select->selected[pos] = -1;
	else
		select->selected[pos] = 1;
	if (select->pos == select->n_items - 1)
		select->pos = 0;
	else
		select->pos += 1;
	save_load(select, 0);
	print_list(select);
}

int			get_longest_item(t_select *select)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	if (select->n_items <= 0)
		return (0);
	len = ft_strlen((select->items)[0]);
	while ((select->items)[i] != NULL)
	{
		j = ft_strlen((select->items)[i]);
		if (len <= j)
			len = j;
		i++;
	}
	return (len);
}

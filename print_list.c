/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:28:18 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/21 12:20:48 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	check_winsize(t_select *select)
{
	int		i;

	i = get_longest_item(select);
	if (select->win.ws_row <= select->n_items || select->win.ws_col <= i)
	{
		if (select->win.ws_row <= select->n_items)
			ft_putendl("NB: Windowds height is small.");
		if (select->win.ws_col <= i)
			ft_putendl("NB: Windows width is small.");
		return (-1);
	}
	return (1);
}

void		print_list(t_select *select)
{
	int		i;

	i = 0;
	clear_terminal();
	if (check_winsize(select) == -1)
		return ;
	while ((select->items)[i] != NULL)
	{
		if (select->pos == i)
		{
			if (select->selected[i] == 1)
				put_underline_highlight((select->items)[i], ft_red);
			else
				put_underline((select->items)[i], ft_green);
		}
		else
		{
			if (select->selected[i] == 1)
				put_highlight(select->items[i], ft_green);
			else
				ft_putendl((select->items)[i]);
		}
		i++;
	}
}

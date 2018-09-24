/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:46:14 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/20 12:07:22 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			clear_terminal(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_putint);
}

void			ft_enter(t_select *select)
{
	int		i;

	i = 0;
	reset_behavior(&(select->term));
	while (select->n_items > i)
	{
		if ((select->selected)[i] == 1)
		{
			ft_putstr_fd((select->items)[i], 1);
			ft_putint_fd(' ', 1);
		}
		i++;
	}
	ft_putint_fd('\n', 1);
	exit(0);
}

void			ft_exit(void)
{
	t_select	*select;

	select = save_load(NULL, 1);
	free_memory(select);
	reset_behavior(&(select->term));
	exit(0);
}

static void		ft_clr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		str[i++] = '\0';
}

void			key_hook(void)
{
	char	key[5];

	key[4] = '\0';
	while (1)
	{
		ft_clr(key);
		read(0, key, 4);
		if (key[0] == 27 && key[1] == '\0' && key[2] == '\0')
			return ;
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'A')
			go_up(save_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'B')
			go_down(save_load(NULL, 1));
		else if (key[0] == 32 && key[1] == '\0' && key[2] == '\0')
			select_item(save_load(NULL, 1));
		else if (key[0] == 10 && key[1] == '\0' && key[2] == '\0')
			ft_enter(save_load(NULL, 1));
		else if (key[0] == 127 && key[1] == '\0' && key[2] == '\0')
			remove_item(save_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 51)
			remove_item(save_load(NULL, 1));
	}
}

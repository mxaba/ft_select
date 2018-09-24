/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:36:34 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/21 12:15:48 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	ft_handle(int num)
{
	t_select	*select;
	char		str[2];

	if (num == SIGINT)
		ft_exit();
	else if (num == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		select = save_load(NULL, 1);
		reset_behavior(&(select->term));
		str[0] = select->term.c_cc[VSUSP];
		str[1] = '\0';
		ioctl(0, TIOCSTI, str);
	}
	else if (num == SIGCONT)
	{
		signal(SIGTSTP, ft_handle);
		select = save_load(NULL, 1);
		change_behavior(&(select->term));
		print_list(select);
	}
	else if (num == SIGWINCH)
		win_change();
	else
		ft_exit();
}

void		handle_signals(void)
{
	int		loop;

	loop = 0;
	while (loop <= 31)
		signal(loop++, ft_handle);
}

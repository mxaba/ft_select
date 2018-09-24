/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:45:46 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/19 13:46:07 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		ft_handle(int num)
{
	t_select	*select;
	char		ch[2];

	if (num == SIGINT)
		ft_exit();
	else if (num == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		select = save_load(NULL, 1);
		reset_behavior(&(select->term));
		ch[0] = select->term.c_cc[VSUSP];
		ch[1] = '\0';
		ioctl(0, TIOCSTI, ch);
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

void			handle_signal(void)
{
	int		loop;

	loop = 1;
	while (loop <= 31)
		signal(loop++, ft_handle);
}

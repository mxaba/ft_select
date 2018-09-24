/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:25:19 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/21 12:19:16 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	win_change(void)
{
	t_select	*temp;

	temp = save_load(NULL, 1);
	ioctl(FILE_DS, TIOCGWINSZ, &(temp->win));
	save_load(temp, 0);
	print_list(temp);
}

int		reset_behavior(struct termios *term)
{
	tputs(tgetstr("ve", NULL), 1, ft_putint);
	tputs(tgetstr("te", NULL), 1, ft_putint);
	term->c_lflag |= (ICANON | ECHO);
	if (tcsetattr(FILE_DS, TCSANOW, term) == -1)
		return (-1);
	return (0);
}

int		change_behavior(struct termios *term)
{
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	if (tcgetattr(FILE_DS, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(FILE_DS, TCSANOW, term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_putint);
	tputs(tgetstr("vi", NULL), 1, ft_putint);
	return (0);
}

int		main(int ac, char **av)
{
	t_select	select;

	if (ac > 1)
	{
		if (change_behavior(&(select.term)) == -1)
			return (-1);
		handle_signal();
		clear_terminal();
		add_list(&select, ac - 1, &av[1]);
		save_load(&select, 0);
		print_list(&select);
		key_hook();
		free_memory(&select);
		reset_behavior(&(select.term));
	}
	return (0);
}

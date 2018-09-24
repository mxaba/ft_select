/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 08:59:17 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/21 08:59:19 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_green(char *str)
{
	ft_putstr("\033[32m");
	ft_putstr(str);
	ft_putendl("\033[0m");
}

void	put_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("so", NULL), 1, ft_putint);
	(*ft_print)(str);
	tputs(tgetstr("se", NULL), 1, ft_putint);
}

void	ft_red(char *str)
{
	ft_putstr("\033[31m");
	ft_putstr(str);
	ft_putendl("\033[0m");
}

void	put_underline_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("so", NULL), 1, ft_putint);
	tputs(tgetstr("us", NULL), 1, ft_putint);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_putint);
	tputs(tgetstr("se", NULL), 1, ft_putint);
}

void	put_underline(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("us", NULL), 1, ft_putint);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_putint);
}

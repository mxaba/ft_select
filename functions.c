/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:02:25 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/21 09:02:27 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		ft_putint_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}

int		ft_putint(int c)
{
	return (write(FILE_DS, &c, 1));
}

void	ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putint((int)'\n');
}

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_putint_fd((int)str[i++], fd);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_putint((int)str[i++]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:21:19 by mxaba             #+#    #+#             */
/*   Updated: 2018/09/21 12:15:24 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# define FILE_DS 2

# include <term.h>
# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct		s_select
{
	struct termios	term;
	struct winsize	win;
	int				pos;
	int				n_items;
	char			**items;
	int				*selected;
}					t_select;

void				ft_putstr_fd(char *str, int fd);
void				ft_putstr(char *str);
void				ft_putendl(char *str);
int					ft_putint(int c);
int					ft_putint_fd(int c, int fd);
void				handle_signal(void);
t_select			*save_load(t_select *select, int mode);
int					reset_behavior(struct termios *term);
void				free_memory(t_select *select);
void				ft_exit(void);
void				win_change(void);
int					reset_behavior(struct termios *term);
int					change_behavior(struct termios *term);
void				print_list(t_select *select);
int					get_longest_item(t_select *select);
void				clear_terminal(void);
void				ft_green(char *str);
void				ft_red(char *str);
void				put_underline(char *str, void (*ft_print)(char *));
void				put_highlight(char *str, void (*ft_print)(char *));
void				put_underline_highlight(char *str, void (*ft_print)(char*));
void				add_list(t_select *select, int n, char **list);
void				key_hook(void);
void				remove_item(t_select *select);
void				go_up(t_select *select);
void				go_down(t_select *select);
void				select_item(t_select *select);
int					ft_strlen(char *str);
char				*ft_strdup(char *str);

#endif

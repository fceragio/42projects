/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:08:09 by federico          #+#    #+#             */
/*   Updated: 2025/07/13 17:57:28 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int s_num)
{
	if (s_num == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	if (s_num == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \b\b");
	}
}

void	sig_init(struct sigaction *sa)
{
	sa->sa_handler = sig_handler;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = 0;
	if (sigaction(SIGINT, sa, NULL) == -1)
	{
		perror("sigaction");
		exit(SYS_ERR);
	}
	if (sigaction(SIGQUIT, sa, NULL) == -1)
	{
		perror("sigaction");
		exit(SYS_ERR);
	}
}

void	temp_sig_handler(int s_num)
{
	if (s_num == SIGINT)
	{
		g_sig = SIGINT;
		rl_done = 1;
		rl_replace_line("", 0);
		printf("\n");
	}
	if (s_num == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \b\b");
	}
}

void	temp_sig_init(struct sigaction *sa, struct sigaction *old)
{
	sa->sa_handler = temp_sig_handler;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = 0;
	if (sigaction(SIGINT, sa, old) == -1)
	{
		perror("sigaction");
		exit(SYS_ERR);
	}
	if (sigaction(SIGQUIT, sa, old) == -1)
	{
		perror("sigaction");
		exit(SYS_ERR);
	}
}

void	restore_sigaction(struct sigaction *old)
{
	if (sigaction(SIGINT, old, NULL) == -1)
	{
		perror("sigaction");
		exit(SYS_ERR);
	}
	if (sigaction(SIGQUIT, old, NULL) == -1)
	{
		perror("sigaction");
		exit(SYS_ERR);
	}
}

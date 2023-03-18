/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:42:59 by ahamrad           #+#    #+#             */
/*   Updated: 2023/03/18 05:12:11 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(int pid, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(800);
		c = c >> 1;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*str;
	int		i;

	if (argc != 3)
	{
		ft_putstr("Usage : ./client [pid] [string-to-send]\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr("PID cannot be negative !!\n");
		exit(EXIT_FAILURE);
	}
	str = argv[2];
	i = 0;
	while (str[i])
	{
		ft_send_char(server_pid, str[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agourrag <agourrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:31:21 by agourrag          #+#    #+#             */
/*   Updated: 2020/03/12 01:11:42 by agourrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// int	main(int argc, char **argv)
// {
// 	int	fd;
// 	int res;
// 	char *line;

// 	if (argc == 100)
// 		return (0);
// 	fd = open(argv[1], 0);
// 	while ((res = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("%d|%s|\n", res, line);
// 		free(line);
// 	}
// 	printf("%d|%s|\n", res, line);
// 	free(line);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	int	fd1;
	int fd2;
	int res;
	char *line;

	if (argc == 100)
		return (0);
	fd1 = open(argv[1], 0);
	fd2 = open(argv[2], 0);
	while ((res = get_next_line(fd1, &line)) > 0)
	{
		printf("%d|%s|\n", res, line);
		free(line);
		res = get_next_line(fd2, &line);
		printf("%d|%s|\n", res, line);
		free(line);
	}
	printf("%d|%s|\n", res, line);
	free(line);
	return (0);
}
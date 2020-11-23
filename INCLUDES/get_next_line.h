/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <dlartigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:14:27 by dlartigu          #+#    #+#             */
/*   Updated: 2020/08/10 03:35:48 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define BUFF_SIZE 321

typedef	struct	s_tab
{
	char		*str;
	int			fd;
}				t_tab;

int				get_next_line(const int fd, char **line);

#endif

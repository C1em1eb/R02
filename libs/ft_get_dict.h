/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dict.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:23:35 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 21:42:07 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include "ft_strcat.h"

char	*g_path = "./data/";

void	ft_get_dict(char *dict_name, char ***dictionary)
{
	char	*dictionary_name;
	char	buff[BUFF_SIZE + 1];
	int		fd;
	int		ret;
	int		c;
	int		row;
	int		o;

	o = 0;
	c = 0;
	row = 0;
	dictionary_name = ft_strcat(g_path, dict_name);
	fd = open(dictionary_name, O_RDONLY);
	if (fd == -1)
	{
		return ;
	}
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	while (c < ret && row < 100)
	{
		o = 0;
		while (buff[c] != ':')
		{
			dictionary[row][0][o] = buff[c];
			o++;
			c++;
		}
		dictionary[row][0][o] = '\0';
		c++;
		o = 0;
		while (buff[c] != '\n' && c < ret)
		{
			dictionary[row][1][o] = buff[c];
			o++;
			c++;
		}
		dictionary[row][1][o] = '\0';
		row++;
		c++;
	}
	if (close(fd) == -1)
	{
		free(dictionary_name);
		return ;
	}
	free(dictionary_name);
	return ;
}

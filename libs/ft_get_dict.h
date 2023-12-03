/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dict.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:23:35 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 20:47:00 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include "ft_strcat.h"

void	fill_dict(char ***dictionary, char *buff, int ret, int *i)
{
	while (i[0] < ret && i[2] < 100)
	{
		i[1] = 0;
		while (buff[i[0]] != ':')
			dictionary[i[2]][0][i[1]++] = buff[i[0]++];
		dictionary[i[2]][0][i[1]] = '\0';
		i[0]++;
		i[1] = 0;
		while (buff[i[0]] != '\n' && i[0] < ret)
			dictionary[i[2]][1][i[1]++] = buff[i[0]++];
		dictionary[i[2]][1][i[1]] = '\0';
		i[2]++;
		i[0]++;
	}
}

void	ft_get_dict(char *dict_name, char ***dictionary)
{
	char	buff[BUFF_SIZE + 1];
	int		fd;
	int		ret;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
		ft_putstr("Dict Error\n");
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	fill_dict(dictionary, buff, ret, i);
	if (close(fd) == -1)
		return ;
}

/*while (c < ret && row < 100)
	{
		o = 0;
		while (buff[c] != ':')
			dictionary[row][0][o++] = buff[c++];
		dictionary[row][0][o] = '\0';
		c++;
		o = 0;
		while (buff[c] != '\n' && c < ret)
			dictionary[row][1][o++] = buff[c++];
		dictionary[row][1][o] = '\0';
		row++;
		c++;
}*/

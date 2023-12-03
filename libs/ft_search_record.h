/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_record.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:32:10 by cleblond          #+#    #+#             */
/*   Updated: 2023/12/03 23:32:46 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strsame.h"
#include "ft_putstr.h"

int	search_record(char ***dictionary, char *n_record)
{
	int	record;

	record = 0;
	while (record < 50)
	{
		if (ft_strsame(n_record, dictionary[record][0]))
		{
			ft_putstr(dictionary[record][1]);
			return (1);
		}
		record++;
	}
	return (0);
}

char	*get_num_order(int num_order)
{
	int		i;
	char	*res;

	i = 1;
	if (num_order < 3)
	{
		res = (char *) malloc(1);
		res[0] = '\0';
		return (res);
	}
	res = (char *) malloc(num_order + 2);
	res[0] = '1';
	while (i <= num_order)
	{
		res[i] = '0';
		i++;
	}
	res[i] = '\0';
	return (res);
}

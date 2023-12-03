/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:18:01 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 19:37:11 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/variables.h"
#include "libs/matoi.h"
#include "libs/ft_is_numeric.h"
#include "libs/ft_strvalid.h"
#include "libs/ft_putstr.h"
#include "libs/ft_get_dict.h"
#include "libs/ft_handle_record.h"

int	main(int argc, char **argv)
{
	char	*n_record;
	char	*entry_value;
	int		record;
	char	***dictionary;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	record = 0;
	dictionary = (char ***)malloc(sizeof(char **) * 60);
	while (record < 50)
	{
		dictionary[record] = (char **)malloc(sizeof(char *) * 2);
		dictionary[record][0] = (char *)malloc(sizeof(char) * 48);
		dictionary[record][1] = (char *)malloc(sizeof(char) * 48);
		record++;
	}
	ft_get_dict(DICT, dictionary);
	if (argc == 2)
	{
		n_record = argv[1];
		matoi(n_record);
		if (!ft_is_numeric(n_record))
		{
			ft_putstr("Error\n");
			return (0);
		}
		ft_handle_record(dictionary, n_record);
	}
	if (argc == 3)
	{
		n_record = argv[1];
		matoi(n_record);
		entry_value = argv[2];
		if (!ft_is_numeric(n_record) || !ft_strvalid(entry_value))
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	free(dictionary);
}

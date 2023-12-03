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

char	*g_path = "./data/";

char	***get_dict(char *dict_name)
{
	char	***dictionary;
	int		record;

	record = 0;
	dictionary = (char ***)malloc(sizeof(char **) * 60);
	while (record < 50)
	{
		dictionary[record] = (char **)malloc(sizeof(char *) * 2);
		dictionary[record][0] = (char *)malloc(sizeof(char) * 48);
		dictionary[record][1] = (char *)malloc(sizeof(char) * 48);
		record++;
	}
	ft_get_dict(dict_name, dictionary);
	return (dictionary);
}

void	free_dict(char ***dict)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		free(dict[i][0]);
		free(dict[i][1]);
		i++;
	}
	free(dict);
	dict = NULL;
}

int	main(int argc, char **args)
{
	char	*n_record;
	char	***dictionary;
	char	*dict_path;

	if (argc == 2)
	{
		dict_path = ft_strcat(g_path, DICT);
		n_record = args[1];
	}
	if (argc == 3)
	{
		dict_path = args[1];
		n_record = args[2];
	}
	dictionary = get_dict(dict_path);
	matoi(n_record);
	if (!ft_is_numeric(n_record))
		ft_putstr("Error\n");
	ft_handle_record(dictionary, n_record);
	free_dict(dictionary);
	ft_putstr("\n");
	if (argc < 2 || argc > 3)
		ft_putstr("Error\n");
	return (0);
}

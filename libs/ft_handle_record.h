/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_record.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:22:03 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 23:33:20 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_RECORD_H
# define FT_HANDLE_RECORD_H

# include "ft_putchar.h"
# include "ft_count_digits.h"
# include "ft_get_charnum.h"
# include "ft_strlen.h"
# include "ft_search_record.h"

void	set_aime(char *aime, char *group, char ***dict)
{
	aime[0] = group[1];
	aime[1] = group[2];
	aime[2] = '\0';
	search_record(dict, aime);
}

void	resolve_group(char *group, char *num_order, char ***dict)
{
	int		num;
	int		i;
	char	aime[3];

	i = 0;
	while (i < 3)
	{
		num = group[i] - 48;
		if (i == 0 && num > 0)
		{
			search_record(dict, ft_get_charnum(num));
			search_record(dict, "100");
		}
		else if (i == 1 && num > 1)
			search_record(dict, ft_get_charnum(num * 10));
		else if (i == 1 && num > 0)
		{
			set_aime(aime, group, dict);
			break ;
		}
		else if (i == 2 && num > 0)
			search_record(dict, ft_get_charnum(num));
		i++;
	}
	search_record(dict, num_order);
}

void	fill_zeroes(char *mdata, char *data, int i, int k)
{
	while (data[i - k] != '\0')
	{
		mdata[i] = data[i - k];
		i++;
	}
}

char	*m_input(char *data, int *t)
{
	int		len;
	char	*mdata;
	int		i;

	len = ft_strlen(data);
	if (len % 3 == 1)
	{
		mdata = (char *) malloc(len + 2);
		mdata[0] = '0';
		mdata[1] = '0';
		*t += 2;
		i = 2;
		fill_zeroes(mdata, data, i, 2);
	}
	else if (len % 3 == 2)
	{
		mdata = (char *) malloc(len + 1);
		mdata[0] = '0';
		*t += 1;
		i = 1;
		fill_zeroes(mdata, data, i, 1);
	}
	else
		return (data);
	return (mdata);
}

void	ft_handle_record(char ***dictionary, char *str_num)
{
	int		len;
	int		c;
	char	chunk[4];
	char	*num_order;
	char	*m_number;
	int		i;
	int		t;

	i = 0;
	len = ft_strlen(str_num);
	t = len;
	m_number = m_input(str_num, &t);
	while (i < len)
	{
		c = 0;
		while (c < 3)
		{
			chunk[c++] = m_number[i++];
		}
		chunk[3] = '\0';
		t -= 3;
		num_order = get_num_order(t);
		resolve_group(chunk, num_order, dictionary);
		free(num_order);
	}
}
#endif

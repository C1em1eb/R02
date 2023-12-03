/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_record.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:22:03 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 20:51:03 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_RECORD_H
# define FT_HANDLE_RECORD_H

# include "ft_strsame.h"
# include "ft_putchar.h"
# include "ft_putstr.h"
# include "ft_atoi.h"
# include "ft_itoa.h"
# include "ft_count_digits.h"
# include "ft_get_charnum.h"
# include "ft_strlen.h"

static int	search_record(char ***dictionary, char *n_record);

int	get_num(char s)
{
	return (s - 48);
}

void	resolve_group(char *group, char *num_order, char ***dict)
{
	int		num;
	int		i;
	char	aime[3];

	i = 0;
	while (i < 3)
	{
		num = get_num(group[i]);
		if (i == 0 && num > 0)
		{
			search_record(dict, ft_get_charnum(num));
			search_record(dict, "100");
		}
		else if (i == 1 && num > 1)
		{
			search_record(dict, ft_get_charnum(num * 10));
		}
		else if (i == 1 && num > 0)
		{
			aime[0] = group[1];
			aime[1] = group[2];
			aime[2] = '\0';
			search_record(dict, aime);
			break;
		}
		else if (i == 2 && num > 0)
		{
			search_record(dict, ft_get_charnum(num));
		}
		i++;
	}
	search_record(dict, num_order);
}

char	*get_num_order(int num_order)
{
	int		i;
	char	*res;

	i = 1;
	if (num_order < 3)
	{
		res = (char*) malloc(1);
		res[0] = '\0';
		return (res);
	}
	res = (char*) malloc(num_order + 2);
	res[0] = '1';
	while (i <= num_order)
	{
		res[i] = '0';
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_putchunk(char *chunk)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		write(1, &chunk[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*m_input(char *data, int *t)
{
	int		len;
	int		rem;
	char	*mdata;
	int		i;

	len = ft_strlen(data);
	rem = len % 3;
	if (rem == 1)
	{
		mdata = (char*) malloc(len + 2);
		mdata[0] = '0';
		mdata[1] = '0';
		*t += 2;
		i = 2;
		while (data[i - 2] != '\0')
		{
			mdata[i] = data[i - 2];
			i++;
		}
	}
	else if (rem == 2)
	{
		mdata = (char*) malloc(len + 1);
		mdata[0] = '0';
		*t += 1;
		i = 1;
		while (data[i - 1] != '\0')
		{
			mdata[i] = data[i - 1];
			i++;
		}
	}
	else
		return (data);
	return (mdata);
}

static int	search_record(char ***dictionary, char *n_record)
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

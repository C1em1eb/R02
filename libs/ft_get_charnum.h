/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_charnum.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:12:48 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 22:02:34 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	get_digits(int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	if (num == 0)
		i++;
	return (i);
}

char	*ft_get_charnum(int nb)
{
	char			*str_res;
	int				i;
	unsigned int	ui;
	int				start;
	int				end;
	char			temp;

	i = 0;
	str_res = malloc(get_digits(nb) + 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		ui = nb * -1;
	}
	else
		ui = nb;
	while (ui > 0)
	{
		str_res[i++] = '0' + (ui % 10);
		ui /= 10;
	}
	if (nb != 0)
		str_res[i] = '\0';
	else
	{
		str_res[0] = '0';
		str_res[1] = '\0';
	}
	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str_res[start];
		str_res[start] = str_res[end];
		str_res[end] = temp;
		start++;
		end--;
	}
	return (str_res);
}

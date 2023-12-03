/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matoi.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:01:39 by cleblond          #+#    #+#             */
/*   Updated: 2023/12/03 20:01:41 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATOI_H
#define MATOI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matoi(char *str)
{
	int	i = 0;
	int	start = 0;

	while (str[i] <= 32)
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
		i++;
	char	*cs = str;
	while (str[i] >= '0' && str[i] <= '9')
	{
		cs[start] = str[i];
		i++;
		start++;
	}
	cs[start] = '\0';
}
#endif

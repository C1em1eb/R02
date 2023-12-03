/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matoi.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:01:39 by cleblond          #+#    #+#             */
/*   Updated: 2023/12/03 20:34:47 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATOI_H
# define MATOI_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	matoi(char *str)
{
	int		i;
	int		start;
	char	*cs;

	i = 0;
	start = 0;
	while (str[i] <= 32)
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
		i++;
	cs = str;
	while (str[i] >= '0' && str[i] <= '9')
	{
		cs[start] = str[i];
		i++;
		start++;
	}
	cs[start] = '\0';
}
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanus <chanus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:15:43 by chanus            #+#    #+#             */
/*   Updated: 2023/12/02 17:31:32 by chanus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include "ft_strlen.h"

#ifndef FT_STRCAT
#define FT_STRCAT
char *ft_strcat(char *str1, char *str2)
{
	unsigned int str1_size;
	unsigned int str2_size;
	unsigned int c;
	char *res;

	str1_size = ft_strlen(str1);
	str2_size = ft_strlen(str2);
	res = (char*)malloc((str1_size + str2_size + 1) * sizeof(char));
	c = 0;
	while (*str1 != '\0')
	{
		res[c] = *str1;
		str1++;
		c++;
	}
	while (*str2 != '\0')
	{
		res[c] = *str2;
		str2++;
		c++;
	}
	res[c] = '\0';
	return (res);
}
#endif

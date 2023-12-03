/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvalid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanus <chanus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:30:08 by chanus            #+#    #+#             */
/*   Updated: 2023/12/02 15:04:14 by chanus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strlen.h"

#ifndef FT_STRVALID
#define FT_STRVALID

int	ft_strvalid(char *str)
{
	if (str[0] == '\0')
	{
		return (0);
	}
	if (ft_strlen(str) > 48)
	{
		return (0);
	}
	return (1);
}
#endif
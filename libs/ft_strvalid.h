/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvalid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:58:35 by cleblond          #+#    #+#             */
/*   Updated: 2023/12/03 19:58:37 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRVALID
# define FT_STRVALID

#include "ft_strlen.h"

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

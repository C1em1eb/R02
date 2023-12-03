/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:12:20 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 20:52:28 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTSTR_H
# define FT_PUTSTR_H

# include "ft_putchar.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}
#endif

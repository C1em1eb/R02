/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:09:08 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 20:54:10 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTCHAR_H
# define FT_PUTCHAR_H

# include "headers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
#endif

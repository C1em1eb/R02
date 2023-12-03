/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:09:08 by chanus            #+#    #+#             */
/*   Updated: 2023/12/03 19:52:52 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

#ifndef FT_PUT_CHAR
#define FT_PUT_CHAR

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
#endif

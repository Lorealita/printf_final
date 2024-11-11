/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:33:48 by azahajur          #+#    #+#             */
/*   Updated: 2023/07/23 16:40:58 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n < 10)
	{
		cnt += ft_putchar((n + '0'));
	}
	else
	{
		cnt += ft_putnbr_u(n / 10);
		cnt += ft_putnbr_u(n % 10);
	}
	return (cnt);
}

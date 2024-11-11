/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:12:49 by azahajur          #+#    #+#             */
/*   Updated: 2023/07/23 18:42:29 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_print(unsigned long int n)
{
	int	cnt;

	cnt = 0;
	if (n >= 16)
	{
		cnt += ft_ptr_print(n / 16);
		cnt += ft_ptr_print(n % 16);
	}
	else
	{
		write(1, &"0123456789abcdef"[n % 16], 1);
		cnt++;
	}
	return (cnt);
}

int	ft_putnbr_ptr(unsigned long int n)
{
	int	cnt;

	cnt = 0;
	if (!n)
	{
		write(1, "0x0", 3);
		return (3);
	}
	cnt += write(1, "0x", 2);
	cnt += ft_ptr_print(n);
	return (cnt);
}

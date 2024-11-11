/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:17:03 by azahajur          #+#    #+#             */
/*   Updated: 2023/07/23 18:56:41 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arglist(char const *str, va_list argptr, int i)
{
	int	cnt;

	cnt = 0;
	if (str[i] == 'c')
		cnt += ft_putchar(va_arg(argptr, int));
	else if (str[i] == 's')
		cnt += ft_putstr(va_arg(argptr, char *));
	else if (str[i] == 'p')
		cnt += ft_putnbr_ptr(va_arg(argptr, unsigned long int));
	else if ((str[i] == 'x') || (str[i] == 'X'))
		cnt += ft_putnbr_hex(va_arg(argptr, unsigned long int), str[i]);
	else if ((str[i] == 'u'))
		cnt += ft_putnbr_u(va_arg(argptr, unsigned int));
	else if ((str[i] == 'd') || (str[i] == 'i'))
		cnt += ft_putnbr(va_arg(argptr, int));
	else if (str[i] == '%')
		cnt += write(1, "%", 1);
	return (cnt);
}

int	ft_printf(char const *str, ...)
{
	va_list	argptr;
	int		i;
	int		cnt;

	va_start(argptr, str);
	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			cnt += ft_arglist(str, argptr, (i + 1));
			if (cnt == -1)
				return (-1);
			i += 2;
		}
		else
		{
			cnt += write(1, &str[i], 1);
			if (cnt == -1)
				return (-1);
			i++;
		}
	}
	return (cnt);
}

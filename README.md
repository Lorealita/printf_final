# Printf
El objetivo del proyecto Printf es crear una función que imite algunas de las funcionalidades de la función printf presente en la librería <stdio.h> de C. Nombraremos
a la versión ft_printf para diferenciarla de función original. Printf es una función variádica (variadic funtions), una función preparada para recibir un número
indefinido de argumentos. Cada argumento debe ser clasificada para poder ser procesado según el tipo de dato del que se trate. Concretamente, printf procesa la información
para escribirla en pantalla. Para acotar nuestro proyecto, ft_printf solo procesará un número limitado de tipos de datos: %c, %s, %p, %d, %i, %u, %x, %X y % %. 
- %c Imprime un solo carácter.
- %s Imprime una string (como se define por defecto en C).
- %p El puntero void * dado como argumento se imprime en formato hexadecimal.
- %d Imprime un número decimal (base 10).
- %i Imprime un entero en base 10.
- %u Imprime un número decimal (base 10) sin signo.
- %x Imprime un número hexadecimal (base 16) en minúsculas.
- %X Imprime un número hexadecimal (base 16) en mayúsculas.
- % % para imprimir el símbolo del porcentaje.

Para llevarlo a cabo también acotaremos las herramientas disponibles. Solo dispondremos de las funciones: `malloc`, `free`, `write`, `av_arg`, `av_start`, `av_copy`,
`av_end`.

## Versión reducida
De forma complementaria se completa el reto de desarrollar una versión reducida del proyecto capaz de funcionar solo con %s, %d y %x. El reto consiste en un código que
sea funcional, reducido y modular sin sacrificar su legibilidad. Para un proyecto de este nivel se apuesta por la sencillez y la limpieza.

```
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int				cnt;
  cnt = 0;
	if (n == -2147483648)
	{
		cnt += write(1, "-2", 2);
		cnt += write(1, "147483648", 9);
		return (cnt);
	}
	if (n < 0)
	{
		cnt += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		cnt += ft_putchar((n + '0'));
	}
	else
	{
		cnt += ft_putnbr(n / 10);
		cnt += ft_putnbr(n % 10);
	}
	return (cnt);
}

int	ft_putnbr_hex(unsigned long int n)
{
	int	cnt = 0;
	char *hex_min = "0123456789abcdef";
  
  if ((n < 16))
    {
        cnt += write(1, &hex_min[n], 1);
    }
    else
    {
        cnt += ft_putnbr_hex(n / 16);
        cnt += ft_putnbr_hex(n % 16);
    }
	return (cnt);
}

int	ft_putstr(char *str)
{
	int	cnt;
  
  cnt = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[cnt])
	{
		write(1, &str[cnt], 1);
		cnt++;
	}
	return (cnt);
}

int	ft_arglist(char const *str, va_list argptr, int i)
{
	int	cnt;
  
  cnt = 0;
    if (str[i] == 's')
		cnt += ft_putstr(va_arg(argptr, char *));
	else if (str[i] == 'x')
		cnt += ft_putnbr_hex(va_arg(argptr, unsigned long int));
	else if (str[i] == 'd')
		cnt += ft_putnbr(va_arg(argptr, int));
	return (cnt);
}

int ft_printf(char const *str, ...)
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
			i += 2;
		}
		else
		{
			cnt += write(1, &str[i], 1);
			i++;
		}
		if (cnt == -1)
			return (-1);
	}
    va_end(argptr);
	return (cnt);
}
```


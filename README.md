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
De forma complementaria se completa el reto de desarrollar una versión reducida del proyecto capaz de funcionar solo con %s, %d y %x. El reto consiste en un código que sea funcional, reducido y modular sin sacrificar su legibilidad. Para un proyecto de este nivel se apuesta por la sencillez y la limpieza. El código se 
encuentra en la carpeta mini_printf.

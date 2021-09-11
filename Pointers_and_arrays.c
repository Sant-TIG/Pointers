/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pointers_and_arrays.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:22:14 by sperez-p          #+#    #+#             */
/*   Updated: 2021/09/10 22:22:14 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
	La relacion que tienen los conceptos de punteros y cadenas en C y C++
es muy fuerte, son dos conceptos que van de la mano.

	Cuando declaramos una cadena de cualquier tipo, cada elemento que la
constituye la cadena se guarda en la memoria como un bloque que ocupa la
cantidad de bytes de su tipo. Si se tratase de una cadena con nombre N
de tipo entero y tuviese un tamaño de 3, int N[3], cada numero ocupara
un espacio de 4 bytes. Por lo tanto, el tamaño total de la cadena será
12 bytes y su direccion base sera la direccion base del primer elemento.

	Una de las ventajas de las cadenas es que cada uno de los elementos
que la forman, se guardan en forma de variables. Por lo tanto, tendrán las
mismas caracteristicas y podremos trabajar con ellas de la misma forma.
En el ejemplo anterior, sus elementos estarian guardados en las siguientes 
variables: N[0] N[1] N[2]. Usaremos contadores para movernos a traves de los
elementos.

	Si declarasemos un puntero a un entero np, y almacenamos en np la direccion
de la direccion de N[0], al igual que en los ejemplos anteriores, podemos
dereferenciar la variable np para saber y modificar el valor almacenado dentro
de N[0] ademas de poder movernos por iteracion a traves de la cadena.

	Si trabajamos con contadores, podremos hacer referencia a las direcciones de
las memorias de los elementos con el operador '&' (&N[i]). Si lo hacemos con
punteros, lo haremos sumando i a la variable que apunta el puntero (np + i).
Para referirinos a sus valores usaremos N[i] para contadores y *(np + i) para
punteros.

	La razon por la que utilizamos punteros o contadores para movernos y modificar
una cadena es porque no podemos moverla ni modificarla de otra forma. Por ejemplo,
no podemos movernos a traves de la cadena anterior de la siguiente forma: N++.
*/

#include <stdio.h>
int	main()
{
	printf("\nEjemplos con una cadena de tipo entero.\n\n");
	int		N[3] = {2,3,5};
	int		i = -1;
	int*	p = N;
	printf("Ejemplo con contadores\n\n");
	while  (++i < 3)
		printf("\tLa direccion del %d elemento es '%p' y su valor %d\n", i, &N[i], N[i]);
	printf ("\nEjemplo con punteros\n\n");
	i = -1;
	while (++i < 3)
		printf("\tLa direccion del %d elemento es '%p' y su valor %d\n", i, N + i, *(N + i));
	printf("\nEjemplos con una cadena de tipo caracter.\n\n");
	char	C[10]= "Character";
	i = -1;
	char* cp = C;
	printf("Ejemplo con contadores\n\n");
	while  (++i < 10)
		printf("\tLa direccion del %d elemento es '%p' y su valor %c\n", i, &C[i], C[i]);
	printf ("\nEjemplo con punteros\n\n");
	i = -1;
	while (++i < 10)
		printf("\tLa direccion del %d elemento es '%p' y su valor %c\n", i, C + i, *(C + i));
	printf("\n");
	return (0);
}
#include <stdio.h>
int main()
{
	int		x = 5;
	int*	p = &x;
	*p = 6;
	int**	q = &p;
	int***	r = &q;

	printf("\nEl valor de x es '%d' y la direccion del espacio de memoria donde se aloja es(&x) '%p'\n\n", x, &x);
	printf("---La direccion del espacio de memoria donde se aloja p(&p) es '%p'---\n\n", &p);
	printf("La dirección a la que apunta p(p) es '%p' y el valor guardado en esa direccion(*p) es: '%d'\n\n", p, *p);
	printf("---La direccion del espacio de memoria donde se aloja q(&q) es '%p'---\n\n", &q);
	printf("La direccion a la que apunta q(q) es '%p' y el valor guardado en esa direccion(*q) es: '%p'\n", q, *q);
	printf("El valor del puntero doble(**q) es: '%d\n\n", **q);
	
	printf("---La direccion del espacio de memoria donde se aloja r(&r) es '%p'---\n\n", &r);
	printf("La direccion a la que apunta r(r) es '%p' y el valor  guardado en esa direccion(*r) es: '%p'\n", r, *r);
	printf("El valor guardado en la direccion anterior(**r) es: '%p' y el valor del puntero triple(***r) es: '%d'\n\n", **r, ***r);
	***r = 10;
	printf("---Si asignamos un nuevo valor al puntero triple (***r), estaremos modificando el valor de x.---\n\n");
	printf("Si ***r = 10, x = %d\n\n", x);	
	**q  = *p + 2;
	printf("---Si asignasemos un nuevo valor al puntero doble(**q), tambien se modificara el valor de x.---\n\n");
	printf("Si **q = *p + 2, x = %d\n\n", x);
	return (0);
}
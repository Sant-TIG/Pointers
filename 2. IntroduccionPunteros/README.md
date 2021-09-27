# Punteros

_Antes de empezar con este apartado, es conveniente haber visto antes el de **Almacenamiento de Datos** para comprender como se almacenan las variables en la memoria. Si no lo has visto pincha aqui: [AlmacenamientodeDatos](../1.AlmacenamientodeDatos/README.md)._

## Definicion

Los **punteros** en **C** son variables que **almacenan la direccion de otras variables** y, como son variables, trabajaremos con ellos como lo hemos hecho hasta hora con las variables. Los punteros se crearon con el proposito de ahorrar espacio en la memoria y lograr un tiempo de ejecucion mas rapido.

Estos pueden ser incrementados/decrementados para apuntar al siguiente/anterior bloque de memoria y nos permiten hacer uso de una caracteristica fundamental: la **dereferenciacion**. Gracias a esta propiedad de los punteros podemos **modificar el valor de la variable a la que apunta el puntero**.

## Declaracion de Punteros

Como cualquier otra variable, hay que **declarar el puntero** antes de poder utilizarlo. Existen **dos estructuras** para declarar punteros: **'tipo \*nombre'** o **'tipo\* nombre'**. Cualquiera de las dos son validas, aunque gramaticalmente la segunda es mas correcta. Esto se debe cuando nos referimos a un puntero decimos que el puntero apunta a un tipo.

```
int *pe; //puntero a un entero
char* pc; //puntero a un caracter
```

Como podemos ver, hay un nuevo elemento a la hora de declarar punteros que no existia en el caso de las variables, y es el operador **'\*'**. Gracias a él, el ordenador sabe que lo que queremos hacer es declarar un puntero y nos permitira acceder al valor almacenado en la direccion a la que apunta. Se vera como funciona en la inicializacion del puntero.

## Inicializacion de Punteros

Independientemente del tipo al que apunte un **puntero**, el **valor** que va a almacenar en el **siempre** va a ser el mismo: un numero largo en hexadecimal que representa la **direccion de memoria de la variable que almacena**. Para **inicializar** un puntero con la direccion de una variable, utilizaremos el operador **'&'** seguido del nombre de la variable que queremos almacenar su direccion.

```
int   e = 10;
char  c = 'a';
int   *pe;
char* pc = &c;

pe = &e;
```

Al igual que con las variables, podemos **declarar un puntero y asignarle un valor en la misma linea**. Sin embargo, esto solo podemos hacerlo si lo declaramos usando el **segundo modelo de estructura(tipo\* nombre)**. Como se puede observar arriba, los **punteros tienen el mismo tipo que las variables a las que apuntan**. Este es el segundo requisito que debemos cumplir a la hora de declararlos e inicializarlos.

Una vez entendido que para declarar e inicializar un puntero debemos tener una variable del mismo tipo a la que apuntar, que el puntero debe ir con el operador **'\*'** y que debe almacenar dentro la direccion de una variable, podemos analizar su funcionamiento en la memoria con el ejemplo posterior.

### Memoria 💾

|  Dirección  | Variable | Tamaño | Declaracion |
| :---: | :---: | :---: | :---: |
| ++ |   | 1 byte |   |
| 130 |   | 1 byte |   |
| 126 - 129 | e = 10 | 4 bytes | `int e = 10` |
| 125 |   | 1 byte |   |
| 124 | c = 'a' | 1 byte | `char c = 'a'` |
| 123 |   | 1 byte |   |
| 122 |   | 1 byte |   |
| 121 | pe = 126 | 1 byte | `int* pe = &e` |
| 120 |   | 1 byte |   |
| 119 | pc = 124 | 1 byte | `char* pc = &c` |
| -- |   | 1 byte |   |

# Punteros

_Antes de empezar con este apartado, es conveniente haber visto antes el de **Almacenamiento de Datos** para comprender como se almacenan las variables en la memoria. Si no lo has visto pincha aqui: [AlmacenamientodeDatos](../1.AlmacenamientodeDatos/README.md)._

## Definicion

**Un puntero en C y C++ es una variable que almacena la direccion de otra variable.** Esta es realmente la definicion de un puntero. Aunque parece sencilla, el concepto de puntero es uno de los conceptos que mas claros tenemos que tener a la hora de programar en C y C++. 

**Los punteros** se crearon con el proposito de ahorrar espacio en la memoria y lograr un tiempo de ejecucion mas rapido. A pesar de que tienen muchas funcionalidades, se utilizan sobre todo para **tres operaciones generales**:
- Recorrer en iteración los elementos de matrices u otras [estructuras de datos](https://github.com/Sant-TIG/EstructurasDeDatos/blob/master/README.md).
- Pasar funciones a otras funciones.
- Asignar nuevos objetos en el montón.

Sin embargo, antes de profundizar en sus funciones debemos entender bien su definicion, que las diferencian del resto de variables, que significa que almacenen la direccion de otra variable, que implicaciones tiene esto a la hora de programar, como se declaran y se definen, y como se almacenan en la memoria. 

## Variables Tipo Puntero. Declaracion de Punteros.

**Los punteros son un tipo variable "fuertemente tipada"**. Esto significa que para poder declarar un puntero, su tipo tiene que ser igual al tipo de la variable a la que apunta. Cuando decimos que un puntero **apunta** a una variable nos referimos a que **almacena** su direccion como valor. Lo veremos en el siguiente apartado. 

Como cualquier otra variable, hay que **declarar el puntero** antes de poder utilizarlo. Existen **dos estructuras** para declarar punteros: **'tipo \*nombre'** o **'tipo\* nombre'**. Cualquiera de las dos son validas, aunque gramaticalmente la **segunda es mas correcta**. Esto se debe cuando nos referimos a un puntero decimos que es **un puntero a un tipo** .

```
int e;
int c;
int *pe; //puntero a un entero
char* pc; //puntero a un caracter
```

Como podemos ver, hay un **nuevo elemento** a la hora de declarar punteros que no existia en el caso de las variables, y es el operador **'\*'**. Gracias a él, el ordenador sabe que lo que queremos hacer es declarar un puntero y nos permitira **acceder al valor almacenado en la direccion de la variable a la que apunta**. A esto se lo denomina como **"desreferenciar una variable"**.

### Memoria 💾

Esta tabla representa de forma ficticia el espacio que asignaría el ordenador tomarse con ellas durante la ejecucion de un programa. El ordenador las almacenará como cualquier otra variable, asignandoles el espacio correspondiente en funcion de su tipo.

|  Dirección  | Variable | Tamaño | Declaracion |
| :---: | :---: | :---: | :---: |
| ++ |   | 1 byte |   |
| 130 |   | 1 byte |   |
| 126 - 129 | e | 4 bytes | `int e` |
| 125 |   | 1 byte |   |
| 124 | c | 1 byte | `char c` |
| 123 |   | 1 byte |   |
| 122 |   | 1 byte |   |
| 118-121 | pe | 4 bytes | `int* pe` |
| 117 |   | 1 byte |   |
| 116 | pc | 1 byte | `char* pc` |
| 115 |   | 1 byte |   |
| -- |   | 1 byte |   |

## Inicializacion de Punteros. Desreferenciacion.

Independientemente del tipo al que apunte un **puntero**, el **valor** que va a almacenar en el **siempre** va a ser el mismo: un numero largo en hexadecimal que representa la **direccion de memoria de la variable que almacena**. Para **inicializar** un puntero con la direccion de una variable, utilizaremos el operador **'&'** seguido del nombre de la variable que queremos almacenar su direccion.

Al igual que con las variables, podemos **declarar un puntero y asignarle un valor en la misma linea**. Sin embargo, esto solo podemos hacerlo si lo declaramos usando el **segundo modelo de estructura(tipo\* nombre)**. 
```
int   e = 10;
char  c = 'a';
int   *pe; //Puntero a un entero, pe
char* pc = &c; //Puntero a un caracter, pc que apunta a c

pe = &e; // pe apunta a e
```
Una vez entendido que para declarar e inicializar un puntero debemos tener una variable del mismo tipo a la que apuntar, que el puntero debe ir con el operador **'\*'** y que debe almacenar dentro la direccion de una variable, podemos analizar su funcionamiento en la memoria con el ejemplo siguiente.

### Memoria

Esta tabla representa de forma ficticia el valor almacenado dentro de las variables anteriores. Se puede ver como dentro de los punteros esan almacenadas las direcciones de las variables a las que apuntan.

|  Dirección  | Variable | Valor | Tamaño | Declaracion |
| :---: | :---: | :---: | :---: | :---: |
| ++ |   |   | 1 byte |   |
| 130 |   |   | 1 byte |   |
| 126 - 129 | e | 10 | 4 bytes | `int e = 10` |
| 125 |   |   | 1 byte |   |
| 124 | c | 'a' | 1 byte | `char c = 'a'` |
| 123 |   |   | 1 byte |   |
| 122 |   |   | 1 byte |   |
| 118-121 | pe | 126 | 1 byte | `int* pe = &e` |
| 117 |   |   | 1 byte |   |
| 116 | pc | 124 | 1 byte | `char* pc = &c` |
| 115 |   |   | 1 byte |   |
| -- |   |   | 1 byte |   |

Una vez entendido que para declarar e inicializar un puntero debemos tener una variable del mismo tipo a la que apuntar, que el puntero debe ir con el operador **'\*'** y que debe almacenar dentro la direccion de una variable, podemos analizar su funcionamiento en la memoria con el ejemplo siguiente.


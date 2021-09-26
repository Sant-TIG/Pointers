# Introduction to Pointers 📬

El concepto de **puntero** es uno de los conceptos que mas claros tenemos que tener a la hora de programar en **C**. Sin embargo, antes de empezar a entenderlos, debemos saber como se almacenan los distintos tipos de datos en la memoria del ordenador. A partir de ahora, **siempre** que hablemos sobre un **espacio de memoria** nos estaremos refiriendo a la memoria que utiliza el ordenador cuando ejecuta un programa, ya que es dentro de esta memoria donde se almacenan los datos e instrucciones que necesita el programa para ejecutarse. A esta memoria se la denomina **Randon Access Memory** o **RAM**.

## Data Storage 💾

Cuando durante la **ejecucion de un programa** el ordenador se encuentra con la declaracion de una **variable**, reservará un espacio de memoria cuyo **tamaño** dependerá del **tipo de dato** que sea. Por ejemplo, si se encuentra con una declaracion de una variable **'e'** de tipo **'entero'**, asignará un espacio de memoria para **'e'** del tamaño de **4 bytes**. Si se encontrase con una variable **'c'** de tipo **'caracter'**, asignará un espacio de memoria de **1 byte**.

---

_Las tablas que aparecen a continuacion son una representacion ficticia de las porciones de la memoria RAM que un ordenador reservaria a la hora de ejecutar un programa. Es dentro de esta porcion donde se almacenaran todas las intrucciones y los datos necesarios para que el programa funcione._

_Las tablas estan divididas en filas que representan un byte de memoria, simulando el la arquitectura de la memoria de un ordenador comun. Esto significa que cada byte de los que esta compuesta la memoria tiene una direccion propia con la que podremos referirnos a él._

---

|  Dirección  | Variable | Tamaño | Declaracion |
| :---: | :---: | :---: | :---: |
| ++ |   | 1 byte |   |
| 130 |   | 1 byte |   |
| 126 - 129 | e | 4 bytes | `int e` |
| 125 |   | 1 byte |   |
| 124 | c | 1 byte | `char c` |
| 123 |   | 1 byte |   |
| -- |   | 1 byte |   |

Como vemos en la tabla, la memoria asignará a las variables un espacio de memoria aleatorio con sus direcciones correspondientes. La variable **'c'** tendra la direccion **'124'** y la variable **'e** estara comprendida entre **'126 y 129'** inclusives. Para saber el tamaño de los tipos mas comunes de datos pincha aqui: [https://www.tutorialspoint.com/cprogramming/c_data_types.htm](https://www.tutorialspoint.com/cprogramming/c_data_types.htm)

El ordenador tiene una **estructura interna**, como una **tabla de busqueda**, en la que almacena una variable de la siguiente manera: **nombre tipoDeDato direccion**. Gracias a esta estructura, en los ejemplos anteriores el ordenador sabria que tiene almacenadas unas variables **'c'** y **'e'** de tipo **'caracter'** y **'entero'** en las direcciones **'124'** y **'126'**.

---

### Importante

Cuando el ordenador asigna un espacio de memoria para algun tipo de dato que ocupa mas de un byte, como es el caso de la variable de tipo entero e del ejemplo anterior, este almacena su **direccion base**, que es la **direccion del primer byte** que forma el tipo de dato, como punto de referencia para encontrarla.

Para que se entienda bien, usaremos el caso de la variable **'e'** anterior. Como se muestra en la tabla, la variable **'e'** esta almacenada en un bloque de memoria que ocupa un espacio de 4 bytes comprendido entre las direcciones 126 y 129 inclusives. Esto significa que las direcciones de sus bytes son **126, 127, 128 y 129**. Como el primer byte esta almacenado en la direccion **126**, esta sera la direccion base de la variable y, como el ordenador la buscara siguiendo la tabla de busquedas anterior, sabra que es de tipo entero y que esta compuesto por 4 bytes, por lo que sabiendo solo la direccion del primero sabra que la direccion de los tres bytes siguientes son 127, 128 y 129.

---

```
Ejemplos de tablas de busqueda
c char 124
e int 126
```

## Inicializacion

```
char c;
int  e;

c = 'a';
a = 5;
```

Cuando **inicializamos una variable** o le **asignamos un valor**, el ordenador identifica la variable usando la tabla de busqueda comentada anteriormente y rellena el espacio asignado con el valor que le damos. 

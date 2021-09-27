# Almacenamiento de Datos 💽

El concepto de **punteros** es uno de los conceptos que mas claros tenemos que tener a la hora de programar en **C**. Sin embargo, antes de empezar a entenderlos, debemos saber como se almacenan los distintos tipos de datos en la memoria del ordenador. A partir de ahora, **siempre** que hablemos sobre un **espacio de memoria** nos estaremos refiriendo a la memoria que utiliza el ordenador cuando ejecuta un programa, ya que es dentro de esta memoria donde se almacenan los datos e instrucciones que necesita el programa para ejecutarse. A esta memoria se la denomina **Randon Access Memory** o **RAM**.

## Declaración de Variables 💾

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

## Inicializacion de variables

```
char c;
int  e;

c = 'a';
a = 10;
```
Como vemos aqui arriba, hemos **asignado un valor** a las variables de los ejemplos anteriores. A esto se le llama **inicializar una variable**. Ahora, cuando ejecutemos el programa y el ordenador vea la inicializacion de las variables, utilizara la **tabla de busqueda** y vera el **nombre** de la variable, seguido identificará su **tipo** y, finalmente irá a la **direccion guardada** para almacenar el valor asignado en caso de no haber habido ningun error en el transcurso.

---

### Errorres

```
int  e;
char c;

e = MAX_INT + 1, e = MIN_INT - 1, e = 'c';
c = "cadena", c = 31, c = 127;
```

En este apartado se muestran que tipos de **errores** podriamos tener a la hora de **inicializar una variable** con los ejemplos anteriores:
<ol>
  <li>En caso de las <b>variables</b> de tipo <b>entero</b>, si se le da un valor <b>mayor que el maximo valor(2.147.483.647) o menor que el minimo valor(-2.147.483.648)</b> que puede almacenar en 4 bytes, o si le damos un <b>valor de distinto tipo</b> al declarado.</li>
  <li>En el caso de las <b>variables</b> de tipo <b>caracter</b>, si le damos un <b>valor de distinto tipo</b> al declarado o si le damos un <b>valor numerico menor que 32 o mayor que 126</b> ya que quedarian fuera del rango de caracteres imprimibles en ascii.
    <ul><li>En este ultimo caso hay que recordar que cuando asignamos un valor numerico a una variable de tipo caracter y este valor esta comprendido entre los caracteres ascii, de 0 a 255, el compilador lo trasladara a su valor de tipo caracter y lo imprimira en caso de ser imprimible.</li></ul>
  </li>
</ol>
  
---
 
Como vemos en la siguiente tabla, el valor que le hemos asignado a las variables se utiliza para rellenar los bytes que se habian reservado para ellas.
 
|  Dirección  | Variable | Tamaño | Declaracion |
| :---: | :---: | :---: | :---: |
| ++ |   | 1 byte |   |
| 130 |   | 1 byte |   |
| 126 - 129 | e = 10 | 4 bytes | `int e` |
| 125 |   | 1 byte |   |
| 124 | c = 'a' | 1 byte | `char c` |
| 123 |   | 1 byte |   |
| -- |   | 1 byte |   |

Con el objetivo entender bien como se almacenan estos datos, haremos una representacion en bits de los bytes que ocupan las variables anteriores. Partimos de la base de que los bytes estan compuestos por 8 bits.

<ol>
  <li>En el caso de la variable c, como es de tipo caracter sabemos que está compuesto por 1 byte. Cuando declaramos la variable de tipo caracter, el ordenador la inicializa rellenando el byte de ceros (Un byte de tipo caracter relleno de ceros representa el caracter nulo).<table><tr><th>Byte 124</th></tr><tr><td>00000000</td></tr></table> Cuando le asignamos un valor, en este caso el de la letra 'a', el ordenador vuelve a rellenar ese espacio con el valor que le hemos dado en binario. En este caso, a en binario es 01100001 por lo que el byte donde esta almacenado quedara:<table><tr><th>Byte 124</th></tr><tr><td>01100001</td></tr></table></li>
  <li>En el caso de la variable e, como es de tipo <b>entero</b> esta compuesto por 4 bytes. Cuando declaramos una variable de este tipo, el ordenador rellena los bytes de forma aleatoria y cuando le damos un valor lo vuelve a rellenar. La razon por la que las variable de este tipo tienen un tamaño de 4 bytes es por la cantidad de numeros a los que puede hacer referencia. En este caso el valor es diez y en binario es 1010.<table><tr><th>Byte 129</th><th>Byte 128</th><th>Byte 127</th><th>Byte 126</th></tr><tr><td>00000000</td><td>00000000</td><td>00000000</td><td>00001010</td></tr></table>
</ol>

El objetivo de incializar una variable es poder trabajar con ella. Cuando la variable tiene asignada un valor dentro de ella nos permite ejecutar diversas operaciones sobre ese valor, en funcion del tipo de dato que sea. Con los tipos numeros podremos ejecutar operaciones, con los caracteres podemos formar cadenas y trabajar con ellas de diversas formas, etc... Lo importante de esto es saber que asi como ha funcionado la memoria al inicializarla, funcionará el resto de veces que le asignemos un nuevo valor.

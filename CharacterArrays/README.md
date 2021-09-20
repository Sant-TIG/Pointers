# Matrices de Caracteres y Punteros

_El concepto de matriz de caracteres es muy similar al concepto de cadena de caracteres ya que ambas
estan compuestas por un conjunto de caracteres encadenados que forman una palabra o una frase. Antes
de entender que representa una matriz de caracteres hay que entender las cadenas de caracteres._

## Definiciones 📚

_En C, una **cadena** es una secuencia de caracteres terminada por el caracter nulo_ **'\0'** _. Esta
secuencia puede formar una palabra o una frase y se suelen utilizar para crear programas legibles y con
significado._

```
Ejemplos de Cadenas
Cadena1 = "cadena"
Cadena2 = "matriz de caracteres"
```
_Como en C no se admiten las **cadenas** como tipo de datos, estas son realmente matrices de una dimension
en las que se almacenan los caracteres de forma contigua. Por eso, cuando hablamos de **cadenas** en C,
estamos hablando de **matrices de caracteres** compuestas por dos o mas elementos de tipo caracter(char)._

```
Ejemplos de Matrices de Caracteres
char C1[] = "cadena";
char C2[] = "matriz de caracteres;
```
## Declaracion ✍️
_Como bien hemos definido anteriormente, una cadena es una matriz unidimensional, por lo que a la hora
de **declararla** seguiremos las mismas reglas que las matrices. La **estructura** que hay que seguir
para **declarar** una cadena es la siguiente:_ **"tipo nombre[tamaño]"**.

```
Ejemplo de una Declaración
char C[5];
```

_El **tipo** siempre ha de ser **char** ya que los elementos que formaran la matriz seran de tipo 
'caracter', el **nombre** puede ser cualquiera y el **tamaño** ha de ser igual o superior al numero
de elementos de la cadena._

_Al **declarar** una matriz de caracteres lo que estamos haciendo es reservar un espacio de memoria de
tamaño igual a la sumatoria del peso de todos sus elementos. Como los elementos que constituyen este
tipo de matrices son de tipo 'caracter', cada elemento sumara 1 byte de espacio. De esta manera, el
ejemplo anterior se almacenaria en la memoria de la siguiente manera:_

### Memoria RAM 💾

| Direccion | Contenido |
| --- | --- |
| 220 |   |
| 219 |   |
| 213 | C |
| 212 |   |
| 211 |   |
| 210 |   |

| Direccion | Contenido | Indice |
| --- | --- | --- |
| 220 |   |   |
| 219 |   |   |
| 218 |   | C[5] |
| 217 |   | C[4] |
| 216 |   | C[3] |
| 215 |   | C[2] |
| 214 |   | C[1] |
| 213 |   | C[0] |
| 212 |   |   |
| 211 |   |   |
| 210 |   |   |

## Inicialización 🖨️




| Direccion | Memoria RAM | Indice |
| --- | --- | --- |
| 220 |   |   |
| 219 |   |   |
| 218 | a | C[5] |
| 217 | n | C[4] |
| 216 | e | C[3] |
| 215 | d | C[2] |
| 214 | a | C[1] |
| 213 | c | C[0] |
| 212 |   |   |
| 211 |   |   |
| 210 |   |   |


```

```

## Almacenaje 📦
Antes de empezar a operar con estas matrices nuevas hay que comprender que representan, como se almacenan en la memoria
y, a su vez, como se almacenan las cadenas en estas matrices. Para poder almacenar una cadena, la matriz
que la va a alojar debe ser lo suficientemente larga como para acomodarla dentro de ella, es decir, que
debe tener la capacidad suficiente para almacenar dentro de ella, al menos, el mismo numero de caracteres
que la conforman mas uno.

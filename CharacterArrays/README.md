# 8. Matrices de Caracteres y Punteros ⛓️

_El concepto de matriz de caracteres es muy similar al concepto de cadena de caracteres ya que ambas
estan compuestas por un conjunto de caracteres encadenados que forman una palabra o una frase. Antes
de entender que representa una matriz de caracteres hay que entender las cadenas de caracteres._

## 8.1 Definiciones 📚

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
## 8.2 Declaracion ✍️
_Como bien hemos definido anteriormente, una cadena es una matriz unidimensional, por lo que a la hora
de **declararla** seguiremos las mismas reglas que las matrices. La **estructura** que hay que seguir
para **declarar** una cadena es la siguiente:_ **"tipo nombre[tamaño]"**.

```
Ejemplo de una Declaración
char C1[7];
char C2[21];
```

_El **tipo** siempre ha de ser **char** ya que los elementos que formaran la matriz seran de tipo 
'caracter', el **nombre** puede ser cualquiera y el **tamaño** ha de ser igual o superior al numero
de elementos de la cadena._

_Al **declarar** una matriz de caracteres lo que estamos haciendo es reservar un espacio de memoria de
tamaño igual a la sumatoria del peso de todos sus elementos. Como los elementos que constituyen este
tipo de matrices son de tipo 'caracter', cada elemento sumara 1 byte de espacio._

### 8.2.1 Memoria RAM 💾

_Estas tablas representan un espacio ficticio de la memoria RAM reservada por nuestro ordenador cuando se encuentra con la siguiente cadena: 'char C[5]' durante la ejecucion de un programa._

| Direccion | Contenido | Tamaño |
| --- | --- | --- |
| ++ |   | ++ |
| 218 |   | 1 byte |
| 213 - 217 | C | 5 bytes |
| 212 |   | 1 byte |
| -- |   | -- |

_Aqui se puede ver que el ordenador reserva un espacio de 5 bytes comprendido entre 213 y 217 inclusive para la matriz C._

| Direccion | Contenido | Elemento | Tamaño |
| --- | --- | --- | --- |
| ++ |   |   | ++ |
| 218 |   |   | 1 byte |
| 217 |   | C[4] | 1 byte |
| 216 |   | C[3] | 1 byte |
| 215 |   | C[2] | 1 byte |
| 214 |   | C[1] | 1 byte |
| 213 |   | C[0] | 1 byte |
| 212 |   |   | 1 byte |
| -- |   |   | -- |

_Aqui se puede ver el espacio reservado distribuido por cada elemento que forma la matriz C._

| Dirección | 212 | 213 | 214 | 215 | 216 | 217 | 218 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **Elemento** |   | C[0] | C[1] | C[2] | C[3] | C[4] |   |
| **Valor** |   |   |   |   |   |   |   |

_Esta tabla es una representacion horizontal de la de arriba._

## 8.3 Inicialización 🖨️

_Hay **dos requisitos** que cumplir a la hora de **inicializar una cadena**:_
- _Que los elementos que la constituyen la matriz sean caracteres, es decir, de tipo 'caracter(char)._
- _Que la matriz sea lo suficientemente larga como para almacenar la cadena dentro de ella. Para ello, deberá tener un tamaño igual al de la cadena mas uno, para almacenar el caracter nulo **'\0'**._

---

### 8.3.1 Caracter Nulo '\0' 🛑

_El caracter nulo es indispensable a la hora de inicializar y trabajar de forma correcta con las cadenas. Gracias a este caracter, que no es imprimible, el ordenador puede identificar cuando se termina la cadena, pudiendo diferenciar así entre distintas cadenas._

_Este elemento intrinseco en las cadenas fue implementado por cuestiones de seguridad relacionados con la longitud de la cadena. Si no se añade el caracter nulo al final de cada cadena, los espacios de memoria adyacentes seran tratados tambien como parte de la misma. Esto puede llevar a fallos o fugas de informacion interna del programa. Es muy importante que este tipo de errores sean prevenidos._

---

_Al igual que con el resto de matrices, podemos inicializar estas de distintas maneras siguiendo la estructura comentada anteriormente:_

- _Igualando la matriz a la cadena, asignandole o no un tamaño. De esta manera el caracter nulo viene implicito._

```
char C1[] = "cadena", char C2[] = "matriz de caracteres";
char C1[1000] = "cadena", char C2[1000] = "matriz de caracteres";
```

- _Igualando la matriz a la cadena caracter por caracter. De esta manera si hay que declarar el caracter nulo._

```
char C1[] = {'c', 'a', 'd', 'e', 'n', 'a', '\0'};
char C1[1000] = {'c', 'a', 'd', 'e', 'n', 'a', '\0'};
```

### 8.2.1 Memoria RAM 💾

_Estas tablas representan un espacio ficticio de la memoria RAM reservada por nuestro ordenador cuando se encuentra con la siguiente cadena: 'char C[7] = "cadena"' durante la ejecucion de un programa._

| Direccion | Contenido | Tamaño |
| --- | --- | --- |
| ++ |   | ++ |
| 220 |   | 1 byte |
| 213 - 219 | C | 7 bytes |
| 212 |   | 1 byte |
| -- |   | -- |

_Aqui se puede ver que el ordenador reserva un espacio de 7 bytes comprendido entre 213 y 219 inclusive para la matriz C._

| Direccion | Contenido | Elemento | Tamaño |
| --- | --- | --- | --- |
| ++ |   |   | ++ |
| 218 |   |   | 1 byte |
| 217 | '\0' | C[6] | 1 byte |
| 217 | 'a' | C[5] | 1 byte |
| 217 | 'n' | C[4] | 1 byte |
| 216 | 'e' | C[3] | 1 byte |
| 215 | 'd' | C[2] | 1 byte |
| 214 | 'a' | C[1] | 1 byte |
| 213 | 'c' | C[0] | 1 byte |
| 212 |   |   | 1 byte |
| -- |   |   | -- |

_Aqui se puede ver el espacio reservado distribuido por cada elemento que forma la matriz C._

| Dirección | 212 | 213 | 214 | 215 | 216 | 217 | 218 | 219 | 220 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **Elemento** |   | C[0] | C[1] | C[2] | C[3] | C[4] | C[5] | C[6] |   |
| **Valor** |   | 'c' | 'a' | 'd' | 'e' | 'n' | 'a' | '\0' |   |

_Esta tabla es una representacion horizontal de la de arriba._

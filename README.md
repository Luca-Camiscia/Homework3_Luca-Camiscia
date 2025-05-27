# Homework3_Luca-Camiscia

# Ejercicio 1

Este módulo implementa un sistema de almacenamiento y recuperación de datos de vuelo, que incluye mediciones de **posición** y **presión**. Utiliza **serialización binaria** para guardar y recuperar datos desde archivos.

## 📦 Estructura del proyecto

* `Clases.hpp`: Declaración de interfaces y clases (`Imediciones`, `MedicionBase`, `Presion`, `Posicion`, `SaveFlightData`)
* `MedicionBase.cpp`: Implementación del comportamiento común a todas las mediciones (manejo del tiempo).
* `Presion.cpp`: Implementación de la clase `Presion`, que almacena presión estática y dinámica.
* `Posicion.cpp`: Implementación de la clase `Posicion`, que almacena latitud, longitud y altitud.
* `SaveFlightData.cpp`: Encapsula un conjunto de mediciones (posición y presión) y permite su serialización/deserialización conjunta.
* `main.cpp`: Archivo de prueba. Crea datos, los serializa a un archivo binario, y luego los lee y muestra en pantalla.

## 🔧 Cómo compilar

```bash
g++ -std=c++17 main.cpp SaveFlightData.cpp Presion.cpp Posicion.cpp MedicionBase.cpp -o flight_logger
```

## ▶️ Cómo ejecutar

```bash
./flight_logger
```

La ejecución genera un archivo `data.dat` con los datos serializados. Luego se deserializan para comprobar la integridad de los datos leídos.

## 🛠️ Makefile

El proyecto incluye un `Makefile` para facilitar la compilación y ejecución. Puedes compilar y ejecutar el programa con:

```bash
make run
```

## 🧱 Clases principales

### `Imediciones` (interfaz)

Define métodos virtuales puros para serializar y deserializar.

### `MedicionBase`

Clase abstracta que maneja el tiempo de medición como un `unique_ptr<float>`.

### `Presion`

Hereda de `MedicionBase`. Almacena:

* `presionEstatica`
* `presionDinamica`

### `Posicion`

Hereda de `MedicionBase`. Almacena:

* `latitud`
* `longitud`
* `altitud`

### `SaveFlightData`

Agrupa una `Posicion` y una `Presion`. Permite serializarlas y deserializarlas de forma conjunta.

# Ejercicio 2

Este módulo implementa un sistema de figuras geométricas básicas y un procesador genérico para calcular sus áreas mediante especialización de templates en C++.

## 📦 Estructura del proyecto

* `Posicion.hpp`: Clase que representa un punto en el plano 2D.
* `Circulo.hpp`: Clase que representa un círculo definido por una posición central y un radio.
* `Elipse.hpp`: Clase que representa una elipse con posición central y dos semiejes.
* `Rectangulo.hpp`: Clase que representa un rectángulo definido por vértice superior izquierdo, ancho y largo.
* `ProcesadorFigura.hpp`: Template especializado para calcular el área de cada figura.
* `main.cpp`: Archivo de prueba. Crea figuras y muestra sus áreas usando el procesador.

## 🧱 Clases principales

### `Posicion`

Representa un punto en el plano 2D mediante una tupla `(x, y)`.

* **Constructores:**  
    `Posicion(double x, double y)`
* **Métodos:**  
    `void Set(double x, double y)`  
    `void SetX(double x)`  
    `void SetY(double y)`  
    `tuple<double, double> Get()`  
    `double GetX()`  
    `double GetY()`

### `Circulo`

Representa un círculo definido por una posición central (`Posicion`) y un radio (`double`).

* **Constructores:**  
    `Circulo(Posicion pos, double r)`
* **Métodos:**  
    `void Set(Posicion pos, double r)`  
    `void SetPos(Posicion pos)`  
    `void SetRad(double rad)`  
    `tuple<Posicion, double> Get()`  
    `Posicion GetPos()`  
    `double GetRad()`

### `Elipse`

Representa una elipse con una posición central (`Posicion`) y dos semiejes (`tuple<double, double>`).

* **Constructores:**  
    `Elipse(Posicion pos, tuple<double, double> semis)`
* **Métodos:**  
    `void Set(Posicion pos, tuple<double,double> semis)`  
    `void SetPos(Posicion pos)`  
    `void SetSemi1(double semi)`  
    `void SetSemi2(double semi)`  
    `tuple<Posicion, tuple<double,double>> Get()`  
    `Posicion GetPos()`  
    `double GetSemi1()`  
    `double GetSemi2()`

### `Rectangulo`

Representa un rectángulo definido por una posición (vértice superior izquierdo), ancho y largo.

* **Constructores:**  
    `Rectangulo(Posicion V, double ancho, double largo)`
* **Métodos:**  
    `void Set(Posicion V, double ancho, double largo)`  
    `void SetPos(Posicion V)`  
    `void SetAncho(double ancho)`  
    `void SetLargo(double largo)`  
    `tuple<Posicion, double, double> Get()`  
    `Posicion GetPos()`  
    `double GetLar()`  
    `double GetAncho()`

## 🧮 Template `ProcesadorFigura`

Clase template especializada para calcular el área de las figuras:

* General: `Area` retorna 0.
* Para `Posicion`: Área 0.
* Para `Circulo`: Área = π × radio².
* Para `Elipse`: Área = π × semieje₁ × semieje₂.
* Para `Rectangulo`: Área = ancho × largo.

## 🔧 Cómo compilar el código de ejemplo

Guarda el código en un archivo, por ejemplo `main.cpp`, y compílalo junto con las implementaciones necesarias:

```bash
g++ -std=c++17 main.cpp -o figuras
```

## 🛠️ Makefile

El proyecto incluye un `Makefile` para compilar y ejecutar fácilmente. Usa el siguiente comando:

```bash
make run
```

# Ejercicio 3

Este módulo implementa un sistema genérico en C++ para almacenar y serializar diferentes tipos de datos (`double`, `string` y `vector<int>`) en formato JSON, utilizando templates y especialización.

## 📦 Estructura del proyecto

* `clases.hpp`: Declaración e implementación de las clases `Clase1` (template) y `Clase2`.
* `main.cpp`: Archivo de prueba. Crea instancias de `Clase1` para distintos tipos, agrega datos, serializa a un archivo JSON (`data.JSON`) y muestra el contenido en consola.

## 🧱 Clases principales

### `Clase1<D>`

Template para manejar colecciones de datos homogéneos. Especializaciones para:

* `double`: Serializa como lista de números.
* `string`: Serializa como lista de strings entre comillas.
* `vector<int>`: Serializa como lista de arrays de enteros.

**Métodos:**
* `void Add(const D& new_dato)`: Agrega un dato.
* `string Process() const`: Devuelve la representación JSON parcial (sin corchetes externos).

### `Clase2`

Permite construir un objeto JSON completo a partir de varias instancias de `Clase1` de distintos tipos.

**Métodos:**
* `void JsonStart(ostream& out)`: Escribe `{` para iniciar el objeto JSON.
* `template<typename T> void JsonAdd(ostream& out, const Clase1<T>& datos)`: Añade una entrada al JSON con etiqueta y datos serializados.
* `void JsonEnd(ostream& out)`: Escribe `}` para cerrar el objeto JSON.
* `void JsonPrint(istream& in)`: Imprime el contenido de un archivo JSON en consola.

## ▶️ Cómo ejecutar

Compila y ejecuta el programa de prueba:

```bash
g++ -std=c++17 main.cpp -o json_example
./json_example
```

La ejecución genera un archivo `data.JSON` con los datos serializados y muestra su contenido en consola.

## 🛠️ Makefile

El proyecto incluye un `Makefile` para automatizar la compilación y ejecución. Puedes usar:

```bash
make run
```

## 📄 Ejemplo de salida JSON (`data.JSON`)

```json
{
"vec_doubles": [1.300000, 2.100000, 3.200000],
 "palabras": ["hola", "mundo"],
 "listas": [
    [1, 2], 
    [3, 4]
]
}
```
`
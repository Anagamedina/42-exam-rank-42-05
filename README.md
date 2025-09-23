# C++ - Conceptos

---

# 📘 Apuntes Técnicos de C++ (Orientados al Exam Rank 05 de 42)

## 🎯 Apuntes Específicos por Level

### 📚 Level-1: Ejercicios Fundamentales
**📁 Ubicación:** `05/level-1/APUNTES_LEVEL1.md`

Contiene apuntes detallados para los 3 ejercicios del Level-1:

#### 🔢 **BIGINT** - Números de Precisión Arbitraria
- **📁 Ubicación:** `05/level-1/bigint/`
- **📚 README:** [Ver README](05/level-1/bigint/README.md)
- **🎯 Características:** Sobrecarga de operadores, aritmética de precisión arbitraria
- **⚠️ Errores corregidos:** Función `addition` con carry

#### 🎯 **POLYSET** - Estructuras de Datos con Herencia
- **📁 Ubicación:** `05/level-1/polyset/`
- **📚 README:** [Ver README](05/level-1/polyset/README.md)
- **🎯 Características:** Herencia múltiple, polimorfismo, patrones de diseño
- **📄 Documentación completa:** [POLYSET_COMPLETO.md](05/level-1/polyset/POLYSET_COMPLETO.md)

#### 📐 **VECT2** - Vectores Matemáticos 2D
- **📁 Ubicación:** `05/level-1/vect2/`
- **📚 README:** [Ver README](05/level-1/vect2/README.md)
- **🎯 Características:** Operaciones vectoriales, sobrecarga de operadores
- **⚠️ Errores corregidos:** Operador `<<` con parámetro correcto

### 🎯 Level-2: Algoritmos Avanzados
**📁 Ubicación:** `05/level-2/APUNTES_LEVEL2.md`

Contiene apuntes detallados para los 2 ejercicios del Level-2:

#### 🔍 **BSQ** - Biggest Square (Programación Dinámica)
- **📁 Ubicación:** `05/level-2/bsq/`
- **📚 README:** [Ver README](05/level-2/README.md#bsq---biggest-square)
- **🎯 Características:** Programación dinámica, matriz DP, validación de mapas
- **📊 Complejidad:** O(rows × cols)

#### 🎮 **Game of Life** - Simulación de Autómatas Celulares
- **📁 Ubicación:** `05/level-2/game_of_life/`
- **📚 README:** [Ver README](05/level-2/README.md#game-of-life)
- **🎯 Características:** Simulación, reglas de Conway, comandos de dibujo
- **📊 Complejidad:** O(iterations × width × height)

### 📚 **Enlaces Rápidos:**
- [📁 Level-1 Completo](05/level-1/)
- [📁 Level-2 Completo](05/level-2/)
- [🧪 Ejemplos de Uso Level-2](05/level-2/EJEMPLOS_USO.md)

---

---

🔹 Orientación a Objetos

“La programación orientada a objetos es una metodología de programación que utiliza objetos como unidades fundamentales para estructurar programas. Estos objetos representan entidades del mundo real, combinando en una sola unidad los datos (atributos) y las operaciones (métodos) que actúan sobre dichos datos.”

## 1. Clases y Objetos

- **Clase** = abstracción → define atributos y comportamientos.
- **Objeto** = instancia concreta de una clase.

```cpp
class Persona {
private:
    std::string nombre;
public:
    Persona(std::string n) : nombre(n) {}
    void saludar() { std::cout << "Hola, soy " << nombre << "\\n"; }
};

```

👉 **Asociación UML:**

- Una **clase** define *qué es* algo.

🔹 Clase

“Una clase en C++ es una descripción de un conjunto de objetos que comparten la misma estructura y comportamiento. La clase define los atributos (datos) y métodos (operaciones) que caracterizan a los objetos que de ella se derivan.”

- Un **objeto** es *una instancia concreta*.

🔹 Objeto

“Un objeto es una instancia concreta de una clase, es decir, una entidad creada a partir de la definición de una clase, con valores específicos en sus atributos y con capacidad para ejecutar los métodos definidos en dicha clase.”

👉 **Patrón relacionado:** *Factory Method* (crear objetos de forma controlada).

---

## 2. Encapsulación (public, private, protected)

- Protege datos internos de la clase.
- `private` → solo accesible dentro de la clase.
- `protected` → accesible por clases hijas.
- `public` → accesible desde fuera.

```cpp
class Cuenta {
private:
    double saldo;
public:
    void depositar(double cantidad) { saldo += cantidad; }
    double getSaldo() const { return saldo; }
};

```

👉 **Asociación UML:** *Encapsulación* = restringir accesos.
👉 **Patrón relacionado:** *Singleton* (ejemplo clásico: constructor privado).

---

## 3. Constructores y Destructores

- **Constructor** → inicializa estado del objeto.
- **Destructor** → limpia recursos (memoria, archivos).

```cpp
class Archivo {
    std::fstream f;
public:
    Archivo(std::string path) { f.open(path); }
    ~Archivo() { f.close(); }
};

```

👉 **Asociación UML:** Ciclo de vida del objeto.
👉 **Patrón relacionado:** *RAII (Resource Acquisition Is Initialization)* → muy usado en C++.

---

## 4. Regla de 3 / Regla de 5

Si una clase gestiona recursos dinámicos:

- **Destructor**
- **Constructor de copia**
- **Operador de asignación**

En C++11 también:

- **Constructor de movimiento**
- **Operador de asignación por movimiento**

```cpp
class Buffer {
    char* data;
public:
    Buffer(size_t size) { data = new char[size]; }
    ~Buffer() { delete[] data; }
    Buffer(const Buffer& other); // copia
    Buffer& operator=(const Buffer& other); // asignación
};

```

👉 **Patrón relacionado:** *Prototype* (copias de objetos).

---

## 5. Herencia

“La herencia es el mecanismo que permite crear nuevas clases a partir de otras ya existentes, heredando sus atributos y métodos, y permitiendo además añadir o modificar el comportamiento de las clases derivadas. Este mecanismo fomenta la reutilización y extensión del código.”

- Relación “es-un” (*is-a*).
- Permite reutilizar código y extender funcionalidades.

```cpp
class Animal {
public:
    virtual void hacerSonido() const { std::cout << "Sonido genérico\\n"; }
};

class Perro : public Animal {
public:
    void hacerSonido() const override { std::cout << "Guau\\n"; }
};

```

👉 **Asociación UML:** Herencia (flecha con triángulo).
👉 **Patrón relacionado:** *Template Method* (definir estructura y que las subclases rellenen).

---

## 6. Polimorfismo

“El polimorfismo es la capacidad que tienen las funciones y los métodos de adoptar distintas formas según el contexto en el que se utilicen. En C++ el polimorfismo se puede dar de forma estática (sobrecarga de funciones y operadores) o de forma dinámica (mediante el uso de funciones virtuales en clases derivadas).”

- **Estático (overloading)**: varias funciones mismo nombre, distinta firma.
- **Dinámico (overriding)**: redefinir comportamiento con `virtual`.

```cpp
Animal* a = new Perro();
a->hacerSonido(); // "Guau"

```

👉 **Asociación UML:** Polimorfismo en relaciones padre-hijo.
👉 **Patrón relacionado:** *Strategy* (múltiples comportamientos intercambiables).

---

## 7. Asociación, Agregación y Composición

- **Asociación:** relación débil (ej: Profesor – Curso).
- **Agregación:** relación con independencia (ej: Equipo – Jugador).
- **Composición:** relación fuerte, ciclo de vida ligado (ej: Casa – Habitación).

```cpp
class Jugador { ... };
class Equipo {
    std::vector<Jugador*> jugadores; // agregación
};
class Motor { ... };
class Coche {
    Motor motor; // composición
};

```

👉 **Patrón relacionado:**

- Asociación → *Observer* (objetos enlazados).
- Composición → *Composite*.

---

## 8. Sobrecarga de Operadores

“La sobrecarga de operadores en C++ consiste en redefinir el funcionamiento de los operadores habituales (+, -, ==, etc.) cuando se aplican a objetos de clases definidas por el programador, de forma que se adapten al comportamiento esperado de dichas clases.”

Permite que clases se comporten como tipos nativos.

```cpp
class Vector {
    int x, y;
public:
    Vector(int a, int b): x(a), y(b) {}
    Vector operator+(const Vector& v) {
        return Vector(x + v.x, y + v.y);
    }
};

```

👉 **Patrón relacionado:** *Adapter* (adaptar interfaces).

---

## 9. Clases Abstractas e Interfaces

“Una clase abstracta es aquella que contiene, al menos, una función virtual pura, es decir, una función que no tiene implementación en la clase base y que debe ser redefinida obligatoriamente en las clases derivadas. Las clases abstractas no pueden instanciarse directamente, sino que sirven como plantillas para otras clases.”

- Clase con métodos virtuales puros (`= 0`).
- No se pueden instanciar, solo heredar.

```cpp
class Forma {
public:
    virtual void dibujar() const = 0;
};

```

👉 **Patrón relacionado:** *Bridge* (separa abstracción de implementación).

---

## 10. Templates (Genéricos)

“Las plantillas en C++ son un mecanismo que permite definir funciones y clases genéricas, es decir, independientes del tipo de dato. Con las plantillas se puede escribir un único código que funcione para diferentes tipos, favoreciendo la reutilización y flexibilidad del software.”

Permiten escribir código independiente del tipo.

```cpp
template<typename T>
T maximo(T a, T b) { return (a > b) ? a : b; }

```

👉 **Patrón relacionado:** *Strategy* + *Generic Programming*.

---

## 11. Excepciones

“Las excepciones en C++ constituyen un mecanismo para el manejo de errores y condiciones excepcionales que se presentan durante la ejecución de un programa. Con el uso de sentencias try, catch y throw se logra separar el código de manejo de errores del código principal, mejorando la claridad y robustez del programa.”

Manejo de errores con `try/catch`.

```cpp
try {
    throw std::runtime_error("Error");
} catch (const std::exception& e) {
    std::cout << e.what();
}

```

👉 **Patrón relacionado:** *Chain of Responsibility* (manejo de errores encadenados).

---

## 12. STL (Standard Template Library)

- **Contenedores**: `vector`, `list`, `map`, `set`.
- **Iteradores**: como punteros para recorrer colecciones.
- **Algoritmos**: `std::sort`, `std::find`, `std::for_each`.

```cpp
std::vector<int> v = {3,1,4};
std::sort(v.begin(), v.end());

```

👉 **Patrón relacionado:** *Iterator*.

---

**🔹 Ligadura y Funciones Virtuales**

“La ligadura es el proceso mediante el cual el compilador asocia una llamada a una función con el código que la implementa. En C++ existen dos tipos de ligadura: la estática, que se realiza en tiempo de compilación, y la dinámica, que se realiza en tiempo de ejecución a través de funciones virtuales. Las funciones virtuales permiten que una llamada a un método en un puntero o referencia a una clase base invoque la versión redefinida en la clase derivada, habilitando el polimorfismo dinámico.”

**🔹 Flujos y Archivos**

“Los flujos en C++ representan secuencias de datos que pueden ser de entrada (lectura) o de salida (escritura). El lenguaje proporciona clases especializadas como ifstream para lectura de archivos, ofstream para escritura y fstream para ambos propósitos. El manejo de archivos mediante flujos permite leer y escribir datos de manera estructurada y orientada a objetos.”

**🔹 Pilas y Colas**

“Las pilas y colas son estructuras de datos dinámicas que permiten almacenar y recuperar información siguiendo reglas específicas. Una pila (stack) sigue la política LIFO (Last In, First Out), mientras que una cola (queue) sigue la política FIFO (First In, First Out). En C++ la STL proporciona implementaciones de ambas estructuras, facilitando su uso en programas.”

**🔹 Recursividad**

“La recursividad es una técnica de programación en la cual una función se llama a sí misma, directa o indirectamente, para resolver un problema. El diseño de algoritmos recursivos requiere identificar un caso base, que detiene la recursión, y un caso recursivo, que divide el problema en subproblemas de menor tamaño.”

**🔹 Árboles Binarios**

“Un árbol binario es una estructura de datos jerárquica en la que cada nodo tiene, como máximo, dos subárboles denominados hijo izquierdo e hijo derecho. Los árboles binarios son utilizados para representar relaciones jerárquicas y permiten operaciones eficientes de búsqueda, inserción y eliminación. En C++ se pueden implementar mediante nodos enlazados dinámicamente, cada uno de los cuales contiene un dato y punteros a sus hijos.”

🔹 Arrays de Funciones Miembro

“En C++ es posible declarar arreglos de punteros a funciones miembro de una clase, lo que permite almacenar y manejar de manera dinámica diferentes comportamientos asociados a objetos. Para acceder a estas funciones se requiere utilizar la sintaxis de punteros a miembros junto con el operador .* o ->* dependiendo de si se trata de un objeto o un puntero a objeto.”

🔹 Copia Superficial (Shallow Copy) y Copia Profunda (Deep Copy)

“La copia superficial es aquella en la que al copiar un objeto a otro se duplican únicamente los valores de los atributos, incluidos los punteros, de modo que ambos objetos terminan compartiendo las mismas direcciones de memoria. En cambio, la copia profunda consiste en crear nuevas áreas de memoria para los punteros, de forma que el objeto copiado disponga de sus propios datos independientes del original.”

🔹 Asociación

“La asociación es una relación entre dos clases que indica que los objetos de una clase se utilizan en la otra. Puede ser de tipo uno a uno, uno a muchos o muchos a muchos. A diferencia de la herencia, la asociación no implica una relación jerárquica, sino de colaboración entre clases.”

[Manejo de excepciones (solo C++)](https://www.ibm.com/docs/es/i/7.5.0?topic=reference-exception-handling-c-only)

[Manejo de excepciones y errores | Apuntes lenguaje C++ | Hektor Profe](https://hektorprofe.github.io/cpp/13-manejo-excepciones/)

[¿Qué es un patrón de diseño?](https://refactoring.guru/es/design-patterns/what-is-pattern)

[Patrones de diseno POO](https://www.notion.so/Patrones-de-diseno-POO-276c25dc1abf80a88f68e14b3964791b?pvs=21)

---

## 🔧 Errores Corregidos en Level-1

### ❌ Errores Encontrados y Solucionados:

#### 1. **bigint.cpp** - Función `addition`
**Problema:** No se reseteaba el `carry` cuando `res <= 9`
```cpp
// ❌ ANTES (incorrecto)
if(res > 9) {
    carry = res / 10;
    result.push_back((res % 10) + '0');
} else
    result.push_back(res + '0');  // carry no se resetea

// ✅ DESPUÉS (corregido)
if(res > 9) {
    carry = res / 10;
    result.push_back((res % 10) + '0');
} else {
    carry = 0;  // ¡IMPORTANTE! Resetear carry
    result.push_back(res + '0');
}
```

#### 2. **vect2.cpp** - Operador `<<`
**Problema:** Usaba `std::cout` en lugar del parámetro `os`
```cpp
// ❌ ANTES (incorrecto)
std::ostream& operator<<(std::ostream& os, const vect2& obj) {
    std::cout << "{" << obj[0] << ", " << obj[1] << "}";
    return(os);
}

// ✅ DESPUÉS (corregido)
std::ostream& operator<<(std::ostream& os, const vect2& obj) {
    os << "{" << obj[0] << ", " << obj[1] << "}";
    return(os);
}
```

### 🎯 Lecciones Aprendidas:
1. **Siempre resetear variables de estado** en bucles
2. **Usar parámetros de función** en lugar de variables globales
3. **Validar casos edge** en algoritmos matemáticos
4. **Probar con diferentes flujos de datos** para detectar errores

---

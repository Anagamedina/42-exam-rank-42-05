# 🎯 POLYSET - Estructuras de Datos con Herencia

## 📋 **Descripción del Ejercicio**

**POLYSET** implementa un sistema de **contenedores (bags)** con capacidades de búsqueda usando **herencia múltiple** y **polimorfismo**.

### 🎯 **Objetivo:**
- Implementar diferentes tipos de contenedores
- Añadir capacidades de búsqueda
- Crear un wrapper que convierta bags en sets

---

## 🏗️ **Estructura de Clases**

### **Jerarquía de Herencia:**
```
bag (abstracta)
├── array_bag (implementación con array)
└── tree_bag (implementación con BST)

searchable_bag (abstracta)
├── searchable_array_bag (hereda de array_bag + searchable_bag)
└── searchable_tree_bag (hereda de tree_bag + searchable_bag)

set (wrapper que convierte searchable_bag en set)
```

---

## 📚 **Clases Implementadas**

### **1. `bag` (Clase Abstracta)**
- **Propósito:** Representa un contenedor genérico
- **Métodos:** `insert()`, `print()`, `clear()`
- **Características:** No permite duplicados, orden no importa

### **2. `array_bag` (Implementación con Array)**
- **Herencia:** `virtual public bag`
- **Estructura:** Array dinámico
- **Operaciones:** Insertar, imprimir, limpiar
- **Ventajas:** Acceso rápido, simple implementación
- **Desventajas:** Búsqueda O(n)

### **3. `tree_bag` (Implementación con BST)**
- **Herencia:** `virtual public bag`
- **Estructura:** Árbol binario de búsqueda
- **Operaciones:** Insertar, imprimir, limpiar
- **Ventajas:** Búsqueda O(log n)
- **Desventajas:** Más complejo, balanceo necesario

### **4. `searchable_bag` (Clase Abstracta)**
- **Propósito:** Añade capacidad de búsqueda a un bag
- **Métodos:** `has()`, `search()`
- **Características:** Permite verificar si un elemento existe

### **5. `searchable_array_bag` (Herencia Múltiple)**
- **Herencia:** `public array_bag, public searchable_bag`
- **Funcionalidad:** Combina array_bag con capacidades de búsqueda
- **Búsqueda:** Lineal O(n)

### **6. `searchable_tree_bag` (Herencia Múltiple)**
- **Herencia:** `public tree_bag, public searchable_bag`
- **Funcionalidad:** Combina tree_bag con capacidades de búsqueda
- **Búsqueda:** Logarítmica O(log n)

### **7. `set` (Wrapper)**
- **Propósito:** Convierte un searchable_bag en un set
- **Características:** Elimina duplicados automáticamente
- **Métodos:** `insert()`, `has()`, `print()`, `clear()`

---

## 🔧 **Implementación de Clases**

### **array_bag:**
```cpp
class array_bag : virtual public bag
{
protected:
    int *data;  // Array dinámico para almacenar elementos
    int size;   // Número de elementos en el array

public:
    // Constructores, destructor, operadores
    void insert(int);                               // Insertar un elemento
    void insert(int *, int);                        // Insertar array de elementos
    void print() const;                             // Imprimir todos los elementos
    void clear();                                   // Limpiar el bag
};
```

### **tree_bag:**
```cpp
class tree_bag : virtual public bag
{
protected:
    struct node {
        node *l;      // Hijo izquierdo
        node *r;      // Hijo derecho
        int value;    // Valor del nodo
    };
    node *tree;     // Nodo raíz del árbol

public:
    // Constructores, destructor, operadores
    virtual void insert(int);                      // Insertar un elemento
    virtual void print() const;                   // Imprimir todos los elementos
    virtual void clear();                         // Limpiar el bag
};
```

### **searchable_bag:**
```cpp
class searchable_bag
{
public:
    virtual bool has(int) const = 0;              // Verificar si existe
    virtual int search(int) const = 0;            // Buscar elemento
    virtual ~searchable_bag() = default;          // Destructor virtual
};
```

---

## 📊 **Ejemplos de Uso**

### **Uso Básico:**
```cpp
#include "searchable_bag.hpp"
#include "set.hpp"

int main(int argc, char **argv) {
    if (argc == 1) return 1;
    
    // Crear bags searchables
    searchable_bag *t = new searchable_tree_bag;
    searchable_bag *a = new searchable_array_bag;
    
    // Insertar elementos
    for (int i = 1; i < argc; i++) {
        t->insert(atoi(argv[i]));
        a->insert(atoi(argv[i]));
    }
    
    // Imprimir contenido
    t->print();
    a->print();
    
    // Buscar elementos
    for (int i = 1; i < argc; i++) {
        std::cout << t->has(atoi(argv[i])) << std::endl;
        std::cout << a->has(atoi(argv[i])) << std::endl;
    }
    
    return 0;
}
```

### **Uso con Set:**
```cpp
// Crear set desde searchable_bag
set sa(*a);
set st(*t);

// Operaciones de set
sa.insert(42);
sa.has(42);
sa.print();
sa.clear();
```

---

## 🏗️ **Patrones de Diseño Utilizados**

### **1. Template Method Pattern**
- **Clase abstracta** `bag` define la interfaz
- **Clases concretas** implementan los métodos

### **2. Strategy Pattern**
- **Diferentes implementaciones** (array vs tree)
- **Intercambiables** según necesidades

### **3. Adapter Pattern**
- **Clase `set`** adapta searchable_bag a set
- **Wrapper** que añade funcionalidad

### **4. Multiple Inheritance**
- **searchable_array_bag** hereda de dos clases
- **Diamond problem** resuelto con virtual inheritance

---

## ⚠️ **Consideraciones Importantes**

### **Herencia Virtual:**
```cpp
class array_bag : virtual public bag
class searchable_array_bag : public array_bag, public searchable_bag
```

### **Manejo de Memoria:**
- **RAII** en constructores/destructores
- **Rule of 3/5** para clases con recursos
- **Liberación correcta** de memoria dinámica

### **Polimorfismo:**
- **Punteros a clases base** para polimorfismo
- **Virtual destructors** para liberación correcta
- **Pure virtual functions** en clases abstractas

---

## 🚀 **Compilación y Uso**

### **Compilar:**
```bash
cd 05/level-1/polyset
g++ -o polyset main.cpp array_bag.cpp tree_bag.cpp searchable_array_bag.cpp searchable_tree_bag.cpp set.cpp
```

### **Ejecutar:**
```bash
./polyset 1 2 3 4 5
```

### **Ejemplo de Salida:**
```
1 2 3 4 5  # tree_bag
1 2 3 4 5  # array_bag
1 1 1 1 1  # has() results
1 1 1 1 1  # has() results
0 0 0 0 0  # has() results (elementos - 1)
0 0 0 0 0  # has() results (elementos - 1)
```

---

## 📚 **Conceptos de C++ Aplicados**

### **1. Herencia Múltiple:**
- **Diamond problem** y virtual inheritance
- **Resolución de ambigüedades** en herencia múltiple
- **Virtual destructors** para liberación correcta

### **2. Polimorfismo:**
- **Punteros a clases base** para polimorfismo
- **Virtual functions** para comportamiento dinámico
- **Pure virtual functions** en clases abstractas

### **3. Gestión de Memoria:**
- **RAII** - Resource Acquisition Is Initialization
- **Rule of 3/5** - Constructor, copia, asignación, destructor
- **Smart pointers** para gestión automática

---

## 🎯 **Consejos para el Examen**

1. **Entender herencia múltiple** - Diamond problem y virtual inheritance
2. **Implementar forma canónica** - Constructor, copia, asignación, destructor
3. **Manejar memoria correctamente** - RAII y Rule of 3/5
4. **Usar const** donde corresponda
5. **Probar con diferentes tipos** - Array vs Tree
6. **Validar funcionalidad** - Insertar, buscar, imprimir, limpiar

---

## 📊 **Complejidad de Operaciones**

| Operación | Array Bag | Tree Bag |
|-----------|------------|----------|
| **Insertar** | O(1) | O(log n) |
| **Buscar** | O(n) | O(log n) |
| **Imprimir** | O(n) | O(n) |
| **Limpiar** | O(1) | O(n) |

---

## 🔗 **Enlaces Relacionados**

- [📚 Apuntes Level-1](../APUNTES_LEVEL1.md)
- [📁 Ejercicio BIGINT](../bigint/README.md)
- [📁 Ejercicio VECT2](../vect2/README.md)
- [📄 Documentación Completa](POLYSET_COMPLETO.md)
- [🏠 README Principal](../../../README.md)

---

## 🎯 **Resumen**

**POLYSET** es un ejercicio completo que combina:
- **Herencia múltiple**
- **Polimorfismo**
- **Estructuras de datos** (Array vs Tree)
- **Patrones de diseño**
- **Gestión de memoria**

¡Es un excelente ejercicio para practicar conceptos avanzados de C++! 🚀

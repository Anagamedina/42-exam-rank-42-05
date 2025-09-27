# 🎯 POLYSET - Ejercicio Completo

## 📋 **Descripción del Ejercicio**

**POLYSET** es un ejercicio de **herencia múltiple** y **polimorfismo** que implementa diferentes tipos de contenedores (bags) con capacidades de búsqueda.

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

## 🔧 **Implementación Requerida**

### **Archivos Esperados:**
- `searchable_array_bag.cpp`
- `searchable_array_bag.hpp`
- `searchable_tree_bag.cpp`
- `searchable_tree_bag.hpp`
- `set.cpp`
- `set.hpp`

### **Forma Canónica Ortodoxa:**
- **Constructor por defecto**
- **Constructor de copia**
- **Operador de asignación**
- **Destructor**
- **Métodos const** donde corresponda

---

## 🎯 **Ejemplo de Uso**

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
    
    // Usar como set
    set sa(*a);
    set st(*t);
    
    // Operaciones de set
    sa.insert(42);
    sa.has(42);
    sa.print();
    
    return 0;
}
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

## 🚀 **Optimizaciones Posibles**

### **Array Bag:**
- **Búsqueda binaria** si se mantiene ordenado
- **Hash table** para búsqueda O(1)

### **Tree Bag:**
- **AVL Tree** para balanceo automático
- **Red-Black Tree** para mejor rendimiento

---

## 📝 **Resumen**

**POLYSET** es un ejercicio completo que combina:
- **Herencia múltiple**
- **Polimorfismo**
- **Estructuras de datos** (Array vs Tree)
- **Patrones de diseño**
- **Gestión de memoria**

¡Es un excelente ejercicio para practicar conceptos avanzados de C++! 🎯


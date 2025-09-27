# 🔢 BIGINT - Números de Precisión Arbitraria

## 📋 **Descripción del Ejercicio**

**BIGINT** implementa una clase para manejar números enteros de **precisión arbitraria**, superando las limitaciones de los tipos primitivos de C++.

### 🎯 **Objetivo:**
- Manejar números enteros de cualquier tamaño
- Implementar operaciones aritméticas básicas
- Soporte para operadores de flujo y comparación

---

## 🏗️ **Estructura de la Clase**

### **Atributos:**
```cpp
private:
    std::string str;  // Almacena el número como string
```

### **Constructores:**
- `bigint()` - Constructor por defecto (valor 0)
- `bigint(unsigned int num)` - Constructor con entero
- `bigint(const bigint& other)` - Constructor de copia

### **Operadores Implementados:**
- **Aritméticos:** `+`, `+=`, `-`, `-=`, `*`, `*=`
- **Incremento/Decremento:** `++` (pre/post), `--` (pre/post)
- **Desplazamiento:** `<<`, `>>`, `<<=`, `>>=`
- **Comparación:** `==`, `!=`, `<`, `>`, `<=`, `>=`
- **Acceso:** `[]` (lectura y escritura)
- **Flujo:** `<<`, `>>`

---

## 🔧 **Algoritmos Implementados**

### **1. Suma de Números Grandes:**
```cpp
std::string addition(const bigint& obj1, const bigint& obj2)
{
    // Algoritmo de suma con carry
    // Maneja números de diferentes longitudes
    // Retorna el resultado como string
}
```

### **2. Conversión de String a Entero:**
```cpp
unsigned int stringToUINT(const std::string& str)
{
    // Convierte string a unsigned int
    // Maneja overflow y validación
}
```

### **3. Operaciones de Desplazamiento:**
```cpp
// Desplazamiento a la izquierda (multiplicación por 2^n)
bigint operator<<(unsigned int n) const;

// Desplazamiento a la derecha (división por 2^n)
bigint operator>>(unsigned int n) const;
```

---

## 📊 **Ejemplos de Uso**

### **Creación y Operaciones Básicas:**
```cpp
bigint a(123456789);
bigint b(987654321);
bigint c = a + b;
bigint d = a * b;

std::cout << "a = " << a << std::endl;
std::cout << "b = " << b << std::endl;
std::cout << "c = a + b = " << c << std::endl;
std::cout << "d = a * b = " << d << std::endl;
```

### **Operadores de Incremento:**
```cpp
bigint x(999);
std::cout << "x = " << x << std::endl;  // 999
std::cout << "++x = " << ++x << std::endl;  // 1000
std::cout << "x++ = " << x++ << std::endl;  // 1000
std::cout << "x = " << x << std::endl;  // 1001
```

### **Operadores de Desplazamiento:**
```cpp
bigint y(5);
std::cout << "y = " << y << std::endl;  // 5
std::cout << "y << 2 = " << (y << 2) << std::endl;  // 20
std::cout << "y >> 1 = " << (y >> 1) << std::endl;  // 2
```

---

## ⚠️ **Errores Corregidos**

### **Error 1: Función `addition`**
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

---

## 🎯 **Características Técnicas**

### **Gestión de Memoria:**
- **RAII** - Resource Acquisition Is Initialization
- **Rule of 3/5** - Constructor, copia, asignación, destructor
- **Sin memory leaks** - Gestión automática con std::string

### **Optimizaciones:**
- **Almacenamiento como string** - Fácil manipulación
- **Operaciones in-place** - Evita copias innecesarias
- **Validación de entrada** - Previene errores

### **Compatibilidad:**
- **STL compatible** - Funciona con algoritmos estándar
- **Operadores estándar** - Sintaxis natural de C++
- **Streams** - Integración con iostream

---

## 🚀 **Compilación y Uso**

### **Compilar:**
```bash
cd 05/level-1/bigint
g++ -o bigint main.cpp bigint.cpp
```

### **Ejecutar:**
```bash
./bigint
```

### **Ejemplo de Salida:**
```
a = 123456789
b = 987654321
c = a + b = 1111111110
d = a * b = 121932631112635269
```

---

## 📚 **Conceptos de C++ Aplicados**

### **1. Sobrecarga de Operadores:**
- **Operadores aritméticos** - `+`, `-`, `*`
- **Operadores de asignación** - `+=`, `-=`, `*=`
- **Operadores de comparación** - `==`, `!=`, `<`, `>`
- **Operadores de flujo** - `<<`, `>>`

### **2. Gestión de Memoria:**
- **Constructores** - Inicialización correcta
- **Destructores** - Liberación de recursos
- **Operadores de asignación** - Evitar auto-asignación

### **3. Algoritmos:**
- **Suma con carry** - Algoritmo clásico de aritmética
- **Conversión de tipos** - String a entero
- **Validación de entrada** - Prevención de errores

---

## 🎯 **Consejos para el Examen**

1. **Entender la aritmética** - Cómo funciona la suma con carry
2. **Manejar overflow** - Validar límites de tipos
3. **Implementar operadores** - Sintaxis correcta de C++
4. **Probar casos edge** - Números muy grandes, cero, negativos
5. **Optimizar memoria** - Evitar copias innecesarias

---

## 📊 **Complejidad de Operaciones**

| Operación | Complejidad | Descripción |
|-----------|-------------|-------------|
| **Suma** | O(n) | n = longitud del número más largo |
| **Multiplicación** | O(n²) | n = longitud del número más largo |
| **Comparación** | O(n) | n = longitud del número más largo |
| **Desplazamiento** | O(n) | n = longitud del número |

---

## 🔗 **Enlaces Relacionados**

- [📚 Apuntes Level-1](../APUNTES_LEVEL1.md)
- [📁 Ejercicio VECT2](../vect2/README.md)
- [📁 Ejercicio POLYSET](../polyset/README.md)
- [🏠 README Principal](../../../README.md)

---

## 🎯 **Resumen**

**BIGINT** es un ejercicio fundamental que demuestra:
- **Sobrecarga de operadores** en C++
- **Gestión de memoria** con RAII
- **Algoritmos de aritmética** de precisión arbitraria
- **Integración con STL** y streams

¡Es un excelente ejercicio para practicar conceptos avanzados de C++! 🚀


# 📐 VECT2 - Vectores Matemáticos 2D

## 📋 **Descripción del Ejercicio**

**VECT2** implementa una clase para manejar **vectores matemáticos 2D** con operaciones aritméticas, comparaciones y acceso por índice.

### 🎯 **Objetivo:**
- Representar vectores 2D con componentes enteras
- Implementar operaciones matemáticas básicas
- Soporte para operadores de incremento/decremento

---

## 🏗️ **Estructura de la Clase**

### **Atributos:**
```cpp
private:
    int x, y;  // Componentes del vector
```

### **Constructores:**
- `vect2()` - Constructor por defecto (0,0)
- `vect2(int num1, int num2)` - Constructor con valores
- `vect2(const vect2& source)` - Constructor de copia

### **Operadores Implementados:**
- **Aritméticos:** `+`, `-`, `*` (escalar y elemento a elemento)
- **Asignación:** `+=`, `-=`, `*=`
- **Incremento/Decremento:** `++` (pre/post), `--` (pre/post)
- **Acceso:** `[]` (lectura y escritura)
- **Comparación:** `==`, `!=`
- **Unarios:** `-` (negación)
- **Flujo:** `<<`

---

## 🔧 **Operaciones Matemáticas**

### **1. Suma de Vectores:**
```cpp
vect2 operator+(const vect2& obj) const
{
    vect2 temp = *this;
    temp.x += obj.x;
    temp.y += obj.y;
    return temp;
}
```

### **2. Multiplicación por Escalar:**
```cpp
vect2 operator*(int num) const
{
    vect2 temp;
    temp.x = this->x * num;
    temp.y = this->y * num;
    return temp;
}
```

### **3. Multiplicación Elemento a Elemento:**
```cpp
vect2 operator*(const vect2& obj) const
{
    vect2 temp = *this;
    temp.x *= obj.x;
    temp.y *= obj.y;
    return temp;
}
```

### **4. Negación del Vector:**
```cpp
vect2 operator-() const
{
    vect2 temp = *this;
    temp[0] = -temp[0];
    temp[1] = -temp[1];
    return temp;
}
```

---

## 📊 **Ejemplos de Uso**

### **Creación y Operaciones Básicas:**
```cpp
vect2 v1(3, 4);
vect2 v2(1, 2);
vect2 v3 = v1 + v2;  // (4, 6)
vect2 v4 = v1 * 2;   // (6, 8)
vect2 v5 = v1 * v2;  // (3, 8) - elemento a elemento

std::cout << "v1 = " << v1 << std::endl;  // {3, 4}
std::cout << "v2 = " << v2 << std::endl;  // {1, 2}
std::cout << "v3 = " << v3 << std::endl;  // {4, 6}
```

### **Operadores de Incremento:**
```cpp
vect2 v(5, 7);
std::cout << "v = " << v << std::endl;  // {5, 7}
std::cout << "++v = " << ++v << std::endl;  // {6, 8}
std::cout << "v++ = " << v++ << std::endl;  // {6, 8}
std::cout << "v = " << v << std::endl;  // {7, 9}
```

### **Acceso por Índice:**
```cpp
vect2 v(10, 20);
std::cout << "v[0] = " << v[0] << std::endl;  // 10
std::cout << "v[1] = " << v[1] << std::endl;  // 20

v[0] = 15;  // Modificar componente x
v[1] = 25;  // Modificar componente y
std::cout << "v = " << v << std::endl;  // {15, 25}
```

### **Operadores de Asignación:**
```cpp
vect2 v1(1, 2);
vect2 v2(3, 4);

v1 += v2;  // v1 = {4, 6}
v1 *= 2;   // v1 = {8, 12}
v1 -= v2;  // v1 = {5, 8}

std::cout << "v1 = " << v1 << std::endl;  // {5, 8}
```

---

## ⚠️ **Errores Corregidos**

### **Error 1: Operador `<<`**
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

---

## 🎯 **Características Técnicas**

### **Gestión de Memoria:**
- **Sin memoria dinámica** - Solo variables locales
- **RAII** - Resource Acquisition Is Initialization
- **Rule of 3/5** - Constructor, copia, asignación, destructor

### **Optimizaciones:**
- **Operaciones in-place** - Evita copias innecesarias
- **Acceso directo** - Sin overhead de funciones
- **Validación de índices** - Previene errores de acceso

### **Compatibilidad:**
- **STL compatible** - Funciona con algoritmos estándar
- **Operadores estándar** - Sintaxis natural de C++
- **Streams** - Integración con iostream

---

## 🚀 **Compilación y Uso**

### **Compilar:**
```bash
cd 05/level-1/vect2
g++ -o vect2 main.cpp vect2.cpp
```

### **Ejecutar:**
```bash
./vect2
```

### **Ejemplo de Salida:**
```
v1 = {3, 4}
v2 = {1, 2}
v1 + v2 = {4, 6}
v1 * 2 = {6, 8}
v1 * v2 = {3, 8}
```

---

## 📚 **Conceptos de C++ Aplicados**

### **1. Sobrecarga de Operadores:**
- **Operadores aritméticos** - `+`, `-`, `*`
- **Operadores de asignación** - `+=`, `-=`, `*=`
- **Operadores de comparación** - `==`, `!=`
- **Operadores de flujo** - `<<`

### **2. Gestión de Memoria:**
- **Constructores** - Inicialización correcta
- **Destructores** - Liberación de recursos
- **Operadores de asignación** - Evitar auto-asignación

### **3. Algoritmos:**
- **Operaciones vectoriales** - Suma, resta, multiplicación
- **Acceso por índice** - Validación de límites
- **Conversión de tipos** - Implícita y explícita

---

## 🎯 **Consejos para el Examen**

1. **Entender la matemática** - Cómo funcionan las operaciones vectoriales
2. **Implementar operadores** - Sintaxis correcta de C++
3. **Manejar índices** - Validar acceso a componentes
4. **Probar casos edge** - Vectores cero, negativos, grandes
5. **Optimizar rendimiento** - Evitar copias innecesarias

---

## 📊 **Complejidad de Operaciones**

| Operación | Complejidad | Descripción |
|-----------|-------------|-------------|
| **Suma** | O(1) | Operación directa en componentes |
| **Resta** | O(1) | Operación directa en componentes |
| **Multiplicación escalar** | O(1) | Operación directa en componentes |
| **Multiplicación elemento a elemento** | O(1) | Operación directa en componentes |
| **Acceso por índice** | O(1) | Acceso directo a componentes |

---

## 🔗 **Enlaces Relacionados**

- [📚 Apuntes Level-1](../APUNTES_LEVEL1.md)
- [📁 Ejercicio BIGINT](../bigint/README.md)
- [📁 Ejercicio POLYSET](../polyset/README.md)
- [🏠 README Principal](../../../README.md)

---

## 🎯 **Resumen**

**VECT2** es un ejercicio fundamental que demuestra:
- **Sobrecarga de operadores** en C++
- **Operaciones matemáticas** con vectores
- **Gestión de memoria** con RAII
- **Integración con STL** y streams

¡Es un excelente ejercicio para practicar conceptos básicos de C++! 🚀

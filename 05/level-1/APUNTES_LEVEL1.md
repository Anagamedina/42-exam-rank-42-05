# 📚 Apuntes Level-1 - Exam Rank 05

## 🎯 Resumen de Ejercicios

El Level-1 del Exam Rank 05 contiene **3 ejercicios fundamentales** que evalúan conceptos clave de C++:

1. **`bigint`** - Números de precisión arbitraria
2. **`polyset`** - Estructuras de datos (bags y sets) con herencia
3. **`vect2`** - Vectores matemáticos 2D con sobrecarga de operadores

---

## 🔢 Ejercicio 1: BIGINT

### 📋 Enunciado
Crear una clase `bigint` que represente números enteros de precisión arbitraria (más grandes que `SIZE_MAX`).

### 🎯 Conceptos Evaluados
- **Sobrecarga de operadores** (+, +=, ++, <<, >>, comparaciones)
- **Manejo de strings** para representar números grandes
- **Constructores y destructores**
- **Operadores de flujo** (`<<` para output)

### 🔧 Implementación Clave

#### Estructura de la Clase
```cpp
class bigint {
private:
    std::string str;  // Almacena el número como string
    
public:
    // Constructores
    bigint();                    // Constructor por defecto
    bigint(unsigned int num);    // Constructor con entero
    bigint(const bigint& source); // Constructor de copia
    
    // Operadores aritméticos
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    bigint& operator++();        // Pre-incremento
    bigint operator++(int);      // Post-incremento
    
    // Operadores de desplazamiento (digitshift)
    bigint operator<<(unsigned int n) const;  // 42 << 3 = 42000
    bigint operator>>(unsigned int n) const;  // 1337 >> 2 = 13
    
    // Operadores de comparación
    bool operator==(const bigint& other) const;
    bool operator<(const bigint& other) const;
    // ... otros operadores de comparación
};
```

#### Algoritmo de Suma
```cpp
std::string addition(const bigint& obj1, const bigint& obj2) {
    // 1. Invertir strings para facilitar suma
    std::string str1 = reverse(obj1.getStr());
    std::string str2 = reverse(obj2.getStr());
    
    // 2. Igualar longitudes con ceros
    // 3. Sumar dígito por dígito con carry
    int carry = 0;
    for (size_t i = 0; i < len; i++) {
        int res = digit1 + digit2 + carry;
        if (res > 9) {
            carry = res / 10;
            result.push_back((res % 10) + '0');
        } else {
            carry = 0;  // ¡IMPORTANTE! Resetear carry
            result.push_back(res + '0');
        }
    }
    if (carry != 0)
        result.push_back(carry + '0');
    
    return reverse(result);
}
```

### ⚠️ Errores Comunes
1. **No resetear carry**: En la suma, si `res <= 9`, hay que poner `carry = 0`
2. **Comparaciones incorrectas**: Para `<`, comparar primero longitud, luego lexicográficamente
3. **Memory leaks**: No liberar memoria en destructores

### 🧪 Casos de Prueba
```cpp
const bigint a(42);
bigint b(21);
std::cout << "a + b = " << a + b << std::endl;  // 63
std::cout << "(42 << 3) = " << (a << 3) << std::endl;  // 42000
std::cout << "(1337 >> 2) = " << (bigint(1337) >> 2) << std::endl;  // 13
```

---

## 🎒 Ejercicio 2: POLYSET

### 📋 Enunciado
Implementar un sistema de bags (multisets) y sets usando herencia y polimorfismo.

### 🎯 Conceptos Evaluados
- **Herencia virtual** (`virtual public`)
- **Clases abstractas** (interfaces)
- **Polimorfismo dinámico**
- **Estructuras de datos** (arrays y árboles binarios)
- **Regla de 3/5** (constructores, destructores, operadores)

### 🏗️ Arquitectura del Sistema

#### Jerarquía de Clases
```
bag (abstract)
├── array_bag (concrete)
│   └── searchable_array_bag
└── tree_bag (concrete)
    └── searchable_tree_bag

searchable_bag (abstract)
├── searchable_array_bag
└── searchable_tree_bag

set (wrapper)
```

#### Clases Base
```cpp
// Interface para bag
class bag {
public:
    virtual void insert(int) = 0;
    virtual void insert(int*, int) = 0;
    virtual void print() const = 0;
    virtual void clear() = 0;
};

// Interface para bag con búsqueda
class searchable_bag : virtual public bag {
public:
    virtual bool has(int) const = 0;
};
```

#### Implementación Array Bag
```cpp
class array_bag : virtual public bag {
protected:
    int* data;
    int size;
    
public:
    // Regla de 3
    array_bag();
    array_bag(const array_bag&);
    array_bag& operator=(const array_bag&);
    ~array_bag();
    
    void insert(int item) {
        int* new_data = new int[size + 1];
        // Copiar datos existentes
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        new_data[size] = item;
        delete[] data;  // Liberar memoria anterior
        data = new_data;
        size++;
    }
};
```

#### Implementación Tree Bag
```cpp
class tree_bag : virtual public bag {
protected:
    struct node {
        node* l, *r;
        int value;
    };
    node* tree;
    
public:
    void insert(int item) {
        node* new_node = new node{item, nullptr, nullptr};
        if (tree == nullptr) {
            tree = new_node;
        } else {
            // Insertar en BST
            node* current = tree;
            while (true) {
                if (item < current->value) {
                    if (current->l == nullptr) {
                        current->l = new_node;
                        break;
                    }
                    current = current->l;
                } else if (item > current->value) {
                    if (current->r == nullptr) {
                        current->r = new_node;
                        break;
                    }
                    current = current->r;
                } else {
                    delete new_node;  // Duplicado
                    break;
                }
            }
        }
    }
};
```

### 🔍 Clases Searchable
```cpp
class searchable_array_bag : public array_bag, public searchable_bag {
public:
    bool has(int item) const override {
        for (int i = 0; i < size; i++) {
            if (data[i] == item) return true;
        }
        return false;
    }
};

class searchable_tree_bag : public tree_bag, public searchable_bag {
public:
    bool has(int item) const override {
        return has_recursive(tree, item);
    }
    
private:
    bool has_recursive(node* current, int item) const {
        if (current == nullptr) return false;
        if (item == current->value) return true;
        if (item < current->value) return has_recursive(current->l, item);
        return has_recursive(current->r, item);
    }
};
```

### 🎯 Clase Set (Wrapper)
```cpp
class set {
private:
    searchable_bag* bag;
    
public:
    set(searchable_bag* b) : bag(b) {}
    
    void insert(int item) {
        if (!bag->has(item)) {  // Solo insertar si no existe
            bag->insert(item);
        }
    }
    
    void print() const { bag->print(); }
    void clear() { bag->clear(); }
};
```

### ⚠️ Errores Comunes
1. **Diamond Problem**: Usar `virtual public` en herencia múltiple
2. **Memory leaks**: No liberar memoria en destructores
3. **Shallow copy**: Implementar correctamente constructor de copia
4. **Virtual destructors**: Destructores virtuales en clases base

---

## 📐 Ejercicio 3: VECT2

### 📋 Enunciado
Crear una clase `vect2` que represente un vector matemático 2D con operaciones vectoriales.

### 🎯 Conceptos Evaluados
- **Sobrecarga completa de operadores**
- **Operadores unarios y binarios**
- **Operadores de acceso** (`[]`)
- **Operadores de flujo** personalizados
- **Operadores friend** para conmutatividad

### 🔧 Implementación Completa

#### Estructura de la Clase
```cpp
class vect2 {
private:
    int x, y;
    
public:
    // Constructores
    vect2();                    // (0, 0)
    vect2(int x, int y);       // (x, y)
    vect2(const vect2& other); // Copia
    
    // Operadores de acceso
    int operator[](int index) const;  // Lectura
    int& operator[](int index);        // Escritura
    
    // Operadores unarios
    vect2 operator-() const;          // Negativo
    
    // Operadores aritméticos
    vect2 operator+(const vect2& other) const;
    vect2 operator-(const vect2& other) const;
    vect2 operator*(const vect2& other) const;  // Multiplicación elemento a elemento
    vect2 operator*(int scalar) const;         // Multiplicación por escalar
    
    // Operadores de asignación
    vect2& operator+=(const vect2& other);
    vect2& operator-=(const vect2& other);
    vect2& operator*=(const vect2& other);
    vect2& operator*=(int scalar);
    
    // Operadores de incremento/decremento
    vect2& operator++();      // Pre-incremento
    vect2 operator++(int);    // Post-incremento
    vect2& operator--();      // Pre-decremento
    vect2 operator--(int);    // Post-decremento
    
    // Operadores de comparación
    bool operator==(const vect2& other) const;
    bool operator!=(const vect2& other) const;
};

// Operador friend para conmutatividad
vect2 operator*(int scalar, const vect2& vec);

// Operador de flujo
std::ostream& operator<<(std::ostream& os, const vect2& obj);
```

#### Implementación Clave
```cpp
// Operador de acceso
int& vect2::operator[](int index) {
    if (index == 0) return x;
    return y;
}

// Operador de multiplicación por escalar
vect2 vect2::operator*(int scalar) const {
    return vect2(x * scalar, y * scalar);
}

// Operador friend para conmutatividad
vect2 operator*(int scalar, const vect2& vec) {
    return vec * scalar;  // Reutilizar operador miembro
}

// Operador de flujo (¡IMPORTANTE usar parámetro os!)
std::ostream& operator<<(std::ostream& os, const vect2& obj) {
    os << "{" << obj[0] << ", " << obj[1] << "}";
    return os;
}
```

### 🧪 Casos de Prueba
```cpp
vect2 v1(1, 2);
vect2 v2(3, 4);

// Operaciones básicas
vect2 v3 = v1 + v2;        // (4, 6)
vect2 v4 = v1 * 2;         // (2, 4)
vect2 v5 = 3 * v1;         // (3, 6) - Conmutativo
vect2 v6 = v1 * v2;        // (3, 8) - Elemento a elemento

// Incremento/decremento
++v1;                       // (2, 3)
v1++;                       // (3, 4)
--v1;                       // (2, 3)
v1--;                       // (1, 2)

// Comparaciones
bool equal = (v1 == v2);    // false
bool not_equal = (v1 != v2); // true
```

### ⚠️ Errores Comunes
1. **Operador `<<` incorrecto**: Usar `std::cout` en lugar del parámetro `os`
2. **Falta conmutatividad**: No implementar operador friend para `int * vect2`
3. **Operadores de asignación**: No retornar referencia a `*this`
4. **Post-incremento**: Devolver copia del valor original

---

## 🎯 Patrones de Diseño Aplicados

### 1. **Template Method** (bigint)
- Algoritmo de suma con pasos definidos
- Cada paso puede ser reutilizado

### 2. **Strategy** (polyset)
- Diferentes implementaciones de bag
- Intercambiables en tiempo de ejecución

### 3. **Adapter** (vect2)
- Adaptar vectores matemáticos a operadores C++
- Hacer que se comporten como tipos nativos

### 4. **Factory Method** (polyset)
- Crear diferentes tipos de bags
- Encapsular la lógica de creación

---

## 🚀 Consejos para el Examen

### ✅ Buenas Prácticas
1. **Siempre implementar la regla de 3/5** cuando se maneja memoria dinámica
2. **Usar `const` correctamente** en métodos que no modifican el objeto
3. **Implementar operadores de comparación** de forma consistente
4. **Usar `virtual` en destructores** de clases base
5. **Validar parámetros** en constructores y operadores

### ❌ Errores a Evitar
1. **Memory leaks** - Siempre liberar memoria en destructores
2. **Shallow copy** - Implementar deep copy cuando sea necesario
3. **Operadores inconsistentes** - Mantener semántica matemática
4. **Falta de const** - Marcar métodos que no modifican el objeto
5. **Herencia múltiple sin virtual** - Usar `virtual public` para evitar diamond problem

### 🔍 Debugging Tips
1. **Usar `valgrind`** para detectar memory leaks
2. **Compilar con `-Wall -Wextra -Werror`** para detectar warnings
3. **Probar casos edge** (números muy grandes, vectores nulos, etc.)
4. **Verificar salida esperada** con el main proporcionado

---

## 📚 Recursos Adicionales

### Libros Recomendados
- **"Effective C++"** - Scott Meyers
- **"More Effective C++"** - Scott Meyers
- **"C++ Primer"** - Stanley Lippman

### Enlaces Útiles
- [cppreference.com](https://en.cppreference.com/) - Referencia completa de C++
- [Stack Overflow C++](https://stackoverflow.com/questions/tagged/c%2b%2b) - Comunidad y ejemplos
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/) - Mejores prácticas

---

*¡Éxito en tu examen! 🎉*

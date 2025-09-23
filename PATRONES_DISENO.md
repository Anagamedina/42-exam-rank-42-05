# 🎨 Patrones de Diseño en C++

## 📚 Índice de Patrones

### 🏗️ Patrones Creacionales
1. **[Singleton](patrones/singleton.md)** - Garantizar una única instancia
2. **[Factory Method](patrones/factory-method.md)** - Crear objetos sin especificar clases
3. **[Builder](patrones/builder.md)** - Construir objetos complejos paso a paso

### 🔧 Patrones Estructurales
4. **[Adapter](patrones/adapter.md)** - Hacer compatibles interfaces incompatibles
5. **[Decorator](patrones/decorator.md)** - Añadir funcionalidad dinámicamente
6. **[Observer](patrones/observer.md)** - Notificar cambios a múltiples objetos

### 🎯 Patrones Comportamentales
7. **[Strategy](patrones/strategy.md)** - Intercambiar algoritmos en tiempo de ejecución
8. **[Command](patrones/command.md)** - Encapsular solicitudes como objetos
9. **[Template Method](patrones/template-method.md)** - Definir estructura de algoritmo
10. **[State](patrones/state.md)** - Cambiar comportamiento según estado

---

## 🎯 ¿Qué es un Patrón de Diseño?

Un **patrón de diseño** es una solución reutilizable a un problema común en el diseño de software. No es código específico, sino una plantilla conceptual que describe cómo resolver un problema que puede presentarse en muchas situaciones diferentes.

### 🔍 Características de los Patrones

#### ✅ **Ventajas:**
- **Reutilización**: Soluciones probadas y testadas
- **Comunicación**: Lenguaje común entre desarrolladores
- **Flexibilidad**: Fácil modificación y extensión
- **Mantenibilidad**: Código más organizado y comprensible

#### ⚠️ **Desventajas:**
- **Complejidad**: Pueden añadir overhead innecesario
- **Sobre-ingeniería**: No siempre son necesarios
- **Curva de aprendizaje**: Requieren tiempo para dominarlos

---

## 🏗️ Clasificación de Patrones

### 1. **Patrones Creacionales** 🏭
**Propósito:** Proporcionar mecanismos de creación de objetos que aumenten la flexibilidad y reutilización del código.

**Principios:**
- Encapsular la lógica de creación
- Desacoplar el código cliente de las clases concretas
- Proporcionar flexibilidad en la creación de objetos

**Ejemplos:** Singleton, Factory Method, Builder, Abstract Factory, Prototype

### 2. **Patrones Estructurales** 🔧
**Propósito:** Componer clases y objetos para formar estructuras más grandes y flexibles.

**Principios:**
- Composición sobre herencia
- Interfaces estables
- Flexibilidad en la estructura

**Ejemplos:** Adapter, Decorator, Facade, Proxy, Composite, Bridge, Flyweight

### 3. **Patrones Comportamentales** 🎯
**Propósito:** Gestionar algoritmos, responsabilidades y comunicación entre objetos.

**Principios:**
- Encapsular comportamiento variable
- Comunicación flexible entre objetos
- Separación de responsabilidades

**Ejemplos:** Observer, Strategy, Command, Template Method, State, Chain of Responsibility, Iterator, Mediator, Memento, Visitor

---

## 🎯 Patrones Más Importantes para 42

### 🥇 **Top 5 Patrones Esenciales**

#### 1. **Singleton** 🏆
- **Cuándo usar:** Cuando necesitas exactamente una instancia
- **Ejemplo:** Logger, Configuración, Conexión a BD
- **Relevancia en 42:** Muy común en proyectos de sistemas

#### 2. **Observer** 👁️
- **Cuándo usar:** Notificar cambios a múltiples objetos
- **Ejemplo:** MVC, Eventos de UI, Sistema de notificaciones
- **Relevancia en 42:** Fundamental en arquitecturas de software

#### 3. **Factory Method** 🏭
- **Cuándo usar:** Crear objetos sin conocer su clase exacta
- **Ejemplo:** Crear diferentes tipos de archivos, formas geométricas
- **Relevancia en 42:** Muy útil en proyectos de programación

#### 4. **Strategy** 🎯
- **Cuándo usar:** Intercambiar algoritmos en tiempo de ejecución
- **Ejemplo:** Diferentes algoritmos de ordenamiento, validaciones
- **Relevancia en 42:** Fundamental en algoritmos y estructuras de datos

#### 5. **Adapter** 🔌
- **Cuándo usar:** Hacer compatibles interfaces incompatibles
- **Ejemplo:** Integrar librerías externas, APIs diferentes
- **Relevancia en 42:** Muy útil en proyectos de integración

---

## 🧠 Principios SOLID y Patrones

### **S** - Single Responsibility Principle
- **Patrones relacionados:** Strategy, Command
- **Aplicación:** Cada clase tiene una sola responsabilidad

### **O** - Open/Closed Principle
- **Patrones relacionados:** Decorator, Observer, Strategy
- **Aplicación:** Abierto para extensión, cerrado para modificación

### **L** - Liskov Substitution Principle
- **Patrones relacionados:** Template Method, Strategy
- **Aplicación:** Los objetos derivados deben ser sustituibles por sus bases

### **I** - Interface Segregation Principle
- **Patrones relacionados:** Adapter, Facade
- **Aplicación:** Interfaces específicas son mejores que generales

### **D** - Dependency Inversion Principle
- **Patrones relacionados:** Factory Method, Abstract Factory, Dependency Injection
- **Aplicación:** Depender de abstracciones, no de concreciones

---

## 🎯 Cómo Elegir el Patrón Correcto

### 🤔 **Preguntas Clave:**

1. **¿Qué problema estoy resolviendo?**
   - Creación de objetos → Patrones Creacionales
   - Estructura de clases → Patrones Estructurales
   - Comportamiento → Patrones Comportamentales

2. **¿Cuál es el contexto?**
   - Sistema simple → Patrones básicos (Singleton, Factory)
   - Sistema complejo → Patrones avanzados (Observer, Strategy)

3. **¿Qué flexibilidad necesito?**
   - Alta flexibilidad → Strategy, Observer, Decorator
   - Baja flexibilidad → Singleton, Template Method

### 📊 **Matriz de Decisión**

| Problema | Patrón Recomendado | Alternativas |
|----------|-------------------|--------------|
| Una sola instancia | Singleton | - |
| Crear objetos | Factory Method | Abstract Factory, Builder |
| Notificar cambios | Observer | Mediator |
| Intercambiar algoritmos | Strategy | Template Method |
| Añadir funcionalidad | Decorator | Adapter |
| Hacer compatible | Adapter | Facade |

---

## 🚀 Implementación en C++

### 🔧 **Características Específicas de C++**

#### **Templates y Patrones**
```cpp
// Template Method con templates
template<typename T>
class Algorithm {
public:
    void execute() {
        step1();
        step2();
        step3();
    }
protected:
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
};
```

#### **RAII y Patrones**
```cpp
// Singleton con RAII
class Singleton {
private:
    static std::unique_ptr<Singleton> instance;
    Singleton() = default;
public:
    static Singleton& getInstance() {
        if (!instance) {
            instance = std::make_unique<Singleton>();
        }
        return *instance;
    }
};
```

#### **Smart Pointers y Patrones**
```cpp
// Observer con smart pointers
class Subject {
private:
    std::vector<std::weak_ptr<Observer>> observers;
public:
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }
};
```

---

## 📚 Recursos Adicionales

### 📖 **Libros Recomendados**
- **"Design Patterns"** - Gang of Four (GoF)
- **"Head First Design Patterns"** - Freeman & Robson
- **"Patterns of Enterprise Application Architecture"** - Martin Fowler

### 🌐 **Enlaces Útiles**
- [Refactoring Guru](https://refactoring.guru/es/design-patterns) - Explicaciones detalladas
- [Source Making](https://sourcemaking.com/design_patterns) - Ejemplos prácticos
- [C++ Reference](https://en.cppreference.com/) - Documentación C++

### 🎯 **Para 42 Específicamente**
- **Cub3D**: Observer, Strategy, Factory Method
- **Philosophers**: Singleton, Observer, State
- **Minishell**: Command, Strategy, Factory Method
- **Webserv**: Observer, Strategy, Adapter

---

## 🎯 Próximos Pasos

1. **Estudia los patrones individuales** en sus archivos específicos
2. **Practica implementaciones** en C++
3. **Identifica patrones** en código existente
4. **Aplica patrones** en tus proyectos de 42

---

*¡Los patrones de diseño son herramientas poderosas que te ayudarán a escribir código más limpio, flexible y mantenible! 🚀*

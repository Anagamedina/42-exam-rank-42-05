# 🎯 Level-2: Algoritmos Avanzados

## 📋 **Descripción del Level**

El **Level-2** contiene **2 ejercicios** que requieren implementación de algoritmos complejos y estructuras de datos avanzadas.

### 🎯 **Ejercicios:**
1. **BSQ** - Biggest Square (Programación Dinámica)
2. **Game of Life** - Simulación de Autómatas Celulares

---

## 🏗️ **Estructura del Level**

```
level-2/
├── APUNTES_LEVEL2.md          # Resumen general del level
├── APUNTES_BSQ.md            # Apuntes detallados de BSQ
├── APUNTES_GAME_OF_LIFE.md   # Apuntes detallados de Game of Life
├── EJEMPLOS_USO.md           # Ejemplos de uso y casos de prueba
├── bsq/                      # Ejercicio BSQ
│   ├── bsq.c                 # Implementación completa
│   ├── bsq.h                 # Header con prototipos
│   ├── main.c                # Función main
│   ├── Makefile              # Para compilar
│   └── bsq_test_maps/        # Mapas de prueba
└── game_of_life/             # Ejercicio Game of Life
    ├── life.c                # Implementación completa
    ├── life.h                # Header con prototipos
    ├── main.c                # Función main
    └── Makefile              # Para compilar
```

---

## 🎯 **BSQ - Biggest Square**

### **Concepto Clave:**
Encontrar el **cuadrado más grande** posible en un mapa evitando obstáculos.

### **Algoritmo Principal:**
- **Programación Dinámica** con matriz DP
- **Fórmula:** `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`
- **Complejidad:** O(rows × cols)

### **Puntos Clave:**
- Validar formato del mapa
- Manejar múltiples archivos
- Elegir solución más arriba y a la izquierda
- Usar `stderr` para errores

### **Enlaces:**
- [📚 Apuntes Detallados](APUNTES_BSQ.md)
- [📁 Implementación](bsq/)
- [🧪 Ejemplos de Uso](EJEMPLOS_USO.md#bsq---biggest-square)

---

## 🎮 **Game of Life**

### **Concepto Clave:**
Simular evolución de células según reglas específicas.

### **Algoritmo Principal:**
- **Reglas de Conway:** 2-3 vecinos para sobrevivir, 3 para nacer
- **Simulación por iteraciones**
- **Comandos de dibujo:** `w`, `a`, `s`, `d`, `x`

### **Puntos Clave:**
- Procesar comandos de entrada
- Contar vecinos correctamente
- Aplicar reglas de evolución
- Manejar células fuera del tablero

### **Enlaces:**
- [📚 Apuntes Detallados](APUNTES_GAME_OF_LIFE.md)
- [📁 Implementación](game_of_life/)
- [🧪 Ejemplos de Uso](EJEMPLOS_USO.md#game-of-life)

---

## 🔧 **Habilidades Requeridas**

### **Gestión de Memoria:**
- `malloc`, `calloc`, `realloc`, `free`
- Liberar memoria correctamente
- Evitar memory leaks

### **Procesamiento de Archivos:**
- `fopen`, `fclose`, `getline`
- Validación de entrada
- Manejo de errores

### **Algoritmos:**
- **Programación Dinámica** (BSQ)
- **Simulación** (Game of Life)
- **Validación de datos**

---

## 📊 **Comparación de Ejercicios**

| Aspecto | BSQ | Game of Life |
|---------|-----|--------------|
| **Complejidad** | Media-Alta | Media |
| **Algoritmo** | Programación Dinámica | Simulación |
| **Entrada** | Archivo de mapa | Comandos + argumentos |
| **Salida** | Mapa modificado | Tablero de células |
| **Validación** | Formato del mapa | Comandos válidos |

---

## 🎯 **Estrategias de Implementación**

### **BSQ:**
1. **Validar mapa** - Formato, caracteres, dimensiones
2. **Crear matriz DP** - Inicializar con 0s
3. **Llenar DP** - Aplicar fórmula recursiva
4. **Encontrar máximo** - Buscar el cuadrado más grande
5. **Dibujar resultado** - Reemplazar caracteres

### **Game of Life:**
1. **Inicializar tablero** - Matriz de células
2. **Procesar comandos** - Mover lápiz y dibujar
3. **Simular evolución** - Aplicar reglas por iteraciones
4. **Contar vecinos** - Incluir células fuera del tablero
5. **Imprimir resultado** - Mostrar estado final

---

## ⚠️ **Errores Comunes**

### **BSQ:**
- No validar formato del mapa
- No manejar múltiples archivos
- Memory leaks en matriz DP
- No elegir solución correcta (arriba-izquierda)

### **Game of Life:**
- No contar vecinos fuera del tablero
- Aplicar reglas incorrectamente
- No manejar comandos inválidos
- Memory leaks en tableros

---

## 🚀 **Optimizaciones**

### **BSQ:**
- Usar solo 2 filas de DP
- Early termination
- Optimizar búsqueda del máximo

### **Game of Life:**
- Detectar estabilidad
- Usar tableros alternados
- Optimizar conteo de vecinos

---

## 🎯 **Consejos para el Examen**

### **Preparación:**
1. **Entender algoritmos** - No solo implementar
2. **Practicar casos edge** - Mapas inválidos, comandos extraños
3. **Manejar memoria** - Liberar todo lo que allocas
4. **Validar entrada** - Siempre verificar formato

### **Durante el Examen:**
1. **Leer cuidadosamente** - Entender el problema completo
2. **Planificar** - Diseñar la estructura antes de codificar
3. **Probar casos** - Verificar con ejemplos dados
4. **Optimizar** - Solo después de que funcione

---

## 📚 **Recursos Adicionales**

### **BSQ:**
- [Programación Dinámica](https://es.wikipedia.org/wiki/Programaci%C3%B3n_din%C3%A1mica)
- [Algoritmo de Cuadrado Máximo](https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/)

### **Game of Life:**
- [Conway's Game of Life](https://es.wikipedia.org/wiki/Juego_de_la_vida)
- [Reglas del Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

---

## 🎯 **Resumen de Habilidades**

| Habilidad | BSQ | Game of Life |
|-----------|-----|--------------|
| **Programación Dinámica** | ✅ | ❌ |
| **Simulación** | ❌ | ✅ |
| **Validación de Datos** | ✅ | ✅ |
| **Gestión de Memoria** | ✅ | ✅ |
| **Procesamiento de Archivos** | ✅ | ❌ |
| **Algoritmos de Búsqueda** | ✅ | ❌ |

---

## 🏆 **Objetivos de Aprendizaje**

Al completar el Level-2, deberías ser capaz de:

1. **Implementar algoritmos de programación dinámica**
2. **Simular sistemas complejos**
3. **Manejar memoria dinámica eficientemente**
4. **Validar y procesar datos de entrada**
5. **Optimizar algoritmos para casos edge**
6. **Diseñar estructuras de datos apropiadas**

---

## 📈 **Progresión de Dificultad**

```
Level-1: Fundamentos OOP
    ↓
Level-2: Algoritmos Avanzados ← Estás aquí
    ↓
Level-3: Sistemas Complejos
    ↓
Level-4: Arquitectura de Software
```

---

## 🔗 **Enlaces Relacionados**

- [📚 Apuntes Level-1](../level-1/APUNTES_LEVEL1.md)
- [📁 Ejercicio BSQ](bsq/)
- [📁 Ejercicio Game of Life](game_of_life/)
- [🏠 README Principal](../../README.md)

---

## 🎯 **Próximos Pasos**

1. **Estudiar apuntes** - Entender cada algoritmo
2. **Implementar BSQ** - Practicar programación dinámica
3. **Implementar Game of Life** - Practicar simulación
4. **Probar casos edge** - Validar implementaciones
5. **Optimizar código** - Mejorar rendimiento

¡Con estos apuntes tienes todo lo necesario para dominar el Level-2! 🚀


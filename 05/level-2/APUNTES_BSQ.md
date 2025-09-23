# 🎯 BSQ - Biggest Square

## 📋 **Descripción del Problema**

**BSQ** (Biggest Square) es un algoritmo que encuentra el **cuadrado más grande** posible en un mapa, evitando obstáculos.

### 🎯 **Objetivo:**
- Encontrar el cuadrado más grande que se puede dibujar en un mapa
- Reemplazar caracteres vacíos por caracteres llenos para formar el cuadrado
- Si hay múltiples soluciones, elegir la más arriba y a la izquierda

---

## 📊 **Formato del Archivo de Entrada**

```
9 . o x
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
```

### **Primera línea:** `[líneas] [vacío] [obstáculo] [lleno]`
- **9**: Número de líneas del mapa
- **.**: Carácter vacío (se puede reemplazar)
- **o**: Carácter obstáculo (no se puede usar)
- **x**: Carácter lleno (resultado final)

---

## 🔍 **Algoritmo: Programación Dinámica**

### **Idea Principal:**
Para cada celda `(i,j)`, calcular el **tamaño del cuadrado más grande** que tiene su esquina inferior derecha en esa posición.

### **Fórmula Recursiva:**
```
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
```

**Solo si** `mapa[i][j]` no es obstáculo.

---

## 📈 **Diagrama del Algoritmo**

```
Mapa inicial:          Matriz DP:
. . . o .            0 1 2 0 1
. . o . .    →       1 2 0 1 2  
. . . . .            2 3 1 2 3
o . . . .            0 1 2 3 4
. . . . .            1 2 3 4 5

Resultado: Cuadrado 3x3 en posición (2,4)
```

---

## 🛠️ **Implementación Paso a Paso**

### **Paso 1: Validar el Mapa**
```c
// Verificar que todas las líneas tengan la misma longitud
// Verificar que solo se usen los caracteres permitidos
// Verificar que no haya caracteres duplicados
```

### **Paso 2: Crear Matriz DP**
```c
int **dp = malloc(rows * sizeof(int*));
for (int i = 0; i < rows; i++) {
    dp[i] = calloc(cols, sizeof(int));
}
```

### **Paso 3: Llenar la Matriz DP**
```c
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        if (map[i][j] == obstacle) {
            dp[i][j] = 0;
        } else {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            }
        }
    }
}
```

### **Paso 4: Encontrar el Máximo**
```c
int max_size = 0;
int max_i = 0, max_j = 0;

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        if (dp[i][j] > max_size) {
            max_size = dp[i][j];
            max_i = i;
            max_j = j;
        }
    }
}
```

### **Paso 5: Dibujar el Cuadrado**
```c
// Reemplazar caracteres vacíos por llenos en el cuadrado
for (int i = max_i - max_size + 1; i <= max_i; i++) {
    for (int j = max_j - max_size + 1; j <= max_j; j++) {
        map[i][j] = full_char;
    }
}
```

---

## 🎯 **Ejemplo Completo**

### **Entrada:**
```
5 . o x
.....
.....
..o..
.....
.....
```

### **Proceso:**
1. **Matriz DP inicial:**
   ```
   1 1 1 1 1
   1 2 2 2 2
   1 2 0 1 2
   1 2 2 2 3
   1 2 3 3 4
   ```

2. **Máximo encontrado:** `4` en posición `(4,4)`

3. **Resultado:**
   ```
   .....
   .....
   ..o..
   .xxxx
   .xxxx
   ```

---

## ⚠️ **Casos Edge y Validaciones**

### **Mapa Inválido:**
- Líneas de diferente longitud
- Caracteres no permitidos
- Caracteres duplicados en la primera línea
- Menos de una línea

### **Casos Especiales:**
- **Sin solución:** Todo el mapa son obstáculos
- **Múltiples soluciones:** Elegir la más arriba y a la izquierda
- **Múltiples archivos:** Procesar cada uno por separado

---

## 🚀 **Optimizaciones**

### **Optimización de Memoria:**
- Usar solo 2 filas de la matriz DP
- Calcular el máximo mientras se llena la matriz

### **Optimización de Tiempo:**
- Parar cuando se encuentra un cuadrado del tamaño máximo posible
- Usar early termination

---

## 📝 **Estructura del Código**

```c
// Funciones principales
void ft_bsq(char **argv);
void ft_bsq_from_stdin(FILE *stream);
void process_map(char **map, int rows, int cols);
int find_biggest_square(char **map, int rows, int cols);
void draw_square(char **map, int row, int col, int size);
bool is_valid_map(char **map, int rows, int cols);
```

---

## 🎯 **Consejos para el Examen**

1. **Validar primero** - No procesar mapas inválidos
2. **Manejar memoria** - Liberar todo lo que allocas
3. **Casos edge** - Mapa vacío, sin solución, etc.
4. **Múltiples archivos** - Procesar cada uno independientemente
5. **Salida correcta** - Usar `stderr` para errores, `stdout` para resultados

---

## 🔧 **Funciones Permitidas**

- `malloc`, `calloc`, `realloc`, `free`
- `fopen`, `fclose`, `getline`
- `fscanf`, `fputs`, `fprintf`
- `stderr`, `stdout`, `stdin`
- `errno`

---

## 📊 **Complejidad**

- **Tiempo:** O(rows × cols)
- **Espacio:** O(rows × cols) para la matriz DP
- **Optimización:** O(min(rows, cols)) con optimización de espacio

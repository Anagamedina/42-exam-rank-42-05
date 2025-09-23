# 🎮 Game of Life - Conway's Game of Life

## 📋 **Descripción del Problema**

**Game of Life** es una simulación de autómatas celulares donde las células pueden estar **vivas** (1) o **muertas** (0) y evolucionan según reglas específicas.

### 🎯 **Objetivo:**
- Simular el comportamiento de células en un tablero
- Aplicar reglas de evolución por un número determinado de iteraciones
- Mostrar el estado final del tablero

---

## 🎮 **Comandos de Entrada**

### **Comandos de Movimiento:**
- **`w`**: Mover lápiz hacia arriba (up)
- **`a`**: Mover lápiz hacia la izquierda (left)  
- **`s`**: Mover lápiz hacia abajo (down)
- **`d`**: Mover lápiz hacia la derecha (right)
- **`x`**: Levantar/bajar el lápiz (toggle drawing)

### **Comportamiento del Lápiz:**
- **Lápiz abajo**: Dibuja células vivas (1) al moverse
- **Lápiz arriba**: Solo se mueve sin dibujar
- **Fuera del tablero**: No se mueve, se queda en el borde

---

## 🔄 **Reglas del Game of Life**

### **Para una célula viva:**
- **2-3 vecinos vivos** → Sobrevive (sigue viva)
- **< 2 vecinos vivos** → Muere por soledad
- **> 3 vecinos vivos** → Muere por sobrepoblación

### **Para una célula muerta:**
- **Exactamente 3 vecinos vivos** → Nace (se vuelve viva)
- **Cualquier otro caso** → Sigue muerta

---

## 📊 **Diagrama de las Reglas**

```
Vecinos: 0 1 2 3 4 5 6 7 8
Célula viva:  M M S S M M M M M
Célula muerta: M M M N M M M M M

M = Muere/Permanece muerta
S = Sobrevive  
N = Nace
```

---

## 🛠️ **Implementación Paso a Paso**

### **Paso 1: Inicializar el Tablero**
```c
char **board = malloc(height * sizeof(char*));
for (int i = 0; i < height; i++) {
    board[i] = calloc(width, sizeof(char));
}
```

### **Paso 2: Procesar Comandos**
```c
int pen_x = 0, pen_y = 0;  // Posición del lápiz
bool pen_down = false;     // Estado del lápiz

char command;
while (read(0, &command, 1) > 0) {
    switch (command) {
        case 'w': if (pen_y > 0) pen_y--; break;
        case 'a': if (pen_x > 0) pen_x--; break;
        case 's': if (pen_y < height-1) pen_y++; break;
        case 'd': if (pen_x < width-1) pen_x++; break;
        case 'x': pen_down = !pen_down; break;
    }
    
    if (pen_down) {
        board[pen_y][pen_x] = 1;  // Dibujar célula viva
    }
}
```

### **Paso 3: Simular Game of Life**
```c
for (int iter = 0; iter < iterations; iter++) {
    char **new_board = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        new_board[i] = calloc(width, sizeof(char));
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int neighbors = count_neighbors(board, i, j, height, width);
            new_board[i][j] = apply_rules(board[i][j], neighbors);
        }
    }
    
    // Liberar tablero anterior y usar el nuevo
    free_board(board, height);
    board = new_board;
}
```

### **Paso 4: Contar Vecinos**
```c
int count_neighbors(char **board, int row, int col, int height, int width) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // No contar la célula misma
            
            int new_row = row + i;
            int new_col = col + j;
            
            // Verificar límites del tablero
            if (new_row >= 0 && new_row < height && 
                new_col >= 0 && new_col < width) {
                count += board[new_row][new_col];
            }
        }
    }
    return count;
}
```

### **Paso 5: Aplicar Reglas**
```c
char apply_rules(char current, int neighbors) {
    if (current == 1) {  // Célula viva
        return (neighbors == 2 || neighbors == 3) ? 1 : 0;
    } else {  // Célula muerta
        return (neighbors == 3) ? 1 : 0;
    }
}
```

### **Paso 6: Imprimir Resultado**
```c
for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        if (board[i][j] == 1) {
            putchar('0');  // Célula viva
        } else {
            putchar(' ');  // Célula muerta
        }
    }
    putchar('\n');
}
```

---

## 🎯 **Ejemplo Completo**

### **Entrada:** `echo 'sdxddssaaww' | ./a.out 5 5 0`

### **Proceso:**
1. **Comandos:** `s` (abajo), `d` (derecha), `x` (bajar lápiz), `d` (derecha), `d` (derecha), `s` (abajo), `s` (abajo), `a` (izquierda), `a` (izquierda), `w` (arriba), `w` (arriba)

2. **Tablero inicial:**
   ```
       0
     0 0
     000
   ```

3. **Resultado (0 iteraciones):**
   ```
       
    000 
     0 0 
     000 
       
   ```

---

## 🔄 **Ejemplo con Iteraciones**

### **Entrada:** `echo 'dxss' | ./a.out 3 3 1`

### **Iteración 0:**
```
 0 
 0 
 0 
```

### **Iteración 1:**
```
   
000
   
```

**Explicación:** Las 3 células verticales mueren por soledad (cada una tiene solo 1 vecino).

---

## ⚠️ **Casos Edge y Validaciones**

### **Comandos Inválidos:**
- Ignorar caracteres que no sean `w`, `a`, `s`, `d`, `x`
- El lápiz no se mueve fuera del tablero

### **Casos Especiales:**
- **Tablero vacío:** Solo espacios
- **Sin iteraciones:** Mostrar estado inicial
- **Células fuera del tablero:** Consideradas muertas

---

## 🚀 **Optimizaciones**

### **Optimización de Memoria:**
- Usar solo 2 tableros (actual y siguiente)
- Liberar memoria correctamente

### **Optimización de Tiempo:**
- Parar si no hay cambios entre iteraciones
- Usar early termination

---

## 📝 **Estructura del Código**

```c
// Funciones principales
int main(int argc, char **argv);
void process_commands(char **board, int width, int height);
void simulate_life(char **board, int width, int height, int iterations);
int count_neighbors(char **board, int row, int col, int height, int width);
char apply_rules(char current, int neighbors);
void print_board(char **board, int width, int height);
void free_board(char **board, int height);
```

---

## 🎯 **Consejos para el Examen**

1. **Manejar entrada** - Leer comandos hasta EOF
2. **Validar movimientos** - No salir del tablero
3. **Manejar memoria** - Liberar todo lo que allocas
4. **Contar vecinos** - Incluir células fuera del tablero como muertas
5. **Aplicar reglas** - Exactamente como se especifica

---

## 🔧 **Funciones Permitidas**

- `atoi` - Convertir argumentos a enteros
- `read` - Leer entrada
- `putchar` - Imprimir caracteres
- `malloc`, `calloc`, `realloc`, `free` - Gestión de memoria

---

## 📊 **Complejidad**

- **Tiempo:** O(iterations × width × height)
- **Espacio:** O(width × height) para el tablero
- **Por iteración:** O(width × height) para contar vecinos

---

## 🎮 **Patrones Conocidos del Game of Life**

### **Osciladores:**
- **Blinker:** `000` → `0 0` → `000`
- **Toad:** Patrón que oscila cada 2 generaciones

### **Naves Espaciales:**
- **Glider:** Se mueve diagonalmente
- **LWSS:** Nave espacial ligera

### **Estables:**
- **Block:** Cuadrado 2x2 que no cambia
- **Beehive:** Patrón hexagonal estable

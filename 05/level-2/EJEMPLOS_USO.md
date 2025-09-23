# 🧪 Ejemplos de Uso - Level-2

## 🎯 **BSQ - Biggest Square**

### **Compilación:**
```bash
cd 05/level-2/bsq
make
```

### **Ejemplo 1: Mapa simple**
```bash
# Crear archivo de prueba
echo "5 . o x
.....
.....
..o..
.....
....." > test_map.txt

# Ejecutar BSQ
./bsq test_map.txt
```

**Salida esperada:**
```
.....
.....
..o..
.xxxx
.xxxx
```

### **Ejemplo 2: Múltiples archivos**
```bash
# Crear segundo archivo
echo "3 . o x
...
.o.
..." > test_map2.txt

# Ejecutar con múltiples archivos
./bsq test_map.txt test_map2.txt
```

### **Ejemplo 3: Desde stdin**
```bash
# Usar el mapa existente
cat map.txt | ./bsq
```

### **Ejemplo 4: Mapa inválido**
```bash
# Crear mapa inválido
echo "3 . o x
...
.o
..." > invalid_map.txt

# Ejecutar (debe mostrar error)
./bsq invalid_map.txt
```

**Salida esperada:**
```
map error
```

---

## 🎮 **Game of Life**

### **Compilación:**
```bash
cd 05/level-2/game_of_life
make
```

### **Ejemplo 1: Patrón simple (0 iteraciones)**
```bash
echo 'sdxddssaaww' | ./life 5 5 0
```

**Salida esperada:**
```
     
  000 
   0 0 
   000 
     
```

### **Ejemplo 2: Con iteraciones**
```bash
echo 'dxss' | ./life 3 3 1
```

**Salida esperada:**
```
   
000
   
```

### **Ejemplo 3: Patrón complejo**
```bash
echo 'sdxddssaaww' | ./life 10 6 0
```

**Salida esperada:**
```
          
   0   000  
   0     0  
   000  0   
    0  000  
          
```

### **Ejemplo 4: Múltiples iteraciones**
```bash
echo 'dxss' | ./life 3 3 2
```

**Salida esperada:**
```
 0 
 0 
 0 
```

---

## 🔧 **Comandos de Dibujo (Game of Life)**

### **Comandos disponibles:**
- **`w`**: Mover lápiz hacia arriba
- **`a`**: Mover lápiz hacia la izquierda
- **`s`**: Mover lápiz hacia abajo
- **`d`**: Mover lápiz hacia la derecha
- **`x`**: Levantar/bajar el lápiz (toggle)

### **Ejemplo de secuencia:**
```bash
# Crear patrón en forma de L
echo 'dxddssaaww' | ./life 5 5 0
```

**Explicación:**
1. `d` - Mover derecha
2. `x` - Bajar lápiz (empezar a dibujar)
3. `d` - Mover derecha (dibujar)
4. `d` - Mover derecha (dibujar)
5. `s` - Mover abajo (dibujar)
6. `s` - Mover abajo (dibujar)
7. `a` - Mover izquierda (dibujar)
8. `a` - Mover izquierda (dibujar)
9. `w` - Mover arriba (dibujar)
10. `w` - Mover arriba (dibujar)

---

## 🧪 **Casos de Prueba**

### **BSQ - Casos Edge:**
```bash
# Mapa vacío
echo "0 . o x" | ./bsq

# Mapa con solo obstáculos
echo "3 . o x
ooo
ooo
ooo" | ./bsq

# Mapa con caracteres inválidos
echo "3 . o x
...
.o.
..." | ./bsq
```

### **Game of Life - Casos Edge:**
```bash
# Sin comandos (tablero vacío)
echo '' | ./life 5 5 0

# Comandos inválidos
echo 'qwerty' | ./life 3 3 0

# Múltiples iteraciones
echo 'dxss' | ./life 3 3 10
```

---

## 🚀 **Scripts de Prueba**

### **Script para BSQ:**
```bash
#!/bin/bash
echo "Probando BSQ..."

# Crear mapas de prueba
echo "5 . o x
.....
.....
..o..
.....
....." > test1.txt

echo "3 . o x
...
.o.
..." > test2.txt

# Probar mapas individuales
echo "Mapa 1:"
./bsq test1.txt
echo ""

echo "Mapa 2:"
./bsq test2.txt
echo ""

# Probar múltiples mapas
echo "Múltiples mapas:"
./bsq test1.txt test2.txt

# Limpiar
rm test1.txt test2.txt
```

### **Script para Game of Life:**
```bash
#!/bin/bash
echo "Probando Game of Life..."

# Patrón simple
echo "Patrón simple (0 iteraciones):"
echo 'sdxddssaaww' | ./life 5 5 0
echo ""

# Con iteraciones
echo "Con 1 iteración:"
echo 'dxss' | ./life 3 3 1
echo ""

# Patrón complejo
echo "Patrón complejo:"
echo 'sdxddssaaww' | ./life 10 6 0
```

---

## 📊 **Análisis de Rendimiento**

### **BSQ:**
- **Complejidad:** O(rows × cols)
- **Memoria:** O(rows × cols) para matriz DP
- **Optimización:** Usar solo 2 filas de DP

### **Game of Life:**
- **Complejidad:** O(iterations × width × height)
- **Memoria:** O(width × height) para tablero
- **Optimización:** Detectar estabilidad

---

## 🎯 **Consejos para el Examen**

1. **Probar casos edge** - Mapas inválidos, comandos extraños
2. **Validar entrada** - Siempre verificar formato
3. **Manejar memoria** - Liberar todo lo que allocas
4. **Optimizar** - Solo después de que funcione
5. **Documentar** - Comentarios claros en código complejo

---

## 🔧 **Debugging**

### **BSQ:**
```bash
# Usar valgrind para detectar memory leaks
valgrind --leak-check=full ./bsq test_map.txt

# Usar gdb para debugging
gdb ./bsq
(gdb) run test_map.txt
```

### **Game of Life:**
```bash
# Debug con printf
# Agregar printf en funciones críticas para ver el flujo

# Usar valgrind
valgrind --leak-check=full ./life 5 5 0
```

---

## 📝 **Notas Importantes**

1. **BSQ** requiere validación estricta del formato del mapa
2. **Game of Life** debe manejar comandos inválidos correctamente
3. **Ambos** requieren manejo cuidadoso de memoria
4. **Casos edge** son cruciales para pasar el examen
5. **Optimización** es importante pero no prioritaria

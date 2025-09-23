# 🔧 Correcciones de Funciones Permitidas

## 📋 **Resumen de Correcciones**

He revisado todos los niveles y corregido las funciones que no estaban permitidas según los subjects del examen.

---

## ✅ **Level-1: Sin Restricciones**

### **BIGINT, POLYSET, VECT2:**
- **Estado:** ✅ **Correcto**
- **Funciones usadas:** Todas las funciones estándar de C++ están permitidas
- **No se requieren correcciones**

---

## ⚠️ **Level-2: Funciones Restringidas**

### **BSQ - Funciones Permitidas:**
```
malloc, calloc, realloc, free, fopen, fclose, getline, fscanf, fputs, fprintf, stderr, stdout, stdin, errno
```

### **❌ Problemas Encontrados y Corregidos:**

#### **1. `strlen()` - NO PERMITIDA**
```c
// ❌ ANTES (incorrecto)
if (strlen(map[i]) != cols)

// ✅ DESPUÉS (corregido)
int len = 0;
while (map[i][len] != '\0') {
    len++;
}
if (len != cols)
```

#### **2. `strtok()` - NO PERMITIDA**
```c
// ❌ ANTES (incorrecto)
char *token = strtok(line, " \n");
token = strtok(NULL, " \n");

// ✅ DESPUÉS (corregido)
int pos = 0;
while (line[pos] != ' ' && line[pos] != '\n' && line[pos] != '\0') pos++;
pos++; // Saltar el espacio
```

#### **3. `strcpy()` - NO PERMITIDA**
```c
// ❌ ANTES (incorrecto)
strcpy(map[i], line);

// ✅ DESPUÉS (corregido)
int j = 0;
while (line[j] != '\0') {
    map[i][j] = line[j];
    j++;
}
map[i][j] = '\0';
```

### **Game of Life - Funciones Permitidas:**
```
atoi, read, putchar, malloc, calloc, realloc, free
```

### **✅ Estado:** **Correcto**
- **Solo usa funciones permitidas**
- **No se requieren correcciones**

---

## 🎯 **Funciones Prohibidas en Level-2**

### **BSQ:**
- ❌ `strlen`, `strcpy`, `strcmp`, `strcat`
- ❌ `strncpy`, `strncmp`, `strncat`
- ❌ `strchr`, `strrchr`, `strstr`
- ❌ `strtok`, `strdup`, `strndup`
- ❌ `printf`, `scanf`, `puts`, `gets`
- ❌ `sprintf`, `sscanf`, `snprintf`

### **Game of Life:**
- ❌ `strlen`, `strcpy`, `strcmp`, `strcat`
- ❌ `printf`, `scanf`, `puts`, `gets`
- ❌ `fprintf`, `fscanf`, `fputs`, `fgets`
- ❌ `sprintf`, `sscanf`, `snprintf`

---

## 🔧 **Implementaciones Alternativas**

### **1. Longitud de String:**
```c
// En lugar de strlen()
int len = 0;
while (str[len] != '\0') {
    len++;
}
```

### **2. Copia de String:**
```c
// En lugar de strcpy()
int i = 0;
while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
}
dest[i] = '\0';
```

### **3. Parsing Manual:**
```c
// En lugar de strtok()
int pos = 0;
while (line[pos] != ' ' && line[pos] != '\n' && line[pos] != '\0') {
    pos++;
}
pos++; // Saltar el delimitador
```

### **4. Conversión de String a Entero:**
```c
// En lugar de atoi() (solo permitida en Game of Life)
int num = 0;
int i = 0;
while (str[i] >= '0' && str[i] <= '9') {
    num = num * 10 + (str[i] - '0');
    i++;
}
```

---

## 📊 **Resumen de Correcciones**

| Ejercicio | Funciones Prohibidas Encontradas | Estado |
|-----------|----------------------------------|---------|
| **BIGINT** | Ninguna | ✅ Correcto |
| **POLYSET** | Ninguna | ✅ Correcto |
| **VECT2** | Ninguna | ✅ Correcto |
| **BSQ** | `strlen`, `strtok`, `strcpy` | ✅ Corregido |
| **Game of Life** | Ninguna | ✅ Correcto |

---

## 🎯 **Consejos para el Examen**

### **1. Leer cuidadosamente las restricciones:**
- **Level-1:** Sin restricciones (C++)
- **Level-2:** Solo funciones específicamente permitidas (C)

### **2. Implementar alternativas manuales:**
- **Longitud de string:** Bucle while
- **Copia de string:** Bucle while
- **Parsing:** Bucle while con delimitadores
- **Conversión:** Bucle while con caracteres

### **3. Probar con las funciones permitidas:**
- **BSQ:** `malloc`, `calloc`, `realloc`, `free`, `fopen`, `fclose`, `getline`, `fscanf`, `fputs`, `fprintf`
- **Game of Life:** `atoi`, `read`, `putchar`, `malloc`, `calloc`, `realloc`, `free`

### **4. Evitar funciones comunes prohibidas:**
- **String functions:** `strlen`, `strcpy`, `strcmp`, `strcat`
- **Print functions:** `printf`, `scanf`, `puts`, `gets`
- **Token functions:** `strtok`, `strdup`

---

## ✅ **Estado Final**

Todos los ejercicios han sido revisados y corregidos:

- **Level-1:** ✅ Sin problemas
- **Level-2:** ✅ Corregido (BSQ)
- **Funciones permitidas:** ✅ Verificadas
- **Implementaciones:** ✅ Alternativas manuales

¡Ahora todos los ejercicios cumplen con las restricciones del examen! 🎉

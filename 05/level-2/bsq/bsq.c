#include "bsq.h"

// Variables globales
ssize_t map_array = 0;
char empty = 0;
char obstacle = 0;
char full = 0;

// ==================== FUNCIONES AUXILIARES ====================

/**
 * @brief Valida si un mapa es válido
 * @param map Matriz del mapa
 * @param rows Número de filas
 * @param cols Número de columnas
 * @return true si es válido, false si no
 */
bool is_valid_map(char **map, int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
        return false;
    
    // Verificar que todas las líneas tengan la misma longitud
    for (int i = 0; i < rows; i++) {
        if (strlen(map[i]) != cols)
            return false;
    }
    
    // Verificar que solo se usen caracteres permitidos
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] != empty && map[i][j] != obstacle)
                return false;
        }
    }
    
    return true;
}

/**
 * @brief Encuentra el cuadrado más grande usando programación dinámica
 * @param map Matriz del mapa
 * @param rows Número de filas
 * @param cols Número de columnas
 * @param max_size Puntero para almacenar el tamaño máximo
 * @param max_row Puntero para almacenar la fila del máximo
 * @param max_col Puntero para almacenar la columna del máximo
 */
void find_biggest_square(char **map, int rows, int cols, int *max_size, int *max_row, int *max_col)
{
    // Crear matriz DP
    int **dp = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = calloc(cols, sizeof(int));
    }
    
    *max_size = 0;
    *max_row = 0;
    *max_col = 0;
    
    // Llenar la matriz DP
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == obstacle) {
                dp[i][j] = 0;
            } else {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    int min_val = dp[i-1][j];
                    if (dp[i][j-1] < min_val) min_val = dp[i][j-1];
                    if (dp[i-1][j-1] < min_val) min_val = dp[i-1][j-1];
                    dp[i][j] = min_val + 1;
                }
                
                // Actualizar máximo
                if (dp[i][j] > *max_size) {
                    *max_size = dp[i][j];
                    *max_row = i;
                    *max_col = j;
                }
            }
        }
    }
    
    // Liberar memoria
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);
}

/**
 * @brief Dibuja el cuadrado más grande en el mapa
 * @param map Matriz del mapa
 * @param max_row Fila del cuadrado
 * @param max_col Columna del cuadrado
 * @param max_size Tamaño del cuadrado
 */
void draw_square(char **map, int max_row, int max_col, int max_size)
{
    for (int i = max_row - max_size + 1; i <= max_row; i++) {
        for (int j = max_col - max_size + 1; j <= max_col; j++) {
            map[i][j] = full;
        }
    }
}

/**
 * @brief Procesa un mapa individual
 * @param map Matriz del mapa
 * @param rows Número de filas
 * @param cols Número de columnas
 */
void process_map(char **map, int rows, int cols)
{
    if (!is_valid_map(map, rows, cols)) {
        fprintf(stderr, "map error\n");
        return;
    }
    
    int max_size, max_row, max_col;
    find_biggest_square(map, rows, cols, &max_size, &max_row, &max_col);
    
    if (max_size > 0) {
        draw_square(map, max_row, max_col, max_size);
    }
    
    // Imprimir resultado
    for (int i = 0; i < rows; i++) {
        printf("%s\n", map[i]);
    }
}

/**
 * @brief Procesa un archivo de mapa
 * @param filename Nombre del archivo
 */
void process_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "map error\n");
        return;
    }
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    // Leer primera línea (metadatos)
    if ((read = getline(&line, &len, file)) == -1) {
        fprintf(stderr, "map error\n");
        free(line);
        fclose(file);
        return;
    }
    
    // Parsear metadatos
    int rows = atoi(line);
    if (rows <= 0) {
        fprintf(stderr, "map error\n");
        free(line);
        fclose(file);
        return;
    }
    
    // Extraer caracteres
    char *token = strtok(line, " \n");
    token = strtok(NULL, " \n");
    if (token) empty = token[0];
    token = strtok(NULL, " \n");
    if (token) obstacle = token[0];
    token = strtok(NULL, " \n");
    if (token) full = token[0];
    
    // Verificar que los caracteres sean diferentes
    if (empty == obstacle || empty == full || obstacle == full) {
        fprintf(stderr, "map error\n");
        free(line);
        fclose(file);
        return;
    }
    
    free(line);
    
    // Leer el mapa
    char **map = malloc(rows * sizeof(char*));
    int cols = 0;
    
    for (int i = 0; i < rows; i++) {
        if ((read = getline(&line, &len, file)) == -1) {
            fprintf(stderr, "map error\n");
            for (int j = 0; j < i; j++) free(map[j]);
            free(map);
            free(line);
            fclose(file);
            return;
        }
        
        // Remover newline
        if (line[read-1] == '\n') {
            line[read-1] = '\0';
            read--;
        }
        
        if (i == 0) {
            cols = read;
        } else if (read != cols) {
            fprintf(stderr, "map error\n");
            for (int j = 0; j < i; j++) free(map[j]);
            free(map);
            free(line);
            fclose(file);
            return;
        }
        
        map[i] = malloc((cols + 1) * sizeof(char));
        strcpy(map[i], line);
    }
    
    free(line);
    fclose(file);
    
    // Procesar el mapa
    process_map(map, rows, cols);
    
    // Liberar memoria
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
}

// ==================== FUNCIONES PRINCIPALES ====================

/**
 * @brief Procesa BSQ desde stdin
 * @param stream Stream de entrada
 */
void ft_bsq_from_stdin(FILE *stream)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    // Leer primera línea (metadatos)
    if ((read = getline(&line, &len, stream)) == -1) {
        fprintf(stderr, "map error\n");
        free(line);
        return;
    }
    
    // Parsear metadatos
    int rows = atoi(line);
    if (rows <= 0) {
        fprintf(stderr, "map error\n");
        free(line);
        return;
    }
    
    // Extraer caracteres
    char *token = strtok(line, " \n");
    token = strtok(NULL, " \n");
    if (token) empty = token[0];
    token = strtok(NULL, " \n");
    if (token) obstacle = token[0];
    token = strtok(NULL, " \n");
    if (token) full = token[0];
    
    // Verificar que los caracteres sean diferentes
    if (empty == obstacle || empty == full || obstacle == full) {
        fprintf(stderr, "map error\n");
        free(line);
        return;
    }
    
    free(line);
    
    // Leer el mapa
    char **map = malloc(rows * sizeof(char*));
    int cols = 0;
    
    for (int i = 0; i < rows; i++) {
        if ((read = getline(&line, &len, stream)) == -1) {
            fprintf(stderr, "map error\n");
            for (int j = 0; j < i; j++) free(map[j]);
            free(map);
            free(line);
            return;
        }
        
        // Remover newline
        if (line[read-1] == '\n') {
            line[read-1] = '\0';
            read--;
        }
        
        if (i == 0) {
            cols = read;
        } else if (read != cols) {
            fprintf(stderr, "map error\n");
            for (int j = 0; j < i; j++) free(map[j]);
            free(map);
            free(line);
            return;
        }
        
        map[i] = malloc((cols + 1) * sizeof(char));
        strcpy(map[i], line);
    }
    
    free(line);
    
    // Procesar el mapa
    process_map(map, rows, cols);
    
    // Liberar memoria
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
}

/**
 * @brief Procesa BSQ desde archivos
 * @param argv Argumentos del programa
 */
void ft_bsq(char **argv)
{
    if (argv[1] == NULL) {
        // Leer desde stdin
        ft_bsq_from_stdin(stdin);
    } else {
        // Procesar cada archivo
        for (int i = 1; argv[i] != NULL; i++) {
            process_file(argv[i]);
            if (argv[i+1] != NULL) {
                printf("\n");
            }
        }
    }
}

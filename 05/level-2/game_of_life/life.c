#include "life.h"

// ==================== FUNCIONES AUXILIARES ====================

/**
 * @brief Crea un tablero vacío
 * @param width Ancho del tablero
 * @param height Alto del tablero
 * @return Matriz del tablero
 */
char** board_creation(int width, int height)
{
    char **board = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        board[i] = calloc(width, sizeof(char));
    }
    return board;
}

/**
 * @brief Libera la memoria del tablero
 * @param board Tablero a liberar
 * @param height Alto del tablero
 */
void free_board(char **board, int height)
{
    for (int i = 0; i < height; i++) {
        free(board[i]);
    }
    free(board);
}

/**
 * @brief Cuenta los vecinos vivos de una célula
 * @param board Tablero actual
 * @param row Fila de la célula
 * @param col Columna de la célula
 * @param height Alto del tablero
 * @param width Ancho del tablero
 * @return Número de vecinos vivos
 */
int count_neighbors(char **board, int row, int col, int height, int width)
{
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
            // Las células fuera del tablero se consideran muertas (0)
        }
    }
    
    return count;
}

/**
 * @brief Aplica las reglas del Game of Life
 * @param current Estado actual de la célula
 * @param neighbors Número de vecinos vivos
 * @return Nuevo estado de la célula
 */
char apply_rules(char current, int neighbors)
{
    if (current == 1) {  // Célula viva
        return (neighbors == 2 || neighbors == 3) ? 1 : 0;
    } else {  // Célula muerta
        return (neighbors == 3) ? 1 : 0;
    }
}

/**
 * @brief Simula una iteración del Game of Life
 * @param board Tablero actual
 * @param width Ancho del tablero
 * @param height Alto del tablero
 * @return Nuevo tablero después de la iteración
 */
char** simulate_iteration(char **board, int width, int height)
{
    char **new_board = board_creation(width, height);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int neighbors = count_neighbors(board, i, j, height, width);
            new_board[i][j] = apply_rules(board[i][j], neighbors);
        }
    }
    
    return new_board;
}

/**
 * @brief Procesa los comandos de dibujo
 * @param board Tablero inicial
 * @param width Ancho del tablero
 * @param height Alto del tablero
 */
void process_commands(char **board, int width, int height)
{
    int pen_x = 0, pen_y = 0;  // Posición del lápiz
    bool pen_down = false;      // Estado del lápiz
    
    char command;
    while (read(0, &command, 1) > 0) {
        switch (command) {
            case 'w':  // Mover arriba
                if (pen_y > 0) pen_y--;
                break;
            case 'a':  // Mover izquierda
                if (pen_x > 0) pen_x--;
                break;
            case 's':  // Mover abajo
                if (pen_y < height - 1) pen_y++;
                break;
            case 'd':  // Mover derecha
                if (pen_x < width - 1) pen_x++;
                break;
            case 'x':  // Toggle lápiz
                pen_down = !pen_down;
                break;
            // Ignorar comandos inválidos
        }
        
        // Dibujar si el lápiz está abajo
        if (pen_down) {
            board[pen_y][pen_x] = 1;  // Célula viva
        }
    }
}

/**
 * @brief Simula el Game of Life por un número de iteraciones
 * @param board Tablero inicial
 * @param width Ancho del tablero
 * @param height Alto del tablero
 * @param iterations Número de iteraciones
 * @return Tablero final después de las iteraciones
 */
char** simulate_life(char **board, int width, int height, int iterations)
{
    char **current_board = board;
    
    for (int iter = 0; iter < iterations; iter++) {
        char **new_board = simulate_iteration(current_board, width, height);
        
        // Liberar tablero anterior si no es el inicial
        if (current_board != board) {
            free_board(current_board, height);
        }
        
        current_board = new_board;
    }
    
    return current_board;
}

/**
 * @brief Imprime el tablero final
 * @param board Tablero a imprimir
 * @param width Ancho del tablero
 * @param height Alto del tablero
 */
void print_board(char **board, int width, int height)
{
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
}

// ==================== FUNCIÓN PRINCIPAL ====================

/**
 * @brief Inicia el Game of Life
 * @param argv Argumentos del programa [width height iterations]
 */
void game_of_life_start(char **argv)
{
    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL) {
        return;
    }
    
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iterations = atoi(argv[3]);
    
    if (width <= 0 || height <= 0 || iterations < 0) {
        return;
    }
    
    // Crear tablero inicial
    char **board = board_creation(width, height);
    
    // Procesar comandos de dibujo
    process_commands(board, width, height);
    
    // Simular Game of Life
    char **final_board = simulate_life(board, width, height, iterations);
    
    // Imprimir resultado
    print_board(final_board, width, height);
    
    // Liberar memoria
    free_board(board, height);
    if (final_board != board) {
        free_board(final_board, height);
    }
}

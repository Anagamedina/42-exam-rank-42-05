#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

/**
 * @brief Vector matemático 2D con enteros
 * Soporta operaciones aritméticas, comparaciones y acceso por índice
 */
class vect2
{
	private:
		int x, y;  // Componentes del vector

	public:
		// ==================== CONSTRUCTORES ====================
		vect2();                                    // Constructor por defecto (0,0)
		vect2(int num1, int num2);                 // Constructor con valores
		vect2(const vect2& source);                // Constructor de copia
		vect2& operator=(const vect2& source);    // Operador de asignación

		// ==================== OPERADORES DE ACCESO ====================
		int operator[](int index) const;            // Acceso de lectura (index 0 o 1)
		int& operator[](int index);                 // Acceso de escritura (index 0 o 1)

		// ==================== OPERADORES UNARIOS ====================
		vect2 operator-() const;                    // Negación del vector

		// ==================== OPERADORES ARITMÉTICOS ====================
		vect2 operator+(const vect2& obj) const;   // Suma de vectores
		vect2 operator-(const vect2& obj) const;    // Resta de vectores
		vect2 operator*(const vect2& obj) const;    // Multiplicación elemento a elemento
		vect2 operator*(int num) const;             // Multiplicación por escalar

		// ==================== OPERADORES DE ASIGNACIÓN ====================
		vect2& operator+=(const vect2& obj);       // Suma y asignación
		vect2& operator-=(const vect2& obj);       // Resta y asignación
		vect2& operator*=(const vect2& obj);       // Multiplicación elemento a elemento y asignación
		vect2& operator*=(int num);                 // Multiplicación por escalar y asignación

		// ==================== OPERADORES DE INCREMENTO/DECREMENTO ====================
		vect2& operator++();                       // Pre-incremento
		vect2 operator++(int);                      // Post-incremento
		vect2& operator--();                        // Pre-decremento
		vect2 operator--(int);                      // Post-decremento

		// ==================== OPERADORES DE COMPARACIÓN ====================
		bool operator==(const vect2& obj) const;   // Igualdad
		bool operator!=(const vect2& obj) const;   // Desigualdad

		~vect2();                                   // Destructor
};

// ==================== OPERADORES FRIEND ====================
vect2 operator*(int num, const vect2& obj);        // Multiplicación escalar conmutativa
std::ostream& operator<<(std::ostream& os, const vect2& obj);  // Salida por stream

#endif


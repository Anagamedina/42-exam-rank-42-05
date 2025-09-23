/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:17:26 by fatkeski          #+#    #+#             */
/*   Updated: 2025/08/01 13:57:18 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT
#define BIGINT

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

/**
 * @brief Clase para manejar números enteros de precisión arbitraria
 * 
 * Esta clase permite trabajar con números enteros más grandes que SIZE_MAX
 * sin pérdida de precisión, almacenándolos como strings.
 */
class bigint
{
	private:
		std::string str;  // Almacena el número como string

	public:
		// ==================== CONSTRUCTORES ====================
		/**
		 * @brief Constructor por defecto
		 * Inicializa el bigint con valor 0
		 */
		bigint();
		
		/**
		 * @brief Constructor con entero sin signo
		 * @param num Número entero a convertir
		 */
		bigint(unsigned int num);
		
		/**
		 * @brief Constructor de copia
		 * @param source Objeto bigint a copiar
		 */
		bigint(const bigint& source);

		// ==================== GETTERS ====================
		/**
		 * @brief Obtiene la representación string del número
		 * @return String que representa el número
		 */
		std::string getStr() const;

		// ==================== OPERADORES DE ASIGNACIÓN ====================
		/**
		 * @brief Operador de asignación
		 * @param source Objeto bigint a asignar
		 * @return Referencia al objeto actual
		 */
		bigint& operator=(const bigint& source);

		// ==================== OPERADORES ARITMÉTICOS ====================
		/**
		 * @brief Operador de suma
		 * @param other Otro bigint a sumar
		 * @return Nuevo bigint con el resultado
		 */
		bigint operator+(const bigint& other) const;
		
		/**
		 * @brief Operador de suma y asignación
		 * @param other Otro bigint a sumar
		 * @return Referencia al objeto actual
		 */
		bigint& operator+=(const bigint& other);

		// ==================== OPERADORES DE INCREMENTO ====================
		/**
		 * @brief Incremento prefijo (++x)
		 * @return Referencia al objeto actual incrementado
		 */
		bigint& operator++();
		
		/**
		 * @brief Incremento postfijo (x++)
		 * @return Copia del objeto antes del incremento
		 */
		bigint operator++(int);

		// ==================== OPERADORES DE DESPLAZAMIENTO (CON ENTERO) ====================
		/**
		 * @brief Desplazamiento a la izquierda (multiplicación por 10^n)
		 * @param n Número de posiciones a desplazar
		 * @return Nuevo bigint desplazado
		 */
		bigint operator<<(unsigned int n) const;
		
		/**
		 * @brief Desplazamiento a la derecha (división por 10^n)
		 * @param n Número de posiciones a desplazar
		 * @return Nuevo bigint desplazado
		 */
		bigint operator>>(unsigned int n) const;
		
		/**
		 * @brief Desplazamiento a la izquierda y asignación
		 * @param n Número de posiciones a desplazar
		 * @return Referencia al objeto actual
		 */
		bigint& operator<<=(unsigned int n);
		
		/**
		 * @brief Desplazamiento a la derecha y asignación
		 * @param n Número de posiciones a desplazar
		 * @return Referencia al objeto actual
		 */
		bigint& operator>>=(unsigned int n);

		// ==================== OPERADORES DE DESPLAZAMIENTO (CON BIGINT) ====================
		/**
		 * @brief Desplazamiento a la izquierda con bigint
		 * @param other Bigint que indica las posiciones a desplazar
		 * @return Nuevo bigint desplazado
		 */
		bigint operator<<(const bigint& other) const;
		
		/**
		 * @brief Desplazamiento a la derecha con bigint
		 * @param other Bigint que indica las posiciones a desplazar
		 * @return Nuevo bigint desplazado
		 */
		bigint operator>>(const bigint& other) const;
		
		/**
		 * @brief Desplazamiento a la izquierda y asignación con bigint
		 * @param other Bigint que indica las posiciones a desplazar
		 * @return Referencia al objeto actual
		 */
		bigint& operator<<=(const bigint& other);
		
		/**
		 * @brief Desplazamiento a la derecha y asignación con bigint
		 * @param other Bigint que indica las posiciones a desplazar
		 * @return Referencia al objeto actual
		 */
		bigint& operator>>=(const bigint& other);

		// ==================== OPERADORES DE COMPARACIÓN ====================
		/**
		 * @brief Operador de igualdad
		 * @param other Otro bigint a comparar
		 * @return true si son iguales, false en caso contrario
		 */
		bool operator==(const bigint& other) const;
		
		/**
		 * @brief Operador de desigualdad
		 * @param other Otro bigint a comparar
		 * @return true si son diferentes, false en caso contrario
		 */
		bool operator!=(const bigint& other) const;
		
		/**
		 * @brief Operador menor que
		 * @param other Otro bigint a comparar
		 * @return true si es menor, false en caso contrario
		 */
		bool operator<(const bigint& other) const;
		
		/**
		 * @brief Operador mayor que
		 * @param other Otro bigint a comparar
		 * @return true si es mayor, false en caso contrario
		 */
		bool operator>(const bigint& other) const;
		
		/**
		 * @brief Operador menor o igual que
		 * @param other Otro bigint a comparar
		 * @return true si es menor o igual, false en caso contrario
		 */
		bool operator<=(const bigint& other) const;
		
		/**
		 * @brief Operador mayor o igual que
		 * @param other Otro bigint a comparar
		 * @return true si es mayor o igual, false en caso contrario
		 */
		bool operator>=(const bigint& other) const;
};

// ==================== OPERADOR DE FLUJO ====================
/**
 * @brief Operador de salida para streams
 * @param output Stream de salida
 * @param obj Objeto bigint a imprimir
 * @return Referencia al stream
 */
std::ostream& operator<<(std::ostream& output, const bigint& obj);

#endif

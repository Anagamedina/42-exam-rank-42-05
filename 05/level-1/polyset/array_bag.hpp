/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:39:23 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/26 19:39:26 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

/**
 * @brief Implementación de bag usando array dinámico
 * Hereda de bag y usa array como estructura de datos subyacente
 */
class array_bag : virtual public bag
{
 protected:
	int *data;  // Array dinámico para almacenar elementos
	int size;   // Número de elementos en el array

 public:
	// ==================== CONSTRUCTORES Y DESTRUCTOR ====================
	array_bag();                                    // Constructor por defecto
	array_bag(const array_bag &);                   // Constructor de copia
	array_bag &operator=(const array_bag &other);   // Operador de asignación
	~array_bag();                                   // Destructor

	// ==================== MÉTODOS DE BAG ====================
	void insert(int);                               // Insertar un elemento
	void insert(int *, int);                        // Insertar array de elementos
	void print() const;                             // Imprimir todos los elementos
	void clear();                                   // Limpiar el bag
};

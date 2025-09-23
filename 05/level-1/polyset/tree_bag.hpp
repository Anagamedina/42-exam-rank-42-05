/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:41:34 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/26 21:14:02 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

/**
 * @brief Implementación de bag usando árbol binario de búsqueda
 * Hereda de bag y usa BST como estructura de datos subyacente
 */
class tree_bag : virtual public bag {
protected:
	// Estructura de nodo del árbol binario de búsqueda
	struct node {
	  node *l;      // Hijo izquierdo
	  node *r;      // Hijo derecho
	  int value;    // Valor del nodo
	};

	node *tree;     // Nodo raíz del árbol

public:
	// ==================== CONSTRUCTORES Y DESTRUCTOR ====================
	tree_bag();                                    // Constructor por defecto
	tree_bag(const tree_bag &);                    // Constructor de copia
	tree_bag &operator=(const tree_bag &);         // Operador de asignación
	~tree_bag();                                   // Destructor

	// ==================== MÉTODOS DE ÁRBOL ====================
	node *extract_tree();                          // Obtener el árbol (getter)
	void set_tree(node *);                         // Establecer el árbol

	// ==================== MÉTODOS DE BAG ====================
	virtual void insert(int);                      // Insertar un elemento
	virtual void insert(int *array, int size);     // Insertar array de elementos
	virtual void print() const;                    // Imprimir todos los elementos
	virtual void clear();                          // Limpiar el bag

private:
	// ==================== MÉTODOS ESTÁTICOS AUXILIARES ====================
	static void destroy_tree(node *);              // Destruir árbol recursivamente
	static void print_node(node *);                // Imprimir nodo recursivamente
	static node *copy_node(node *);                // Copiar nodo recursivamente
};

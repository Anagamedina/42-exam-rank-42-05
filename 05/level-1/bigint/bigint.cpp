/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:27:29 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/26 18:15:45 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

// ==================== CONSTRUCTORES ====================

/**
 * @brief Constructor por defecto
 * Inicializa el bigint con valor "0"
 */
bigint::bigint()
{
	this->str = "0";
}

/**
 * @brief Constructor con entero sin signo
 * Convierte el entero a string para almacenamiento
 * @param num Número entero a convertir
 */
bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->str = ss.str();
}

/**
 * @brief Constructor de copia
 * @param source Objeto bigint a copiar
 */
bigint::bigint(const bigint& source)
{
	(*this) = source;
}

// ==================== OPERADORES DE ASIGNACIÓN ====================

/**
 * @brief Operador de asignación
 * @param source Objeto bigint a asignar
 * @return Referencia al objeto actual
 */
bigint& bigint::operator=(const bigint& source)
{
	if(this == &source)
		return(*this);
	this->str = source.str;
	return(*this);
}

// ==================== GETTERS ====================

/**
 * @brief Obtiene la representación string del número
 * @return String que representa el número
 */
std::string bigint::getStr() const
{
	return(this->str);
}

// ==================== FUNCIONES AUXILIARES ====================

/**
 * @brief Invierte un string
 * @param str String a invertir
 * @return String invertido
 */
std::string reverse(const std::string& str)
{
	std::string revStr;
	for(size_t i = str.length(); i > 0; i--)
	{
		revStr.push_back(str[i - 1]);
	}
	return(revStr);
}

/**
 * @brief Realiza la suma de dos bigint
 * Algoritmo: suma dígito por dígito con carry
 * @param obj1 Primer bigint
 * @param obj2 Segundo bigint
 * @return String con el resultado de la suma
 */
std::string addition(const bigint& obj1, const bigint& obj2)
{
	// Invertir strings para facilitar la suma
	std::string str1 = reverse(obj1.getStr());
	std::string str2 = reverse(obj2.getStr());
	std::string result;
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	// Igualar longitudes con ceros a la derecha
	if(len1 > len2)
	{
		int diff = len1 - len2;
		while(diff > 0)
		{
			str2.push_back('0');
			diff--;
		}
	}
	else if(len2 > len1)
	{
		int diff = len2 - len1;
		while(diff > 0)
		{
			str1.push_back('0');
			diff--;
		}
	}

	// Sumar dígito por dígito con carry
	int carry = 0;
	int digit1;
	int digit2;
	size_t len = str1.length();
	for(size_t i = 0; i < len; i++)
	{
		digit1 = str1[i] - '0';
		digit2 = str2[i] - '0';
		int res = digit1 + digit2 + carry;
		
		if(res > 9)
		{
			carry = res / 10;
			result.push_back((res % 10) + '0');
		}
		else
		{
			carry = 0;  // ¡IMPORTANTE! Resetear carry
			result.push_back(res + '0');
		}
	}
	
	// Si queda carry, agregarlo
	if(carry != 0)
		result.push_back(carry + '0');
	
	return(reverse(result));
}

// ==================== OPERADORES ARITMÉTICOS ====================

/**
 * @brief Operador de suma
 * @param other Otro bigint a sumar
 * @return Nuevo bigint con el resultado
 */
bigint bigint::operator+(const bigint& other) const
{
	bigint temp(other);
	temp.str.clear();
	std::string result = addition(*this, other);
	temp.str = result;
	return(temp);
}

/**
 * @brief Operador de suma y asignación
 * @param other Otro bigint a sumar
 * @return Referencia al objeto actual
 */
bigint& bigint::operator+=(const bigint& other)
{
	(*this) = (*this) + other;
	return(*this);
}

// ==================== OPERADORES DE INCREMENTO ====================

/**
 * @brief Incremento prefijo (++x)
 * @return Referencia al objeto actual incrementado
 */
bigint& bigint::operator++()
{
	*(this) = *(this) + bigint(1);
	return(*this);
}

/**
 * @brief Incremento postfijo (x++)
 * @return Copia del objeto antes del incremento
 */
bigint bigint::operator++(int)
{
	bigint temp = (*this);
	*(this) = *(this) + bigint(1);
	return(temp);
}


// ==================== OPERADORES DE DESPLAZAMIENTO (CON ENTERO) ====================

/**
 * @brief Desplazamiento a la izquierda (multiplicación por 10^n)
 * @param n Número de posiciones a desplazar
 * @return Nuevo bigint desplazado
 */
bigint bigint::operator<<(unsigned int n) const
{
	bigint temp = *this;
	// Agregar n ceros al final (multiplicar por 10^n)
	temp.str.insert(temp.str.end(), n, '0');
	return(temp);
}

/**
 * @brief Desplazamiento a la derecha (división por 10^n)
 * @param n Número de posiciones a desplazar
 * @return Nuevo bigint desplazado
 */
bigint bigint::operator>>(unsigned int n) const
{
	bigint temp = *this;
	size_t len = temp.str.length();
	
	// Si n es mayor o igual a la longitud, resultado es 0
	if(n >= len)
		temp.str = "0";
	else
	{
		// Eliminar n caracteres desde el final
		temp.str.erase(temp.str.length() - n, n);
	}
	return(temp);
}

/**
 * @brief Desplazamiento a la izquierda y asignación
 * @param n Número de posiciones a desplazar
 * @return Referencia al objeto actual
 */
bigint& bigint::operator<<=(unsigned int n)
{
	(*this) = (*this) << n;
	return(*this);
}

/**
 * @brief Desplazamiento a la derecha y asignación
 * @param n Número de posiciones a desplazar
 * @return Referencia al objeto actual
 */
bigint& bigint::operator>>=(unsigned int n)
{
	(*this) = (*this) >> n;
	return(*this);
}

/**
 * @brief Convierte string a unsigned int
 * @param str String a convertir
 * @return Entero sin signo
 */
unsigned int stringToUINT(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

// ==================== OPERADORES DE DESPLAZAMIENTO (CON BIGINT) ====================

/**
 * @brief Desplazamiento a la izquierda con bigint
 * @param other Bigint que indica las posiciones a desplazar
 * @return Nuevo bigint desplazado
 */
bigint bigint::operator<<(const bigint& other) const
{
	bigint temp;
	temp = (*this) << stringToUINT(other.str);
	return(temp);
}

/**
 * @brief Desplazamiento a la derecha con bigint
 * @param other Bigint que indica las posiciones a desplazar
 * @return Nuevo bigint desplazado
 */
bigint bigint::operator>>(const bigint& other) const
{
	bigint temp;
	temp = (*this) >> stringToUINT(other.str);
	return(temp);
}

/**
 * @brief Desplazamiento a la izquierda y asignación con bigint
 * @param other Bigint que indica las posiciones a desplazar
 * @return Referencia al objeto actual
 */
bigint& bigint::operator<<=(const bigint& other)
{
	(*this) = (*this) << stringToUINT(other.str);
	return(*this);
}

/**
 * @brief Desplazamiento a la derecha y asignación con bigint
 * @param other Bigint que indica las posiciones a desplazar
 * @return Referencia al objeto actual
 */
bigint& bigint::operator>>=(const bigint& other)
{
	(*this) = (*this) >> stringToUINT(other.str);
	return(*this);
}


// ==================== OPERADORES DE COMPARACIÓN ====================

/**
 * @brief Operador de igualdad
 * @param other Otro bigint a comparar
 * @return true si son iguales, false en caso contrario
 */
bool bigint::operator==(const bigint& other) const
{
	if(this->getStr() == other.getStr())
		return(true);
	return(false);
}

/**
 * @brief Operador de desigualdad
 * @param other Otro bigint a comparar
 * @return true si son diferentes, false en caso contrario
 */
bool bigint::operator!=(const bigint& other) const
{
	return(!((*this) == (other)));
}

/**
 * @brief Operador menor que
 * @param other Otro bigint a comparar
 * @return true si es menor, false en caso contrario
 */
bool bigint::operator<(const bigint& other) const
{
	std::string str1 = this->str;
	std::string str2 = other.getStr();
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	// Si las longitudes son diferentes, el más corto es menor
	if(len1 != len2)
		return(len1 < len2);
	
	// Si las longitudes son iguales, comparar lexicográficamente
	return(str1 < str2);
}

/**
 * @brief Operador mayor que
 * @param other Otro bigint a comparar
 * @return true si es mayor, false en caso contrario
 */
bool bigint::operator>(const bigint& other) const
{
	return(!(((*this) < other)));
}

/**
 * @brief Operador menor o igual que
 * @param other Otro bigint a comparar
 * @return true si es menor o igual, false en caso contrario
 */
bool bigint::operator<=(const bigint& other) const
{
	return((((*this) < other) || ((*this) == other)));
}

/**
 * @brief Operador mayor o igual que
 * @param other Otro bigint a comparar
 * @return true si es mayor o igual, false en caso contrario
 */
bool bigint::operator>=(const bigint& other) const
{
	return((((*this) > other) || ((*this) == other)));
}

// ==================== OPERADOR DE FLUJO ====================

/**
 * @brief Operador de salida para streams
 * @param output Stream de salida
 * @param obj Objeto bigint a imprimir
 * @return Referencia al stream
 */
std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return(output);
}

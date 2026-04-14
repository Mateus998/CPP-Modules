/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:42:20 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/14 20:25:34 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
const char* Array<T>::InvalidIdx::what() const throw(){
    return "Invlaid index";
};

template<typename T>
Array<T>::Array(void): _array(NULL), _size(0){};

template<typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){};

template<typename T>
Array<T>::Array(const Array& other): _array(new T[other._size]), _size(other._size){
    *this = other;
};

template<typename T>
Array<T>::~Array(void){
    delete[] _array;
};

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
    if (this != &other){
        if(this->_size > 0)
            delete[] this->_array;
            
        this->_array = new T[other._size];
        this->_size = other._size;
        for (size_t i = 0; i < _size; i++){
            _array[i] = other._array[i];
        }
    }
    return *this;
};

template<typename T>
T& Array<T>::operator[](const size_t i) const{
    if (i >= _size)
        throw InvalidIdx();
    return this->_array[i];
};

template<typename T>
size_t Array<T>::size(void) const{
    return _size;
};
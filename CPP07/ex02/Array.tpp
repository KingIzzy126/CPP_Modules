/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:31:20 by ismailalash       #+#    #+#             */
/*   Updated: 2026/04/08 14:59:51 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ---------------------------------------------- */
/*          Constructors & Destructor             */
/* ---------------------------------------------- */

template<typename T>
Array<T>::Array() : _data(NULL), _size(0) 
{
    std::cout << "Array default constructor created\n";
}

template<typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
    std::cout << "Array constructor with size " << n << " created\n";
    if (n > 0)
        _data = new T[n]();
}

template<typename T>
Array<T>::Array(const Array &other) : _data(NULL), _size(other._size)
{
    std::cout << "Array copy constructor created\n";
    if (_size > 0)
    {
        _data = new T[_size]();
        unsigned int i = 0;
        while (i < _size)
        {
            _data[i] = other._data[i];
            i++;
        }
    }
}

template<typename T> 
Array<T>::~Array()
{
    std::cout << "Array destructor called\n";
    delete [] _data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
    std::cout << "Array assignment operator called\n";
    
    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new T[_size]();
        
        unsigned int i = 0;
        while (i < _size)
        {
            _data[i] = other._data[i];
            i++;
        }
    }
    return *this;
}

/* ---------------------------------------------- */
/*    Subscript Operator (const & non const)      */
/* ---------------------------------------------- */

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw Array<T>::OutOfBoundsException();
    return _data[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw Array<T>::OutOfBoundsException();
    return _data[index];
}

/* ---------------------------------------------- */
/*                   Functions                    */
/* ---------------------------------------------- */

template<typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what(void) const throw()
{
    return ("Error: Index out of bounds");
}
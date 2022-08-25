#ifndef LSL_H
#define LSL_H
#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

template<typename T>
class LSL
{
private:
    struct NodoLSL
    {
        T dato;
        shared_ptr<NodoLSL> siguiente;

        NodoLSL(const T& elem, shared_ptr<NodoLSL> sig = nullptr) :
            dato(elem), siguiente(sig)
        {}
    };

    size_t listSize;
    shared_ptr<NodoLSL> listFront;
    shared_ptr<NodoLSL> listBack;

public:
    LSL()
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;
    }
    ~LSL()
    {
        clear();
    }

    bool empty() const;
    size_t size() const;
    void push_front(const T& elem);
    void push_back(const T& elem);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& elem);
    void erase(size_t position);
    void clear();
    void remove(const T& value);
    T& operator [](size_t position);
};

template<typename T>
bool LSL<T>::empty() const
{
    return listSize == 0;
}

template<typename T>
size_t LSL<T>::size() const
{
    return listSize;
}

template<typename T>
void LSL<T>::push_front(const T &elem)
{
    if (empty())
    {
        listFront = make_shared<NodoLSL>(elem);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodoLSL> temp = make_shared<NodoLSL>(elem, listFront);
        listFront = temp;
    }

    ++listSize;
}

template<typename T>
void LSL<T>::push_back(const T &elem)
{
    if (empty())
    {
        listFront = make_shared<NodoLSL>(elem);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodoLSL> temp = make_shared<NodoLSL>(elem);
        listBack->siguiente = temp;
        listBack = temp;
    }

    ++listSize;
}

template<typename T>
const T &LSL<T>::front() const
{
    if (empty())
    {
        throw range_error("Trying front() from empty list");
    }
    return listFront->dato;
}

template<typename T>
const T &LSL<T>::back() const
{
    if (empty())
    {
        throw range_error("Trying back() from empty list");
    }
    return listBack->dato;
}

template<typename T>
void LSL<T>::pop_front()
{
    if (empty())
    {
        throw range_error("Trying pop_front() from empty list");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        listFront = listFront->siguiente;
    }
    --listSize;
}

template<typename T>
void LSL<T>::pop_back()
{
    if (empty())
    {
        throw range_error("Trying pop_back() from empty list");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        shared_ptr<NodoLSL> temp = listFront;
        while (temp->siguiente != listBack)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nullptr;
        listBack = temp;
    }
    --listSize;
}

template<typename T>
void LSL<T>::insert(size_t position, const T &elem)
{
    if (position > size())
    {
        throw range_error("Trying insert() in non valid position");
    }
    if (position == 0)
    {
        push_front(elem);
    }
    else if (position == size())
    {
        push_back(elem);
    }
    else
    {
        shared_ptr<NodoLSL> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->siguiente;
        }
        shared_ptr<NodoLSL> nuevo = make_shared<NodoLSL>(elem, temp->siguiente);
        temp->siguiente = nuevo;
        ++listSize;
    }
}

template<typename T>
void LSL<T>::erase(size_t position)
{
    if (empty())
    {
        throw range_error("Trying erase() from empty list");
    }
    if (position >= size())
    {
        throw range_error("Trying erase() in non valid position");
    }
    else if (position == 0)
    {
        pop_front();
    }
    else if (position == size()-1)
    {
        pop_back();
    }
    else
    {
        shared_ptr<NodoLSL> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->siguiente;
        }
        shared_ptr<NodoLSL> eliminar = temp->siguiente;
        temp->siguiente = eliminar->siguiente;
        eliminar->siguiente = nullptr;
        --listSize;
    }
}

template<typename T>
void LSL<T>::clear()
{
    for (size_t i(0), j(size()); i < j; ++i)
    {
        pop_front();
    }
}

template<typename T>
void LSL<T>::remove(const T &value)
{
    if (empty())
    {
        throw range_error("Trying remove() from empty list");
    }
    T dato;
    shared_ptr<NodoLSL> temp = listFront;
    size_t i(0);

    while(temp != nullptr)
    {
        dato = temp->dato;
        temp = temp->siguiente;
        if (dato == value)
        {
            erase(i);
            --i;
        }
        ++i;
    }
}

template<typename T>
T &LSL<T>::operator [](size_t position)
{
    if (empty())
    {
        throw range_error("Trying [] from empty list");
    }
    if (position >= size())
    {
        throw range_error("Trying [] in non valid position");
    }
    shared_ptr<NodoLSL> temp = listFront;
    for (size_t i(0); i < position; ++i)
    {
        temp = temp->siguiente;
    }
    return temp->dato;
}
#endif // LSL_H

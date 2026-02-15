#include "ListException.h"
#include <iostream>

ListException::ListException(const std::string& msg) : message(msg) {
    std::cout << "ERROR: " << message << std::endl;
}

const char* ListException::what() const noexcept {
    return message.c_str();
}

InvalidIndexException::InvalidIndexException(int index, int size) 
    : ListException("Índice inválido: " + std::to_string(index) + 
                    " (tamaño: " + std::to_string(size) + ")") {}

EmptyListException::EmptyListException() 
    : ListException("La lista está vacía") {}

#include "InputException.h"

InputException::InputException(const std::string& msg) : message(msg) {
    std::cout << "ERROR DE ENTRADA: " << message << std::endl;
}

const char* InputException::what() const noexcept {
    return message.c_str();
}

InvalidInputException::InvalidInputException(const std::string& details)
    : InputException("Entrada inválida" + (details.empty() ? "" : ": " + details)) {}

OutOfRangeInputException::OutOfRangeInputException(int value, int minimo, int maximo)
    : InputException("Valor " + std::to_string(value) + 
                    " fuera de rango (" + std::to_string(minimo) + 
                    "-" + std::to_string(maximo) + ")") {}

InputBufferException::InputBufferException()
    : InputException("Error al limpiar el buffer de entrada") {}

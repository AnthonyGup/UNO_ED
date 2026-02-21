#ifndef LIST_EXCEPTION_H
#define LIST_EXCEPTION_H

#include <exception>
#include <string>
#include <iostream>

class ListException : public std::exception {
private:
    std::string message;

public:
    ListException(const std::string& msg);
    virtual const char* what() const noexcept override;
};

class InvalidIndexException : public ListException {
public:
    InvalidIndexException(int index, int size);
};

class EmptyListException : public ListException {
public:
    EmptyListException();
};

class FullListException : public ListException {
public:
    FullListException();
};

#endif

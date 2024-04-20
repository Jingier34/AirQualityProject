//
// Created by 白白 on 2024/4/19.
//

#ifndef FINALPROJECT_VECTOR_H
#define FINALPROJECT_VECTOR_H

#include "AirQuality.h"

template <typename T>
class Vector {
private:
    T* elements;
    int size;
    int capacity;

public:
    // Constructor
    Vector(int initialCapacity = 10) : size(0), capacity(initialCapacity) {
        elements = new T[capacity];
    }

    // Destructor
    ~Vector() {
        delete[] elements;
    }

    // Function to add an element to the vector
    void push_back(const T& element) {
        if (size >= capacity) {
            // If the vector is full, double the capacity
            capacity *= 2;
            T* newElements = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
        }
        elements[size++] = element;
    }

    // Function to get the element at a specific index
    T& operator[](int index) {
        return elements[index];
    }

    // Function to get the size of the vector
    int getSize() const {
        return size;
    }

    AirQuality* begin() {
        return &elements[0];
    }


    AirQuality* end() {
        return &elements[size];
    }


    const AirQuality* begin() const {
        return &elements[0];
    }


    const AirQuality* end() const {
        return &elements[size];
    }

};


#endif //FINALPROJECT_VECTOR_H

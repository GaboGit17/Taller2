//
// Created by gabri on 15-10-2025.
//

#include "SparseMatrix.h"

#include "SparseMatrix.h"
#include <iostream>
using namespace std;


// Constructor sin argumentos

SparseMatrix::SparseMatrix() {
    start = nullptr;
}


// Destructor sin argumentos

SparseMatrix::~SparseMatrix() {

}


// Insertar un dato en las coordenada (x, y)

void SparseMatrix::add(int value, int xPos, int yPos) {

    if (value == 0)
        return;

    Node* nuevo = new Node(value, xPos, yPos);

    if (start == nullptr) {
        start = nuevo;
        return;
    }

    Node* actual = start;
    Node* anterior = nullptr;


    while (actual != nullptr) {
        if (actual->x == xPos && actual->y == yPos) {

            actual->value = value;
            delete nuevo;
            return;
        }
        anterior = actual;
        actual = actual->next;
    }


    anterior->next = nuevo;
}


// Obtener el valor en las coordenadas (x, y)
// Si no existe, retornar 0

int SparseMatrix::get(int xPos, int yPos) {
    Node* actual = start;

    while (actual != nullptr) {
        if (actual->x == xPos && actual->y == yPos)
            return actual->value;
        actual = actual->next;
    }
    return 0;
}

// Eliminar un dato según las coordenadas (x, y)

void SparseMatrix::remove(int xPos, int yPos) {
    if (start == nullptr)
        return;

    Node* actual = start;
    Node* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->x == xPos && actual->y == yPos) {

            if (anterior == nullptr)
                start = actual->next;
            else
                anterior->next = actual->next;

            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->next;
    }
}

//
// Created by gabri on 22-10-2025.
//

#include <iostream>
#include "SparseMatrix.h"

using namespace std;

SparseMatrix::SparseMatrix() {
    start = nullptr;
}

SparseMatrix::~SparseMatrix() {
    Node* actual = start;
    while (actual != nullptr) {
        Node* siguiente = actual->next;
        delete actual;
        actual = siguiente;
    }
}

void SparseMatrix::add(int value, int xPos, int yPos) {
    // si el valor es 0 no insetamos nada
    if (value == 0)
        return;

    Node* nuevo = new Node(value, xPos, yPos);
    // si la lista esta vacía insertamos
    if (start == nullptr) {
        start = nuevo;
        return;
    }

    Node* actual = start;
    Node* anterior = nullptr;

    // siempre que haya nodos recorremos la lista
    while (actual != nullptr) {
        // si el nodo tiene los mismo valores de x,y lo actualizamos con valores nuevos
        if (actual->x == xPos && actual->y == yPos) {
            actual->value = value;
            delete nuevo;
            return;
        }

        anterior = actual;
        actual = actual->next;
    }

    // si es un nodo con posiciones x,y nuevas lo insertamos al final de la lista
    anterior->next = nuevo;
}

int SparseMatrix::get(int xPos, int yPos) {
    Node* actual = start;

    // siempre que haya nodo recorremos
    while (actual != nullptr) {
        // si lo encontramos en posicion x,y imprimimos el valor
        if (actual->x == xPos && actual->y == yPos) {
            return actual->value;
        }
        actual = actual->next;
    }

    return 0;
}

void SparseMatrix::remove(int xPos, int yPos) {
    if (start == nullptr) return;

    Node* actual = start;
    Node* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->x == xPos && actual->y == yPos) {
            if (anterior == nullptr) {
                start = actual->next;
            } else {
                anterior->next = actual->next;
            }
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->next;
    }
}

void SparseMatrix::printStoredValues() {
    Node* actual = start;
    while (actual != nullptr) {
        cout << "(" << actual->x << ", " << actual->y << ") --> " << actual->value << endl;
        actual = actual->next;
    }
}

int SparseMatrix::density() {
    if (start == nullptr) return 0;

    int count = 0;
    int xMax = 0;
    int yMax = 0;

    Node* actual = start;
    while (actual != nullptr) {
        count++;

        if (actual->x > xMax)
            xMax = actual->x;
        if (actual->y > yMax)
            yMax = actual->y;

        actual = actual->next;
    }

    // Se calcula para cumplir con el enunciado, aunque no se usa para el retorno
    int totalSize = (xMax + 1) * (yMax + 1);
    if (totalSize == 0) return 0;

    return count;
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second) {
    SparseMatrix* resultado = new SparseMatrix();

    Node* a = start;
    while (a != nullptr) {
        Node* b = second->start;
        while (b != nullptr) {
            if (a->y == b->x) {
                int val = resultado->get(a->x, b->y);
                resultado->add(val + a->value * b->value, a->x, b->y);
            }
            b = b->next;
        }
        a = a->next;
    }

    return resultado;
}

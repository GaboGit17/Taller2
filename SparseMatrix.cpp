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
    // si el valor es 0 no insetamos nada
    if (value == 0)
        return;

    Node* nuevo = new Node(value, xPos, yPos);
    //si la lista esta vacia insertamos
    if (start == nullptr) {
        start = nuevo;
        return;
    }

    Node* actual = start;
    Node* anterior = nullptr;

    //siempre que haya nodos recorremos la lista
    while (actual != nullptr) {
        //si el nodo tiene los mismo valores de x,y lo actualizamos con valores nuevos
        if (actual->x == xPos && actual->y == yPos) {

            actual->value = value;
            delete nuevo;
            return;
        }

        anterior = actual;
        actual = actual->next;
    }

    // si es un nodo con posciones x,y nuevas lo insertamos al final de la lista
    anterior->next = nuevo;
}


// Obtener el valor en las coordenadas (x, y)
// Si no existe, retornar 0

int SparseMatrix::get(int xPos, int yPos) {
    Node* actual = start;
    // siempre que haya nodo recorremos
    while (actual != nullptr) {
        //si lo encontramos en posicion x,y imprimimos el valor
        if (actual->x == xPos && actual->y == yPos) {
            return actual->value;
        }
        actual = actual->next;
    }
    return 0;
}

// Eliminar un dato según las coordenadas (x, y)

void SparseMatrix::remove(int xPos, int yPos) {
    // si no hay nada returnamos
    if (start == nullptr)
        return;

    Node* actual = start;
    Node* anterior = nullptr;
    // siempre que haya nodo
    while (actual != nullptr) {
        // si encontramos con nodo con esos valores en x,y
        if (actual->x == xPos && actual->y == yPos) {
            //si es el primer nodo
            if (anterior == nullptr) {
                // el Nodo de inicio sera null
                start = actual->next;
            }else {
                // si es un nodo del medio, el anterior sera el actual y el siguiente sera el siguiente del actual xd
                anterior->next = actual->next;
                //borramos y returnamos
            }
            //borramos despues de definir previamente dependiendo del caso
            delete actual;
            return;
        }
        //avanzamos while
        anterior = actual;
        actual = actual->next;
    }
}

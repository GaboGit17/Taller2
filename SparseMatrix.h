//
// Created by gabri on 15-10-2025.
//

#pragma once


#pragma once
#include "Node.h"

class SparseMatrix {
private:
    Node* start;

public:
    SparseMatrix();
    void add(int value, int xPos, int yPos);
    int get(int xPos, int yPos);
    void remove(int xPos, int yPos);
    void printStoredValues();
    void density();
    SparseMatrix* multiply(SparseMatrix* second);
    ~SparseMatrix();
};
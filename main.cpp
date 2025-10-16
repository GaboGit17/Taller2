//
// Created by gabri on 15-10-2025.
//


#include <iostream>


#include "Node.h"
#include "SparseMatrix.h"




int main() {

    SparseMatrix* matrix = new SparseMatrix();

    matrix->add(5,1,2);

    matrix->add(5,2,3);

    std::cout << matrix->get(1,2) << std::endl;

    delete matrix;

    return 0;
}
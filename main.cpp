//
// Created by gabri on 22-10-2025.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include "SparseMatrix.h"

using namespace std;

// Genera N coordenadas únicas dentro de una matriz de filas x columnas
vector<pair<int, int>> generarCoordenadasUnicas(int N, int filas, int columnas) {
    set<pair<int, int>> usadas;
    vector<pair<int, int>> resultado;

    while ((int)resultado.size() < N) {
        int x = rand() % filas;
        int y = rand() % columnas;

        if (usadas.find({x, y}) == usadas.end()) {
            usadas.insert({x, y});
            resultado.push_back({x, y});
        }
    }

    return resultado;
}

// Mide el tiempo promedio de inserción para N datos en matriz de tamaño filas x columnas
double testadd(int cantidadDatos, int filas, int columnas, int repeticiones) {
    double tiempoTotal = 0;

    for (int r = 0; r < repeticiones; r++) {
        SparseMatrix matrix;
        vector<pair<int, int>> coordenadas = generarCoordenadasUnicas(cantidadDatos, filas, columnas);

        clock_t inicio = clock();

        for (const auto& coord : coordenadas) {
            int valor = rand() % 100 + 1;  // valor aleatorio entre 1 y 100
            matrix.add(valor, coord.first, coord.second);
        }

        clock_t fin = clock();
        double duracion = double(fin - inicio) / CLOCKS_PER_SEC;
        tiempoTotal += duracion;
    }

    return tiempoTotal / repeticiones;
}



int main() {
    srand(time(0)); // Inicializa semilla aleatoria

    int repeticiones = 10;
    int tamaños[] = {50, 250, 500, 1000, 5000};

    for (int N : tamaños) {
        // Caso densidad < 40%
        int filas1 = N * 2;
        int columnas1 = N * 2;

        double tiempoBajo = testadd(N, filas1, columnas1, repeticiones);
        cout << "[ADD] N = " << N << " | Densidad < 40% | Tiempo promedio = "
             << tiempoBajo << " segundos" << endl;

        // Caso densidad > 70%
        int lado = int(sqrt(N / 0.75));
        double tiempoAlto = testadd(N, lado, lado, repeticiones);
        cout << "[ADD] N = " << N << " | Densidad > 70% | Tiempo promedio = "
             << tiempoAlto << " segundos" << endl;

        cout << "--------------------------------------------------" << endl;
    }

    return 0;
}





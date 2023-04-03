//
// Created by Brian on 2/4/2023.
//
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

#ifndef PRACTICA_1_EJ2_CUADRADOMAGICO_H
#define PRACTICA_1_EJ2_CUADRADOMAGICO_H


bool is_valid(vector<vector<int>> &s) {
    int n = s.size();

    // Calculo el num mágico haciendo la suma. Esto funciona porque con que 1 fila, columna o diagonal de diferente
    // no importa si es o no el numero mágico, ya no es un cuadrado magico valido
    int m = 0;
    for (int i = 0; i < n; i++) {
        m += s[i][0];
    }

    // Compruebo la suma de las filas y columnas.
    for (int i = 0; i < n; i++) {
        int fila = 0;
        int col = 0;
        for (int j = 0; j < n; j++) {
            fila += s[i][j];
            col += s[j][i];
        }
        if (fila != m || col != m) return false;
    }

    //  diagonales.
    int diagonal1 = 0;
    int diagonal2 = 0;
    for (int i = 0; i < n; i++) {
        diagonal1 += s[i][i];
        diagonal2 += s[i][n - i - 1];
    }
    if (diagonal1 != m || diagonal2 != m) return false;

    return true;
}

int magic_squares(vector<vector<int>> &s, int i, int j, vector<int> &c) {
    int n = s.size();
    if (j == n) return magic_squares(s, i + 1, 0, c); // Continue on next row.
    if (i == n) return is_valid(s); // Square is filled.
    int cantidad = 0; // Solutions counter.
    for (int k = 0; k < n * n; k++) {
        if (c[k] == 0) { // k is available.
            s[i][j] = k + 1;
            c[k] = 1;
            cantidad += magic_squares(s, i, j + 1, c);
            c[k] = 0; // Backtrack.
        }
    }
    return cantidad;
}
#endif //PRACTICA_1_EJ2_CUADRADOMAGICO_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include "ej2_cuadradoMagico.h"
#include "ej2_cuadradoMagicoPoda.h"
using namespace std;


int main() {

    //Ejercicio 2
    int n; //= atoi(argv[1]);
   cout << "Introducir n " << endl;
    // Initialize arguments.
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n)); // magic square
    vector<int> c(n * n); // candidates

    int r = magic_squares(s, 0, 0, c);
    printf("%dx%d magic squares (naive): %d\n", n, n, r);

    vector<vector<int>> s2(n, vector<int>(n)); // magic square
    vector<int> sumas ((2*n)+2);
    vector<int> c2(n * n,0);
    int m= (n*n*n + n)/2;
    int r2= cuadradoMagicoConPoda(s2,0,0,c2,sumas,m);
    printf("%dx%d cuadrados magicos con poda: %d\n", n, n, r2);
    return 0;
}
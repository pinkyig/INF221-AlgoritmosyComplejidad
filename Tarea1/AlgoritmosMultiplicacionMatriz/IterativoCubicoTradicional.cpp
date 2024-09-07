#include "chrono"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

//Funcion pobladora de matrices cuadradas
vector<vector<int> > pobladorMatriz(vector<vector<int> > matriz, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matriz[i][j] = rand() % 100;
        }
    }
    return matriz;
}

void printMatriz(vector<vector<int> > matriz, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    int n;

    //obteniendo el tamaño de la matriz cuadrada leyendo el archivo
    ifstream MyFile("dataSetMatriz.txt");
    MyFile >> n;
    MyFile.close();

    cout << "Tamaño de la matriz cuadrada: " << n << endl;

    srand(time(0)); // semilla para generar números aleatorios

    vector<vector<int> > matrizA(n, vector<int>(n));
    matrizA = pobladorMatriz(matrizA, n);

    vector<vector<int> > matrizB(n, vector<int>(n));
    matrizB = pobladorMatriz(matrizB, n);
    

    //Algoritmo de multiplicacion de matrices iterativo cubico tradicional
    vector<vector<int> > C(n, vector<int>(n));

    auto startChrono = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                C[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    auto endChrono = chrono::high_resolution_clock::now();

    auto durationMicrosegundos = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();
    auto tiempoMilisegundos = durationMicrosegundos / 1e3;
    
    cout << "matriz multiplicada con exito!" << endl;

    cout << "Tiempo de ejecucion: " << durationMicrosegundos << " microsegundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoMilisegundos << " milisegundos" << endl;

    return 0;
}
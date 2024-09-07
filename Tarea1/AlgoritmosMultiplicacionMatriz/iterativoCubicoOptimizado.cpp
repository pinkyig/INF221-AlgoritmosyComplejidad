#include <iostream>
#include <vector>
#include <fstream>
#include <sys/time.h>
#include <algorithm>
#include <cstdlib>
#include "chrono"

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

void transponerMatriz(vector<vector<int> > &matriz, int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            swap(matriz[i][j], matriz[j][i]);
        }
    }
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


    vector<vector<int> > matrizA(n, vector<int>(n));
    matrizA = pobladorMatriz(matrizA, n);

    vector<vector<int> > matrizB(n, vector<int>(n));
    matrizB = pobladorMatriz(matrizB, n);

    vector<vector<int> > C(n, vector<int>(n));

    //Algoritmo de multiplicacion de matrices iterativo cubico optimizado
    auto startChrono = chrono::high_resolution_clock::now();
    transponerMatriz(matrizB, n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int sum = 0;
            for (int k = 0; k < n; k++){
                sum += matrizA[i][k] * matrizB[j][k];
            }
            C[i][j] = sum;
        }
    }
    auto endChrono = chrono::high_resolution_clock::now();

    auto durationMicrosegundos = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();
    auto tiempoMilisegundos = durationMicrosegundos / 1e3;


    cout << "Matriz multiplicada con exito!" << endl;

    cout << "Tiempo de ejecucion: " << durationMicrosegundos << " microsegundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoMilisegundos << " milisegundos" << endl;

    return 0;
    
}
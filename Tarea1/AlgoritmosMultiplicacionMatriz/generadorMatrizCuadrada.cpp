#include "iostream"
#include "fstream"
#include "string"
#include "cstdlib"
#include "ctime"
#include "vector"
#include <algorithm>
#include <random>
using namespace std;



int main(){
    long long int n;

    cout << "Ingrese el tamaño para las 2  matrices cuadradas (solo potencias de 2): ";
    cin >> n;

    srand(time(0));

    ofstream MyFile("dataSetMatriz.txt");

    //Tamaño de las matrices en la primera linea del archivo
    MyFile << n << endl;

    //Generando matriz A
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            MyFile << rand() % 100 << " ";
        }
        MyFile << endl;
    }

    MyFile << endl;

    //Generando matriz B
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            MyFile << rand() % 100 << " ";
        }
        MyFile << endl;
    }

    MyFile.close();

    cout << "Matrices generadas con exito!" << endl;

    return 0;
}
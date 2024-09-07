#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sys/time.h>
#include <chrono>
using namespace std;


vector <int> pobladorVector(vector<int> elementos){
    ifstream MyFile("dataSet.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}


int main(){
    long tiempoMicrosegundos;
    double tiempoSegundos;
        

    vector<int> elementos;
    elementos = pobladorVector(elementos);

    auto startChrono = chrono::high_resolution_clock::now();
    sort(elementos.begin(), elementos.end());
    auto endChrono = chrono::high_resolution_clock::now();

    cout << "Elementos ordenados con exito!" << endl;

    auto durationMicrosegundos = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();

    auto tiempoMilisegundos = durationMicrosegundos / 1e3;

    cout << "Tiempo de ejecucion: " << durationMicrosegundos << " microsegundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoMilisegundos << " milisegundos" << endl;

    return 0;
}
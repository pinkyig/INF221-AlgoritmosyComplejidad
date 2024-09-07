#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include <sys/time.h>
#include "chrono"
using namespace std;

vector<int> pobladorVector(vector<int> elementos){
    ifstream MyFile("dataSet.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}


void bubbleSort(vector<int>& elementos){
    int n = elementos.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (elementos[j] > elementos[j + 1]){
                int temp = elementos[j];
                elementos[j] = elementos[j + 1];
                elementos[j + 1] = temp;
            }
        }
    }
}


int main(){
    long tiempoMicrosegundos;
    double tiempoSegundos;
        

    vector<int> elementos;
    elementos = pobladorVector(elementos);

    //obteniendo el tiempo de ejecucion

    auto startChrono = chrono::high_resolution_clock::now();
    bubbleSort(elementos);
    auto endChrono = chrono::high_resolution_clock::now();

    cout << "Elementos ordenados con exito!" << endl;

    auto durationMicrosegundos = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();

    auto tiempoMilisegundos = durationMicrosegundos / 1e3;

    cout << "Tiempo de ejecucion: " << durationMicrosegundos << " microsegundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoMilisegundos << " milisegundos" << endl;

}
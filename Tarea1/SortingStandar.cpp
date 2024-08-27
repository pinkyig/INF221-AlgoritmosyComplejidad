#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/time.h>

using namespace std;


long long int get_time_usec(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}


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

    //obteniendo el tiempo de ejecucion
    long long int start = get_time_usec();
    sort(elementos.begin(), elementos.end());
    long long int end = get_time_usec();

    tiempoMicrosegundos = end - start;
    tiempoSegundos = tiempoMicrosegundos / 1e6;

    cout << "Elementos ordenados con exito!" << endl;

    cout << "Tiempo de ejecucion: " << tiempoSegundos << " segundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoMicrosegundos << " microsegundos" << endl;

    return 0;
}
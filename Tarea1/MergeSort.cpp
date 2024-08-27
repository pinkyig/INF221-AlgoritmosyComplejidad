#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include <sys/time.h>
using namespace std;


long long int get_time_usec(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}


//poblador de vector
vector<int> pobladorVector(vector<int> elementos){
    ifstream MyFile("dataSet.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}


//funcion de ordenamiento mergeSort

void merge(vector<int>& elementos, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = elementos[l + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = elementos[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            elementos[k] = L[i];
            i++;
        }else{
            elementos[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        elementos[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        elementos[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& elementos, int l, int r){
    if (l >= r){
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(elementos, l, m);
    mergeSort(elementos, m + 1, r);
    merge(elementos, l, m, r);
}



int main(){

    long tiempoMicrosegundos;
    double tiempoSegundos;
        

    vector<int> elementos;
    elementos = pobladorVector(elementos);

    //obteniendo el tiempo de ejecucion
    long long int start = get_time_usec();
    mergeSort(elementos, 0, elementos.size() - 1);
    long long int end = get_time_usec();

    cout << "Elementos ordenados con exito!" << endl;

    tiempoMicrosegundos = end - start;
    tiempoSegundos = tiempoMicrosegundos / 1e6;

    cout << "Tiempo de ejecucion: " << tiempoMicrosegundos << " microsegundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoSegundos << " segundos" << endl;    

}
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


vector<int> pobladorVector(vector<int> elementos){
    ifstream MyFile("dataSet.txt");
    int n;
    while (MyFile >> n){
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;

}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}


int partition(vector<int>& elementos, int low, int high){
    int pivot = elementos[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++){
        if (elementos[j] < pivot){
            i++;
            swap(elementos[i], elementos[j]);
        }
    }
    swap(elementos[i + 1], elementos[high]);
    return (i + 1);
}


void quickSort(vector<int>& elementos, int low, int high){
    if (low < high){
        int pi = partition(elementos, low, high);

        quickSort(elementos, low, pi - 1);
        quickSort(elementos, pi + 1, high);
    }
}






int main(){
    long tiempoMicrosegundos;
    double tiempoSegundos;
        

    vector<int> elementos;
    elementos = pobladorVector(elementos);

    //obteniendo el tiempo de ejecucion
    long long int start = get_time_usec();
    quickSort(elementos, 0, elementos.size() - 1);
    long long int end = get_time_usec();
    cout << "Elementos ordenados con exito!" << endl;

    tiempoMicrosegundos = end - start;
    tiempoSegundos = tiempoMicrosegundos / 1e6;

    cout << "Tiempo de ejecucion: " << tiempoSegundos << " segundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoMicrosegundos << " microsegundos" << endl;




    return 0;
}
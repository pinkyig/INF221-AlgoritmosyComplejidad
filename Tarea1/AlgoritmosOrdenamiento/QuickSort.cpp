    #include "iostream"
    #include "string"
    #include "vector"
    #include "fstream"
    #include <sys/time.h>
    #include "chrono"
    using namespace std;


#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include <sys/time.h>
#include "chrono"
using namespace std;

long long int get_time_usec() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

vector<int> pobladorVector(vector<int>& elementos) {
    ifstream MyFile("dataSet.txt");
    int n;
    while (MyFile >> n) {
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int medianOfThree(vector<int>& elementos, int low, int high) {
    int mid = low + (high - low) / 2;
    if (elementos[low] > elementos[mid])
        swap(elementos[low], elementos[mid]);
    if (elementos[low] > elementos[high])
        swap(elementos[low], elementos[high]);
    if (elementos[mid] > elementos[high])
        swap(elementos[mid], elementos[high]);
    swap(elementos[mid], elementos[high - 1]);  // Coloca el pivote al final
    return elementos[high - 1];  // Pivote
}

int partition(vector<int>& elementos, int low, int high) {
    int pivot = medianOfThree(elementos, low, high);
    int i = low;
    int j = high - 1;

    while (true) {
        while (elementos[++i] < pivot) {}
        while (elementos[--j] > pivot) {}
        if (i >= j)
            break;
        swap(elementos[i], elementos[j]);
    }
    swap(elementos[i], elementos[high - 1]);  // Coloca el pivote en su lugar
    return i;
}

void quickSort(vector<int>& elementos, int low, int high) {
    if (low < high) {
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
    auto startChrono = chrono::high_resolution_clock::now();
    quickSort(elementos, 0, elementos.size() - 1);
    auto endChrono = chrono::high_resolution_clock::now();

    cout << "Elementos ordenados con exito!" << endl;

    auto durationMicrosegundos = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();

    auto tiempoMilisegundos = durationMicrosegundos / 1e3;

    cout << "Tiempo de ejecucion: " << durationMicrosegundos << " microsegundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoMilisegundos << " milisegundos" << endl;





    return 0;
}
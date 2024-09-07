#include "iostream"
#include "fstream"
#include "string"
#include "cstdlib"
#include "ctime"
#include "vector"
#include <algorithm>
#include <random>
using namespace std;

void generatePartiallySortedDataset(int n, std::ofstream& file) {
    std::vector<int> data(n);
    double sortedPercentage = 0.5; // Change this value as desired

    int sortedElements = static_cast<int>(n * sortedPercentage);

    // Generate the completely sorted dataset
    for (int i = 0; i < n; ++i) {
        data[i] = i + 1; // Or any other value you prefer
    }

    // Shuffle the elements after the sorted range
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(data.begin() + sortedElements, data.end(), g);

    // Write the elements to the file
    for (int i = 0; i < n; ++i) {
        file << data[i] << endl;
    }
}

int main(){


    int opcion;
    long long int n;
    cout << "Seleccione el tipo de dataset que desea generar: " << endl;
    cout << "Ordenado (1)" << endl;
    cout << "Completamente desordenado (2)" << endl;
    cout << "Parcialmente Ordenados (3)" << endl;
    cout << "Orden inverso (4)" << endl;

    cin >> opcion;

    cout << "Ingrese el tamaño de su dataset: ";
    cin >> n;

    srand(time(0));

    ofstream MyFile("dataSet.txt");

    if (opcion == 1){
        for (int i = 0; i < n; i++){
            MyFile << i << endl;
        }
    }else if (opcion == 2){
        for (int i = 0; i < n; i++){
            MyFile << rand() % 1000000 << endl;
        }
    }else if (opcion == 3){
        generatePartiallySortedDataset(n, MyFile);
    }else if (opcion == 4){
        for (int i = n; i > 0; i--){
            MyFile << i << endl;
        }
    }

    MyFile.close();

    cout << "Dataset generado con exito!" << endl;

}
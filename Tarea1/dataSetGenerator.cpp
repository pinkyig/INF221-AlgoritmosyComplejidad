#include "iostream"
#include "fstream"
#include "string"
#include "cstdlib"
#include "ctime"

using namespace std;

int main(){
    double n;
    ofstream MyFile("dataSet.txt");
    cout << "Ingrse la cantidad de elementos que desea en su dataset: ";
    cin >> n;

    srand(time(0)); // semilla para generar numeros aleatorios

    for (int i = 0; i < n; i++){
        MyFile << rand() % 1000000 << endl; 
    }
    cout << "Dataset generado con exito!" << endl;
    MyFile.close();
}
#include "iostream"
#include "string"
#include "vector"
#include "fstream"
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

    ofstream MyFile("dataSetOrdenado.txt");

    vector<int> elementos;
    elementos = pobladorVector(elementos);

    bubbleSort(elementos);
    cout << "Elementos ordenados con exito!" << endl;

    for (int i = 0; i < elementos.size(); i++){
        
        MyFile << elementos[i] << endl;
    }
    MyFile.close();



}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

// Función para calcular el peor caso de suma de índices
int calcularPeorCaso(vector<int> A, vector<int> B) {
    int indiceA = 0;
    int indiceB = 100;
    int peorCaso = 0;
    bool flag = false;

    while (true) {
        // Encuentra el siguiente índice no vacío en A
        while (indiceA <= 100 && A[indiceA] == 0) {
            indiceA++;
        }
        if (indiceA > 100) {
            flag = true;
            break;
        }

        // Encuentra el siguiente índice no vacío en B
        while (indiceB >= 0 && B[indiceB] == 0) {
            indiceB--;
        }
        if (indiceB < 0) {
            flag = true;
            break;
        }

        // Calcula el peor caso actual
        peorCaso = max(peorCaso, indiceA + indiceB);

        // Resta la cantidad mínima entre A[indiceA] y B[indiceB]
        int minimo = min(A[indiceA], B[indiceB]);
        A[indiceA] -= minimo;
        B[indiceB] -= minimo;
    }

    return peorCaso;
}

int main() {
    int n;
    cin >> n;

    //Rango 100 ya que sabmos por el ununciado que es el maximo rango
    vector<int> A(101, 0); 
    vector<int> B(101, 0);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A[a]++;
        B[b]++;
        cout << calcularPeorCaso(A, B) << endl;
    }
}

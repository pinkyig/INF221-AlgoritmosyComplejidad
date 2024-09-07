#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

//Funcion pobladora de matrices cuadradas
vector<vector<int> > pobladorMatriz(vector<vector<int> > matriz, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matriz[i][j] = rand() % 100;
        }
    }
    return matriz;
}

void printMatriz(vector<vector<int> > matriz, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}




int main(){

    int n;

    //obteniendo el tamaño de la matriz cuadrada leyendo el archivo
    ifstream MyFile("dataSetMatriz.txt");
    MyFile >> n;
    MyFile.close();

    cout << "Tamaño de la matriz cuadrada: " << n << endl;

    srand(time(0)); // semilla para generar números aleatorios

    vector<vector<int> > matrizA(n, vector<int>(n));
    matrizA = pobladorMatriz(matrizA, n);

    vector<vector<int> > matrizB(n, vector<int>(n));
    matrizB = pobladorMatriz(matrizB, n);

    auto startChrono = chrono::high_resolution_clock::now();
    //Dividir la matriz en 4 submatrices
    vector<vector<int> > A11(n/2, vector<int>(n/2));
    vector<vector<int> > A12(n/2, vector<int>(n/2));
    vector<vector<int> > A21(n/2, vector<int>(n/2));
    vector<vector<int> > A22(n/2, vector<int>(n/2));

    vector<vector<int> > B11(n/2, vector<int>(n/2));
    vector<vector<int> > B12(n/2, vector<int>(n/2));
    vector<vector<int> > B21(n/2, vector<int>(n/2));
    vector<vector<int> > B22(n/2, vector<int>(n/2));

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            A11[i][j] = matrizA[i][j];
            A12[i][j] = matrizA[i][j + n/2];
            A21[i][j] = matrizA[i + n/2][j];
            A22[i][j] = matrizA[i + n/2][j + n/2];

            B11[i][j] = matrizB[i][j];
            B12[i][j] = matrizB[i][j + n/2];
            B21[i][j] = matrizB[i + n/2][j];
            B22[i][j] = matrizB[i + n/2][j + n/2];
        }
    }

    //calcular las 7 multiplicaciones de Strassen
    vector<vector<int> > C(n, vector<int>(n));

    vector<vector<int> > M1(n/2, vector<int>(n/2));
    vector<vector<int> > M2(n/2, vector<int>(n/2));
    vector<vector<int> > M3(n/2, vector<int>(n/2));
    vector<vector<int> > M4(n/2, vector<int>(n/2));
    vector<vector<int> > M5(n/2, vector<int>(n/2));
    vector<vector<int> > M6(n/2, vector<int>(n/2));
    vector<vector<int> > M7(n/2, vector<int>(n/2));


    //M1 = (A11 + A22) * (B11 + B22)

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            int sum = 0;
            for (int k = 0; k < n/2; k++){
                sum += (A11[i][k] + A22[i][k]) * (B11[k][j] + B22[k][j]);
            }
            M1[i][j] = sum;
        }
    }

    //M2 = (A21 + A22) * B11

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            int sum = 0;
            for (int k = 0; k < n/2; k++){
                sum += (A21[i][k] + A22[i][k]) * B11[k][j];
            }
            M2[i][j] = sum;
        }
    }

    //M3 = A11 * (B12 - B22)

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            int sum = 0;
            for (int k = 0; k < n/2; k++){
                sum += A11[i][k] * (B12[k][j] - B22[k][j]);
            }
            M3[i][j] = sum;
        }
    }

    //M4 = A22 * (B21 - B11)

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            int sum = 0;
            for (int k = 0; k < n/2; k++){
                sum += A22[i][k] * (B21[k][j] - B11[k][j]);
            }
            M4[i][j] = sum;
        }
    }

    //M5 = (A11 + A12) * B22

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            int sum = 0;
            for (int k = 0; k < n/2; k++){
                sum += (A11[i][k] + A12[i][k]) * B22[k][j];
            }
            M5[i][j] = sum;
        }
    }

    //M6 = (A21 - A11) * (B11 + B12)

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            int sum = 0;
            for (int k = 0; k < n/2; k++){
                sum += (A21[i][k] - A11[i][k]) * (B11[k][j] + B12[k][j]);
            }
            M6[i][j] = sum;
        }
    }

    //M7 = (A12 - A22) * (B21 + B22)

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            int sum = 0;
            for (int k = 0; k < n/2; k++){
                sum += (A12[i][k] - A22[i][k]) * (B21[k][j] + B22[k][j]);
            }
            M7[i][j] = sum;
        }
    }

    //Calcular las submatrices C

    //C11 = M1 + M4 - M5 + M7
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
        }
    }

    //C12 = M3 + M5

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            C[i][j + n/2] = M3[i][j] + M5[i][j];
        }
    }

    //C21 = M2 + M4

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            C[i + n/2][j] = M2[i][j] + M4[i][j];
        }
    }

    //C22 = M1 - M2 + M3 + M6

    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            C[i + n/2][j + n/2] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    auto endChrono = chrono::high_resolution_clock::now();
    cout << "Matriz multiplicada con exito!" << endl;

    auto durationMicrosegundos = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();
    auto tiempoMilisegundos = durationMicrosegundos / 1e3;

    cout << "Tiempo de ejecucion: " << durationMicrosegundos << " microsegundos" << endl;
    cout << "Tiempo de ejecucion: " << tiempoMilisegundos << " milisegundos" << endl;

    return 0;
}

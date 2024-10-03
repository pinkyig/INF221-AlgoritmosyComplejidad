#include <iostream>
#include <vector>

using namespace std;

uint8_t* arregloDescriptador() {
    uint8_t* arr = new uint8_t[257];
    for (int i = 0; i < 256; i++) {
        arr[(uint8_t)(i ^ (i << 1))] = i;
    }
    return arr;
}

void imprimirArreglo(int n, uint8_t* arrayDesencripador) {
    
    for (int i = 0; i < n; i++) {
        int byteEncriptado;
        cin >> byteEncriptado; 
        cout << (int)arrayDesencripador[byteEncriptado]<< " ";
    }
}

int main() {
    //Inicializando arreglo que asocia el byte encriptado con el byte desencriptado
    uint8_t* arrayDesencripador = arregloDescriptador();

  
    int n;
    cin >> n;

    imprimirArreglo(n, arrayDesencripador);
    cout << endl;

    return 0;
}

#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



deque<int> decodificador(const string& elementos) {

    deque<int> elementosInt;
    string numero = "";

    //Verifica si el string esta vacio(largo 2 --> [])
    if (elementos.size() == 2) {
        return elementosInt;
    }

    for (int i = 1; i < elementos.size(); i++) {
        if (elementos[i] == ',' || elementos[i] == ']') {
            elementosInt.push_back(stoi(numero));
            numero = "";
        } else {
            numero += elementos[i];
        }
    }

    return elementosInt;
}

void BAPC(){

    bool reverso = 1;

    string funciones;
    cin >> funciones;

    int numeroElementos;
    cin >> numeroElementos;

    string elementos;
    cin >> elementos;

    deque <int> elementosInt = decodificador(elementos);

    for (int i = 0; i < funciones.size(); i++){
        if (funciones[i] == 'R'){
            reverso = !reverso; //Cambia el valor de reverso a su opuesto
        }else if (funciones[i] == 'D'){
            //Si el vector esta vacio
            if (elementosInt.empty()){
                cout << "error" << endl;
                return;
            }else if (reverso){
                elementosInt.pop_front();
              
            }else{
                elementosInt.pop_back();
            }
        }

    }

    if (!reverso){
        cout << "[";
        for (int i = elementosInt.size() - 1; i >= 0; i--){
            cout << elementosInt[i];
            if (i != 0){
                cout << ",";
            }
        }
        cout << "]" << endl;
    }else{
        cout << "[";
        for (int i = 0; i < elementosInt.size(); i++){
            cout << elementosInt[i];
            if (i != elementosInt.size() - 1){
                cout << ",";
            }
        }
        cout << "]" << endl;
    }


}

int main(){

    int iteraciones;
    cin >> iteraciones;

    while (iteraciones > 0){
        BAPC();
        iteraciones--;
    }
}

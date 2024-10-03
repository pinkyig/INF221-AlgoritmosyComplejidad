#include <iostream>
#include <list>
#include <string>

using namespace std;

void procesadorCadena(string cadena) {

    list<char> resultado;
    auto iterador = resultado.begin();

    //Recorriendo el string caracter por caracter
    for (char caracter : cadena) {
        if (caracter == '<'){
            if (iterador == resultado.begin()) {
                continue;
            }
            --iterador;
            iterador = resultado.erase(iterador);
        }else if (caracter == '[') {
            iterador = resultado.begin();
        }else if (caracter == ']') {
            iterador = resultado.end();
        }else {
            iterador = resultado.insert(iterador, caracter);
            ++iterador;
        }
    }

    string resultadoFinal(resultado.begin(), resultado.end());
    cout << resultadoFinal<< endl;
}

int main() {
 
    int TotalCasos;
    cin >> TotalCasos;
    cin.ignore();
    
    while (TotalCasos > 0) {
        string cadena;
        getline(cin, cadena);        
        procesadorCadena(cadena);
        TotalCasos--;
    }
}
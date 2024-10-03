#include "iostream"
#include "vector"
#include "string"
#include "map"

using namespace std;

void Srednji(int numeroElementos, int valorMediana){

    int posMediana = 0;
    vector<int> elementos(numeroElementos);

    //poblando el vector con  los elementos y guardando la posición de la mediana
    for (int i = 0; i < numeroElementos; i++){
        cin >> elementos[i];
        if (elementos[i] == valorMediana){
            posMediana = i;
        }
    }

    //Recorriendo a la izquierda de la mediana y guardando la diferencia de los elementos con la mediana
	map<int, int> m;
	int diff = 0;
	m[0] = 1;

    for (int i = posMediana - 1; i >= 0; i--) {
        diff += (elementos[i] < valorMediana) ? -1 : 1;
        m[diff]++;
    }
    
    //Recorriendo a la derecha de la mediana y sumando los valores de la diferencia de los elementos con la mediana
    diff = 0;
    int result = m[0];
    for (int i = posMediana + 1; i < numeroElementos; i++) {
        diff += (elementos[i] < valorMediana) ? -1 : 1;
        result += m[-diff];
    }

    cout << result << endl;



}

 
int main(){

    int N,B;
    cin >> N >> B;

    Srednji(N,B);

    return 0;

}
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;



int altruaMaximaSalto(int n, vector<int> alturaMontanias){

    int saltoMaximo = 0;

    //Algoritmo que busca crear el salto con mayor altura sin puentes entre montañas más altas
    for (int i = 0; i < n; i++){

        if (alturaMontanias[i] > alturaMontanias[i+1]){
            
            for (int j = i+2; j < n; j++){

                if (alturaMontanias[j] > alturaMontanias[i]){

                    for (int k = i + 1; k < j; k++) {

                        saltoMaximo = max(saltoMaximo, min(alturaMontanias[i], alturaMontanias[j]) - alturaMontanias[k]);

                    }

                }
    
            }
            
        }
    }

    return saltoMaximo;

}




int main() {
    int totalMontanias;
    vector<int> montanias;

    cin >> totalMontanias;
    cin.ignore(); 



    string alturaMontanias;
    getline(cin, alturaMontanias);
    stringstream ss(alturaMontanias);

    for (int i = 0; i < totalMontanias; i++) {
        int altura;
        ss >> altura;
        montanias.push_back(altura);
    }


    int saltoMaximo = altruaMaximaSalto(totalMontanias, montanias);
    cout << saltoMaximo << endl;
    

    return 0;
}

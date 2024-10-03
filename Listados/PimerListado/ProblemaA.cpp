#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;



int HuevoPosicionFinal(int n, int k, vector <string> comandos){
    int poscicionActual = 0;
    vector <int> historial;

    for (int i = 0; i < k; i++){

        if(comandos[i].substr(0, 4) == "undo"){
            int m = stoi(comandos[i].substr(5));
            //Eliminando los últimos m elementos del historial
            historial.erase(historial.end() - m, historial.end());
            poscicionActual = historial.back();
            

        }else{
            int Pases = stoi(comandos[i]);

            if (Pases < 0){
                Pases = (Pases % n + n) % n;
            }
            
            poscicionActual = (poscicionActual + Pases) % n;
            historial.push_back(poscicionActual);           
        } 


        
    }

    return poscicionActual;

}

int main() {
    int n, k;
    cin >> n >> k;


    vector<string> comandos(k);

    // Recibiendo el segundo input con todos los comandos en una sola linea
    cin.ignore();
    string comando;
    getline(cin, comando);
    stringstream ss(comando);

    for (int i = 0; i < k; i++) {
        ss >> comandos[i];
        if (comandos[i] == "undo") {
            int m;
            ss >> m;
            comandos[i] += " " + to_string(m);
        }
    }

    int poscicionFinal = HuevoPosicionFinal(n, k, comandos);
    cout << poscicionFinal<<endl;
    return 0;
}
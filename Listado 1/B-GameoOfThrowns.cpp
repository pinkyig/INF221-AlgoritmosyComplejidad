#include <iostream>
#include <vector>
#include <string>

using namespace std;




int main(){


    int n, k;
    cin >> n >> k;

    

    vector<int> posiciones = {0};
    int poscicionActual = 0;
    int pases;

    while (k--){
        string instruccion;
        cin >> instruccion;

        if (instruccion == "undo"){
            int x;
            cin >> x;
            //Borrando los ultimos x elementos del vector
            posiciones.erase(posiciones.end() - x, posiciones.end());
            poscicionActual = posiciones.back();
            continue;
        }

        pases = stoi(instruccion);

        if (stoi(instruccion) < 0){
            pases = (pases % n + n) % n;
        }

        poscicionActual = (poscicionActual + pases) % n;

        posiciones.push_back(poscicionActual);
    }

    cout << posiciones.back() <<endl;


    return 0 ;
}
#include <iostream>
#include <vector>
using namespace std;


int main(){

    int obstaculosTotales, obstaculosEncontrados;
    vector <int> obstaculosPeligrosos;

    cin >> obstaculosTotales >> obstaculosEncontrados;

    for (int i = 0; i<obstaculosEncontrados; i++){
        int obstaculo;
        cin >> obstaculo;

        if (find(obstaculosPeligrosos.begin(), obstaculosPeligrosos.end(), obstaculo) == obstaculosPeligrosos.end()){
            obstaculosPeligrosos.push_back(obstaculo);
        }
        
    
    }

    for (int i = 0; i < obstaculosTotales; i++){
        if (find(obstaculosPeligrosos.begin(), obstaculosPeligrosos.end(), i) == obstaculosPeligrosos.end()){
            cout << i <<endl;
        }
    }

    cout <<  "Mario got " << obstaculosPeligrosos.size() << " of the dangerous obstacles." << endl;

}
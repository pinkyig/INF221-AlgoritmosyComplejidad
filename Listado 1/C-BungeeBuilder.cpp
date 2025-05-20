#include <iostream>
#include <map>
#include <vector>



using namespace std;



void maxJumpingDistance(int montainNumber, vector<int>& montains) {
    vector<int> left(montainNumber, 0);
    vector<int> right(montainNumber, 0);

    // Encuentra la montaña más alta a la izquierda de cada montaña
    left[0] = montains[0];
    for (int i = 1; i < montainNumber; i++) {
        left[i] = max(left[i - 1], montains[i]);
    }

    // Imprime el vector left
    cout << "Vector left: ";
    for (int i = 0; i < montainNumber; i++) {
        cout << left[i] << " ";
    }
    cout << endl;

    // Encuentra la montaña más alta a la derecha de cada montaña
    right[montainNumber - 1] = montains[montainNumber - 1];
    for (int i = montainNumber - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], montains[i]);
    }

    // Imprime el vector right
    cout << "Vector right: ";
    for (int i = 0; i < montainNumber; i++) {
        cout << right[i] << " ";
    }
    cout << endl;

    // Calcular la distancia máxima de salto
    int maxDistance = 0;
    for (int i = 1; i < montainNumber - 1; i++) {
        int minHeight = min(left[i - 1], right[i + 1]);
        cout << "Viendo montaña "<< i+1 <<endl;
        if (minHeight > montains[i]) {
            maxDistance = max(maxDistance, minHeight - montains[i]);
            cout << maxDistance <<endl;

        }
    }

    //cout<< maxDistance << endl;
}




int main(){


    int montainNumber,height;
    cin >> montainNumber;

    vector<int> montains(montainNumber);

    for (int i = 0; i < montainNumber; i++) {
        cin >> montains[i];
    }

    maxJumpingDistance(montainNumber, montains);



    return 0;
}
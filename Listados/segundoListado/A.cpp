#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void heightOrdering(){

    //Leyendo la entrada de altura 
    string input;
    vector<int> alturas;

    getline(cin, input);
    stringstream ss(input);
    int height;
    while (ss >> height) {
        alturas.push_back(height);
    }

    //Contando cantidad de swaps
    int swaps = 0;
    for (int i = 1; i < alturas.size(); i++){
        for (int j = i + 1; j < alturas.size(); j++){
            if (alturas[i] > alturas[j]){
                swaps++;
            }
        }
    }

    cout << alturas[0] << " " << swaps << endl;

}

int main(){

    int n;
    cin >> n;
    cin.ignore();

    while (n > 0){
        heightOrdering();
        n--;
    }

    return 0;
}
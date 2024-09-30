#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool compararApellidos(const string &a, const string &b) {
    return a.substr(0, 2) < b.substr(0, 2);
}

int main(){
    
    while (true){
        int n;
        cin >> n;

        vector<string> apellidos;
        if (n == 0){
            break;
        }

        for (int i = 0; i < n; i++){
            string apellido;
            cin >> apellido;
            apellidos.push_back(apellido);
        }

        stable_sort(apellidos.begin(), apellidos.end(), compararApellidos);
        for (const string& apellido : apellidos) {
            cout << apellido << endl;
        }
        cout << endl;
    
    }
    return 0;
}
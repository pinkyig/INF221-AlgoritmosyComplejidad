#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//Lamnda function to sort the lastname by the first 2 caracters

bool compareString(string a, string b){

    return (a.substr(0,2) < b.substr(0,2));

}



int main(){


    int n;

    while (n != 0){

        string apellido;
        vector<string> lastNames;
        cin >> n;



        for(int i=0; i<n ;i++){
            cin >>apellido;
            lastNames.push_back(apellido);
        }

    stable_sort(lastNames.begin(),lastNames.end(),compareString);
    
        for (const auto& name : lastNames) {
            cout << name << endl;
        }
    }

    return 0;
}

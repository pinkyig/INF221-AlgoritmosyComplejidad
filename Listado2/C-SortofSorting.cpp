#include <iostream>
#include <vector>
#include <string>
using namespace std;


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

    stable_sort(lastNames.begin(),lastNames.end());

    cout <<"Nombres ordenamos sin key"<<endl;
    for (const auto& name : lastNames) {
        cout << name << endl;
    }
    
    
    }



    return 0;
}
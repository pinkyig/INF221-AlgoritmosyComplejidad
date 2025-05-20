#include <iostream>
#include <vector>
#include <string>
#include <set>



using namespace std;


int main(){

    int n, y,obstaculo;
    set <int> obstaculosMarioSaid;

    cin >> n >> y;

    while (y--){
        cin >>obstaculo;
        obstaculosMarioSaid.insert(obstaculo);
    }

    //Printeando valores desde 0 hasta N-1 omitiendo los valores del set
    for (int i = 0; i < n; ++i) {
        if (obstaculosMarioSaid.find(i) == obstaculosMarioSaid.end()) {
            cout << i << endl;
        }
    }

    cout <<"Mario got "<< obstaculosMarioSaid.size() <<" of the dangerous obstacles." <<endl;


    return 0;
}




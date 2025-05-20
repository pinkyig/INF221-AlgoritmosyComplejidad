#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;


int HeightOrdering(vector<int> alturas){

    int steps=0;

    //Seleccionamos la key 
    for(int i = 1 ; i < alturas.size() ; i++){
        int key = alturas[i];
        int j = i-1;


        while(j>=0 && key < alturas[j]){

            alturas[j + 1] = alturas[j];
            steps++;
            --j;
        }
    
        alturas[j + 1] = key;
    }

    return steps;

}


int main(){

    int n,steps,num;
    string dataset;
    vector<int> nums;

    cin >> n;
    cin.ignore();

    while (n > 0){

        vector<int> nums;

        getline(cin, dataset);

        istringstream iss(dataset);

        int x;
        bool skipFirst = true;
        while (iss >> x) {
            if (skipFirst) {
            num = x;
            skipFirst = false;
            continue;
            }
            nums.push_back(x);
        }

        //LLamando a la funcion 
        steps=HeightOrdering(nums);
        cout << num << " "<< steps <<endl;

        n--;

    }



    return 0;
}



#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;




void procesadorPlabra(string palabra){

    list <char> resultado;
    auto iterator = resultado.begin();

    for (auto character: palabra){
        
        // Caso '<'
        if (character == '<'){

            //Si el cursor esta al principio del todo no haremos nada
            if (iterator == resultado.begin())
                continue;

            --iterator;
            iterator = resultado.erase(iterator);

        }else if(character =='['){
            
            iterator = resultado.begin();

        }else if(character ==']'){

            iterator = resultado.end();

        }else{

        iterator = resultado.insert(iterator, character);
        ++iterator;
        }

    }

    string resultadoFinal(resultado.begin(), resultado.end());
    cout << resultadoFinal<< endl;

}

int main(){

    int numCasos;
    string palabra;

    cin >> numCasos;
    cin.ignore();

    while (numCasos--){

        getline(cin,palabra);
        procesadorPlabra(palabra);
        
        
    }

    return 0;

}



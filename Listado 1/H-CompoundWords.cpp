#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>



using namespace std;




int main(){

    string input,line;
    vector<string> tokens;

    while (getline(cin, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            tokens.push_back(word);
        }
    }

    //Combinando palabras
    set<string> compoundWords;

    for (size_t i = 0; i < tokens.size(); ++i) {
        for (size_t j = 0; j < tokens.size(); ++j) {
            if (i != j) {
                compoundWords.insert(tokens[i] + tokens[j]);
            }
        }
    }

    // Imprimir las palabras compuestas
    for (const auto& word : compoundWords) {
        cout << word << endl;
    }


    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <deque>


using namespace std;


deque<int> parseArrayString(const string& s) {
    deque<int> result;
    string num;

    for (char c : s) {
        if (isdigit(c)) {
            num += c;
        } else if (!num.empty()) {
            result.push_back(stoi(num));
            num.clear();
        }
    }

    return result;
}

void printDeque(const deque<int>& deq, int reverse) {

    if (deq.empty()) {
        cout << "[]" << endl;
        return;
    }

    cout << "[";
    if (reverse == 1) {
        for (auto it = deq.rbegin(); it != deq.rend(); ++it) {
            cout << *it;
            if (it + 1 != deq.rend()) cout << ",";
        }
    } else {
        for (auto it = deq.begin(); it != deq.end(); ++it) {
            cout << *it;
            if (it + 1 != deq.end()) cout << ",";
        }
    }
    cout << "]" << endl;
}



void BAPC(){

    int reverse = 0;

    string functions;
    cin >> functions;

    int arrayLength;
    cin >> arrayLength;

    string stringArray;
    cin >>stringArray;

    deque <int> numbers = parseArrayString(stringArray);

    for (char function : functions) {

        if (function == 'R') {
            reverse = !reverse;
        } else if (function == 'D') {
            if (numbers.empty()) {
                cout << "error" << endl;
                return;
            }

            if (reverse == 1) {
                numbers.pop_back();
            } else {
                numbers.pop_front();
            }
        }

    }


    printDeque(numbers, reverse);



}



int main(){

    int cases;
    cin >>cases;

    while (cases--){
        BAPC();
    }

    return 0;
}
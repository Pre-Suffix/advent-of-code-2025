#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) {
        cerr << "Not enough arguments.\n";
        return 1;
    }

    ifstream test(argv[1]);
    if(!test.is_open()) {
        cerr << "Invalid file path.\n";
        return 1;
    }

    string line;
    while(getline(test, line, '\n')) {
        /* CODE HERE */
    }

    return 0; 
}
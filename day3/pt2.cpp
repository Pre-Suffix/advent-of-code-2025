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

    ll totalJoltage = 0;

    string line;
    while(getline(test, line, '\n')) {
        int batteryCount = line.size();
        ll totalSubJoltage = 0;
        pair<ll, int> lastHighJolt = {0, -1};
    
        for(ll n = 11; n >= 0; n--) {
            pair<ll, int> highJolt = {0, 0};

            for(int i = lastHighJolt.second + 1; i < batteryCount - n; i++) {
                if(line[i] - '0' <= highJolt.first) continue;

                highJolt.first = line[i] - '0';
                highJolt.second = i;
            }


            lastHighJolt = highJolt;
            totalSubJoltage += pow(10, n) * highJolt.first;
        }

        cout << totalSubJoltage << '\n';
        totalJoltage += totalSubJoltage;
    }

    cout << "\nTotal Joltage: " << totalJoltage << endl;

    return 0; 
}
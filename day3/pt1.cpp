#include <bits/stdc++.h>

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

    int totalJoltage = 0;

    string line;
    while(getline(test, line, '\n')) {
        int batteryCount = line.size();
        pair<int, int> highJolt = {0, 0};
        int sHighJolt = 0;

        for(int i = 0; i < batteryCount - 1; i++) {
            if(line[i] - '0' <= highJolt.first) continue;

            highJolt.first = line[i] - '0';
            highJolt.second = i;
        }

        for(int i = highJolt.second + 1; i < batteryCount; i++) {
            if(line[i] - '0' <= sHighJolt) continue;

            sHighJolt = line[i] - '0';
        }
        
        cout << 10 * highJolt.first + sHighJolt << '\n';

        totalJoltage += 10 * highJolt.first + sHighJolt;
    }

    cout << "\nTotal Joltage: " << totalJoltage << endl;

    return 0; 
}
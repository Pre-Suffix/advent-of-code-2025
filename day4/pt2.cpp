#include <bits/stdc++.h>

using namespace std;

unsigned char *rollMatrix[256];

void changeVicinity(int x, int y, int mx, int my, int sum) {
    if(x != 0) {
        if(y != 0) rollMatrix[y-1][x-1] += sum;
        rollMatrix[y][x-1] += sum;
        if(y < my-1) rollMatrix[y+1][x-1] += sum;
    }

    if(y != 0) {
        rollMatrix[y-1][x] += sum;
        if(x < mx-1) rollMatrix[y-1][x+1] += sum;
    }

    if(y < my-1) {
        rollMatrix[y+1][x] += sum;
        if(x < mx-1) rollMatrix[y+1][x+1] += sum;
    }

    if(x < mx-1) rollMatrix[y][x+1] += sum;
}

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

    for(int i = 0; i < 256; i++) {
        rollMatrix[i] = new unsigned char[256]();
    }

    string line;
    vector<string> rows;
    while(getline(test, line, '\n')) rows.emplace_back(line);

    int rowCount = (int) rows.size();
    for(int y = 0; y < rowCount; y++) {
        int colCount = (int) rows[y].size();
        for(int x = 0; x < colCount; x++) {
            if(rows[y][x] == '.') continue;

            changeVicinity(x, y, colCount, rowCount, 1);
        }
    }

    int totalRolls = 0;
    while(true) {
        int startRolls = totalRolls;

        for(int y = 0; y < rowCount; y++) {
            int colCount = (int) rows[y].size();
            for(int x = 0; x < colCount; x++) {
                if(rows[y][x] == '.') continue;
                if(rollMatrix[y][x] >= 4) continue;

                rows[y][x] = '.';
                totalRolls++;
                changeVicinity(x, y, colCount, rowCount, -1);
            }
        }

        if(startRolls == totalRolls) break;
    }

    cout << "\n\n" << totalRolls << '\n';

    return 0; 
}
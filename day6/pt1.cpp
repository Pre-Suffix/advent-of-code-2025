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
    vector<string> lines;
    while(getline(test, line, '\n'))
        lines.emplace_back(string(line));

    int lastIndex = 0, lineSize = (int) line.size(), linesSize = (int) lines.size();
    ll total = 0;

    for(int i = 1; i < lineSize; i++) {
        if(i != lineSize - 1) {
            bool valid = true;
            for(int j = 0; j < linesSize - 1; j++) {
                if(lines[j][i] == ' ') continue;

                valid = false;
                break;
            }

            if(!valid) continue;
        } else i++;

        char op = line[lastIndex];
        ll subTotal = 0;
        for(int lin = 0; lin < linesSize - 1; lin++) {
            int num = atoi(&(lines[lin].c_str())[lastIndex]);

            if(subTotal == 0) subTotal = num;
            else if(op == '*') subTotal *= num;
            else subTotal += num;
        }

        total += subTotal;
        lastIndex = i + 1;
    }

    cout << total << '\n';

    return 0; 
}
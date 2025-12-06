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

    int rotation = 50;
    int zerocount = 0;

    string line;
    while(getline(test, line, '\n')) {
        const char *line_c = line.c_str();
        int rotate = atoi(&line_c[1]);
        if(line_c[0] == 'R') {
            rotation += rotate;
            rotation = rotation % 100;
        } else {
            rotation -= rotate;
            rotation = rotation % 100;
            if(rotation < 0) rotation += 100;
        }

        if(rotation == 0) zerocount++;
    }

    cout << zerocount << endl;

    return 0; 
}
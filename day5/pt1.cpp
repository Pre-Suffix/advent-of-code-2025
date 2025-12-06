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
    bool inRanges = true;

    vector<pair<ll, ll>> ranges;
    ll count = 0;

    while(getline(test, line, '\n')) {
        if(line.length() == 0) {
            inRanges = false;
            continue;
        } else if(inRanges) {
            ranges.emplace_back(atoll(line.c_str()), atoll(&line.c_str()[line.find('-') + 1]));
            continue;
        }

        for(auto x : ranges) {
            ll num = atoll(line.c_str());
            if(x.first <= num && x.second >= num) {
                count++;
                break;
            }
        }
    }  

    cout << count << '\n';

    return 0; 
}
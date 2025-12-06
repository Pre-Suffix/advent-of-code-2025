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

    vector<pair<ll, ll>> ranges;
    ll count = 0;

    while(getline(test, line, '\n')) {
        if(line.length() == 0) break;
        ranges.emplace_back(atoll(line.c_str()), atoll(&line.c_str()[line.find('-') + 1]));
    }

    int rangesSize = (int) ranges.size();
    
    while(true) {
        bool changed = false;
        for(int i = 0; i < rangesSize - 1; i++) {
            if(ranges[i].first == -1) continue;
            for(int j = i + 1; j < rangesSize; j++) {
                if(ranges[j].first == -1) continue;
                if(ranges[i].first > ranges[j].second || ranges[i].second < ranges[j].first) continue;

                changed = true;

                ranges[i].first = min(ranges[i].first, ranges[j].first);
                ranges[i].second = max(ranges[i].second, ranges[j].second);

                ranges[j].first = -1;
            }
        }

        if(!changed) break;
    }

    for(auto x : ranges) {
        if(x.first == -1) continue;
        count += x.second - x.first + 1;
    }

    cout << count << '\n';

    return 0; 
}
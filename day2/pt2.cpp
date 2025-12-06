#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool repeats(ll _num) {
    string num = to_string(_num);
    int length = (int) num.size();

    for(int i = 1; i < length; i++) {
        if(length % i != 0) continue;
        string rep = num.substr(0, i);
        string comp = "";
        for(int j = 0; j < length / i; j++) comp.append(rep);

        if(num == comp) return true;
    }

    return false;
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

    ll invalidIdSum = 0;
    ll start, end;

    while(!test.eof()) {
        test >> start >> end;

        cout << '(' << start << '-' << end << ")\n";

        for(ll i = start; i <= end; i++) {
            if(!repeats(i)) continue;

            cout << i << '\n';
            invalidIdSum += i;
        }
    }

    cout << invalidIdSum << '\n';

    return 0; 
}
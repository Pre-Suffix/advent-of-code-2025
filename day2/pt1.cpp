#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll powers_10[] = {1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000};

int nl(ll num) {
    double n = num;
    return (ll) floor(log10(max(n, 1.0))) + 1LL;
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
        ll nl_s = nl(start), nl_e = nl(end);

        cout << '(' << start << '-' << end << ")\n";

        if(nl_s % 2 == 1 && nl_e % 2 == 1 && nl_s == nl_e) continue;
        
        ll base, mult;
        if(nl_s % 2 == 0) {
            base = powers_10[nl_s / 2] + 1LL;
            mult = powers_10[(nl_s / 2) - 1];

            while(base*mult < start) mult++;
        } else {
            nl_s++;

            base = powers_10[nl_s / 2] + 1LL;
            mult = powers_10[(nl_s / 2) - 1];
        }
        cout << "b: " << base << " m: " << mult << " b*m: " << base*mult << '\n';

        while(base*mult <= end) {
            cout << base*mult << '\n';
            invalidIdSum += base*mult;
            mult++;

            for(int i = 1; i < 13; i++) {
                if(mult == powers_10[i])
                    goto increase_base;
            }

            continue;
            increase_base:
            nl_s++;

            base = powers_10[nl_s - 1] + 1LL;
            mult = powers_10[nl_s - 2];
        }
    }

    cout << invalidIdSum << '\n';

    return 0; 
}
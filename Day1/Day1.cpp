#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
#define ll long long


int main() {
    freopen("input.txt", "r", stdin);
    vector<ll> v;
    ll input;
    while(cin >> input){
        v.push_back(input);
    }
    //part 1
    ll sum = 0;

    for(auto& x : v){
        sum += std::max(x / 3 - 2, (ll) 0);
        x = x / 3 - 2;
    }
    cout << "original required fuel: " << sum << endl;
    //part 2
    for(ll x: v){
        while((x = x / 3 - 2) > 0){
            sum += x;
        }
    }
    cout << "final required fuel: " << sum << endl;

    return 0;
}
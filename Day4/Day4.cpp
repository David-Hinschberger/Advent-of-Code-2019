#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
//    string input ("347312-805915");

    ull min = 347312;
    ull max = 805915;
    //part1
    ull count = 0;
    for (auto i = min; i <= max; i++) {
        bool adjacent = false;

        string str_rep = to_string(i);
        for (int j = 0; j < 5; j++) {
            int a = str_rep[j] - '0';
            int b = str_rep[j + 1] - '0';
            if (a > b) {
                adjacent = false;
                break;
            }
            if (a == b) {
                adjacent = true;
            }
        }
        if (adjacent) {
            count++;
        }
    }
    cout << "part1: " << count << endl;

    //part2
    count = 0;
    for (auto i = min; i <= max; i++) {
        bool valid = false;
        int seen[10] {};
        string str_rep = to_string(i);
        for (int j = 0; j < 5; j++) {
            int a = str_rep[j] - '0';
            int b = str_rep[j + 1] - '0';
            if (a > b) {
                valid = false;
                break;
            }
            if (a == b) {
                valid = true;
            }
            seen[a]++;
        }
        seen[str_rep[5] - '0']++;
        if(valid && any_of(&seen[0], &seen[10], [](int i){ return i == 2;})){
            count++;
        }
    }
    cout << "part2: " << count << endl;

    return 0;
}
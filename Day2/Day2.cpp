#include <bits/stdc++.h>

#define ull unsigned long long
using namespace std;

ull run(vector<ull> v) {
    int index = 0;
    while (index < v.size() && v[index] != 99) {
        switch (v[index]) {
            case 1:
                //add
                v[v[index + 3]] = v[v[index + 1]] + v[v[index + 2]];
                break;
            case 2:
                //multiply
                v[v[index + 3]] = v[v[index + 1]] * v[v[index + 2]];
                break;
            default:
                //error
                cout << "invalid opcode: " << v[index] << endl;
                exit(-1);
        }
        index += 4;
    }
    return index >= v.size() ? -1 : v[0];
}

int main() {
    //part 1
    freopen("input.txt", "r", stdin);
    vector<ull> original;
    string line;
    while (getline(cin, line, ',')) {
        original.push_back(stoull(line));
    }
    int ret = run(original);
    if (ret == -1) {
        cout << "program didn't halt with 99, index exceeded values." << endl;
    } else {
        cout << "program halted gracefully, index 0 has the value: " << ret << endl;
    }

    //part 2
    ull target = 19690720;
    ull noun = 0;
    ull verb = 0;
    vector<ull> v(original);
    while (run(v) != target) {
        v = original;
        if (verb == 99) {
            noun++;
        }
        verb = (verb + 1) % 100;
        v[1] = noun;
        v[2] = verb;
    }
    cout << "noun: " << noun << "\nverb: " << verb << "\n100 * noun + verb: " << 100 * noun + verb << endl;

    return 0;
}
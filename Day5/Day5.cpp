#include <bits/stdc++.h>

#define ll long long
using namespace std;
//part 1 change input to 1, part2 change input to 2
vector<ll> input{5};
vector<ll> output;
int input_index = 0;

ll run(vector<ll> v) {
    long index = 0;
    while (index < v.size() && v[index] != 99) {
        string instruction = to_string(v[index]);
        ll code = instruction.size() > 1 ? stoll(instruction.substr(instruction.size() - 2)) : instruction[0] - '0';
        array<bool, 2> parameters{0, 0};
        if (code != 3 && code != 4) {
            parameters[0] = instruction.size() > 2 ? instruction[instruction.size() - 3] == '1' : 0;
            parameters[1] = instruction.size() > 3 ? instruction[instruction.size() - 4] == '1' : 0;
        } else {
            parameters[0] = instruction.size() > 2 ? instruction[instruction.size() - 3] == '1' : 0;
        }
        long first, second;
        first = parameters[0] ? v[index + 1] : v[v[index + 1]];
        second = parameters[1] ? v[index + 2] : v[v[index + 2]];
        switch (code) {
            case 1:
                //add
                v[v[index + 3]] = first + second;
                index += 4;
                break;
            case 2:
                //multiply
                v[v[index + 3]] = first * second;
                index += 4;
                break;
            case 3:
                //input
                v[v[index + 1]] = input[input_index++];
                index += 2;
                break;
            case 4:
                //output
                output.push_back(first);
                index += 2;
                break;
            case 5:
                //jump if true -2 params
                index = first != 0 ? second : index + 3;
                break;
            case 6:
                //jump if false -2 params
                index = first == 0 ? second : index + 3;
                break;
            case 7:
                //less than - 3 params
                v[v[index + 3]] = first < second ? 1 : 0;
                index += 4;
                break;
            case 8:
                //equals - 3 params
                v[v[index + 3]] = first == second ? 1 : 0;
                index += 4;
                break;
            default:
                //error
                cout << "invalid opcode: " << code << endl;
                cout << "instruction: " << instruction << endl;
                exit(-1);
        }
    }
    return index >= v.size() ? -1 : v[0];
}

int main() {
    //part 1
    freopen("input.txt", "r", stdin);
    vector<ll> original;
    string line;
    while (getline(cin, line, ',')) {
        original.push_back(stoll(line));
    }
    int ret = run(original);
    if (ret == -1) {
        cout << "program didn't halt with 99, index exceeded values." << endl;
    } else {
        cout << "program halted gracefully, index 0 has the value: " << ret << endl << "output: " << endl;
        for (auto i: output) {
            cout << i << endl;
        }
    }

    return 0;
}
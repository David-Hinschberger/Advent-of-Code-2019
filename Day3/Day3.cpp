#include <bits/stdc++.h>

using namespace std;
//{x, y} => {length}
map <pair<long, long>, long> lengths[2];

set <pair<long, long>> process(string line, int wire){
    set <pair<long, long>> s;
    long x = 0;
    long y = 0;
    long curr = 0;
    stringstream ss(line);
    while (getline(ss, line, ',')) {
        long length = stol(line.substr(1));
        switch(line[0]){
            case 'R':
                for (int i = 0; i < length; ++i) {
                    s.insert({++x, y});
                    lengths[wire].insert({{x, y}, ++curr});
                }
                break;
            case 'L':
                for (int i = 0; i < length; ++i) {
                    s.insert({--x, y});
                    lengths[wire].insert({{x, y}, ++curr});
                }
                break;
            case 'U':
                for (int i = 0; i < length; ++i) {
                    s.insert({x, ++y});
                    lengths[wire].insert({{x, y}, ++curr});
                }
                break;
            case 'D':
                for (int i = 0; i < length; ++i) {
                    s.insert({x, --y});
                    lengths[wire].insert({{x, y}, ++curr});
                }
                break;
            default:
                cout << "invalid direction: " << line[0] << endl;
                exit(-1);
        }
    }
    return s;
}


int main() {
    freopen("input.txt", "r", stdin);

    string line;

    //wire1
    getline(cin, line);
    set <pair<long, long>> wire1 = process(line, 0);

    //wire2
    getline(cin, line);
    set <pair<long, long>> wire2 = process(line, 1);

    set<pair<long, long>> intersect;
    set_intersection(wire1.begin(), wire1.end(), wire2.begin(), wire2.end(), inserter(intersect, intersect.begin()));
    long lowest = LONG_MAX;
    long wire1_len;
    long wire2_len;
    long wires_total = LONG_MAX;
    for(auto p: intersect){
        lowest = min(abs(p.first) + abs(p.second), lowest);
        long wire1 = lengths[0][p];
        long wire2 = lengths[1][p];
        if(wire1 + wire2 < wires_total){
            wires_total = wire1 + wire2;
            wire1_len = wire1;
            wire2_len = wire2;
        }
    }
    cout << "part 1: ";
    cout << lowest << endl;
    //part2
    cout << "part 2: ";
    cout << "wire1: " << wire1_len << "\nwire2: " << wire2_len << "\ntotal: " << wires_total << endl;



    return 0;
}
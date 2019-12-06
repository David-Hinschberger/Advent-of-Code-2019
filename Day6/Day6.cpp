//boilerplate for shit
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    //part 1
    string line;
    map <string, set<string>> objects;
    //p2
    unordered_set <string> vertices;

    while (getline(cin, line)) {

        stringstream ss(line);
        string a, b;
        getline(ss, a, ')');
        getline(ss, b);

        //p2
        vertices.insert({a});
        vertices.insert({b});

        auto it = objects.find(a);
        if (it == objects.end()) {
            objects.insert({a, {b}});
        } else {
            it->second.insert(b);
        }

        //p2
        it = objects.find(b);
        if (it == objects.end()) {
            objects.insert({b, {a}});
        } else {
            it->second.insert(a);
        }
    }
    //q { object, orbits }
    queue <pair<string, int>> q;
    unordered_set <string> seen;
    seen.insert("COM");
    q.push({"COM", 0});
    ull sum = 0;
    while (q.size()) {
        auto curr = q.front();
        q.pop();
        ull curr_val = curr.second;
        sum += curr_val;
        for (auto obj: objects[curr.first]) {
            if (seen.insert(obj).second) {
                q.push({obj, curr_val + 1});
            }
        }
    }
    cout << sum << endl;

    //p2
    seen.clear();
    //vertex to distance
    queue <string> Q;
    unordered_map<string, ull> distances;
    Q.push("YOU");
    for (auto vertex: vertices) {
        distances[vertex] = ULLONG_MAX;
    }
    distances["YOU"] = 0;
    cout << endl;
    while (Q.size()) {
        auto curr = Q.front();
        Q.pop();
        seen.insert(curr);
        for (auto connected_destination: objects[curr]) {
            if(seen.find(connected_destination) != seen.end()){
                continue;
            }
            Q.push(connected_destination);
            ull distance = distances[curr];
            if (distance < distances[connected_destination]) {
                distances[connected_destination] = distance + 1;
            }
        }
    }
    cout << distances["SAN"] - 2 << endl;


    return 0;
}
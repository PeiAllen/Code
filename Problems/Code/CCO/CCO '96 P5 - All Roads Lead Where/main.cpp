/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on May 4, 2019, 12:27 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

struct pa {
    char dest;
    string way;

    pa(char a, string b) : dest(a), way(b) {
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m>>n;
    unordered_map<char, vector<char> > matrix;
    string a, b;
    for (int i = 0; i < m; i++) {
        cin >> a>>b;
        matrix[a[0]].push_back(b[0]);
        matrix[b[0]].push_back(a[0]);
    }
    for (int i = 0; i < n; i++) {
        queue<pa> qu;
        cin >> a>>b;
        qu.push(pa(a[0], a.substr(0,1)));
        unordered_set<char> gone;
        gone.insert(a[0]);
        while (!qu.empty()) {
            pa cur = qu.front();
            qu.pop();
            if (cur.dest == b[0]) {
                cout << cur.way << "\n";
                break;
            }
            for (char temp : matrix[cur.dest]) {
                if(!gone.count(temp)){
                qu.push(pa(temp, cur.way + temp));
                gone.insert(temp);
                }
            }
        }
    }
    return 0;
}


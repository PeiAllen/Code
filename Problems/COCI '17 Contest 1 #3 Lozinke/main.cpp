/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on May 4, 2019, 12:11 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

struct compartor {

    bool operator()(const string& lhs, const string &rhs) {
        if (lhs.size() == rhs.size())return lhs < rhs;
        return lhs.size() < rhs.size();
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    unordered_map<string, int> pass;
    int n;
    cin>>n;
    int count = 0;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, compartor());
    for (int i = 0; i < n; i++) {
        unordered_set<string> ree;
        for (int j = 0; j < arr[i].size(); j++) {
            for (int k = 1; k <= arr[i].size()-j; k++) {
                if (pass.count(arr[i].substr(j, k))&&!ree.count(arr[i].substr(j, k))) {
                    count += pass[arr[i].substr(j, k)];
                    ree.insert(arr[i].substr(j, k));
                }
            }
        }
        if (pass.count(arr[i])) {
            count += pass[arr[i]];
        }
        pass[arr[i]] += 1;
    }
    printf("%d", count);
    return 0;
}


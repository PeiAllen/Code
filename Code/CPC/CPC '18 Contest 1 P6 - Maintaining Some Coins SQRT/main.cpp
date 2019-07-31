/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 8, 2019, 9:42 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
int maxblocksize;


struct node {
    vector<int> arr;
    unordered_map<int, int> amount;
    int prefix;

    node(int a = 0) {
        prefix = a;
    }
    bool operator<(const int& rhs) {
        return prefix<rhs;
    }
};
vector<node> sqr;
void recalc(int ind) {
    sqr[ind].amount.clear();
    for (int i : sqr[ind].arr)sqr[ind].amount[i] += 1;
}

void pre(int ind) {
    for (int i = ind + 1; i < sqr.size(); i++) {
        sqr[i].prefix = sqr[i - 1].prefix + sqr[i - 1].arr.size();
    }
}

void insert(int a, int loc) {
    if(sqr.size()==0){
        sqr.push_back(node());
    }
    int ind = (lower_bound(sqr.begin(), sqr.end(), loc+1) - sqr.begin()) - 1;
    loc -= sqr[ind].prefix;
    sqr[ind].arr.insert(sqr[ind].arr.begin() + loc, a);
    sqr[ind].amount[a] += 1;
    if (sqr[ind].arr.size() == maxblocksize * 2) {
        sqr.insert(sqr.begin() + ind + 1, node());
        for(int i=maxblocksize;i<sqr[ind].arr.size();i++)sqr[ind+1].arr.push_back(sqr[ind].arr[i]);
        sqr[ind].arr.resize(maxblocksize);
        recalc(ind);
        recalc(ind + 1);
    }
    pre(ind);
}

void del(int loc) {
    if(sqr.size()==0){
        return;
    }
    int ind = (lower_bound(sqr.begin(), sqr.end(),loc) - sqr.begin()) - 1;
    loc -= sqr[ind].prefix;
    sqr[ind].amount[sqr[ind].arr[loc-1]] -= 1;
    sqr[ind].arr.erase(sqr[ind].arr.begin()+(loc-1));
    if (sqr[ind].arr.size() == 0) {
        sqr.erase(sqr.begin() + ind);
        sqr[ind].prefix -= 1;
    }
    pre(ind);
}

int start(int a, int l, int r) {
    if(sqr.size()==0){
        return 0;
    }
    int le = (lower_bound(sqr.begin(), sqr.end(),l) - sqr.begin()) - 1;
    int ri = (lower_bound(sqr.begin(), sqr.end(),r) - sqr.begin()) - 1;
    l-=1;
    r-=1;
    int count = 0;
    if(le==ri){
        for (int i = l - sqr[le].prefix; i <= r-sqr[le].prefix; i++) {
            count += (sqr[le].arr[i] == a);
        }
    }
    else{
    if (l == sqr[le].prefix) {
        count += (sqr[le].amount.count(a) ? sqr[le].amount[a] : 0);
    } else {
        for (int i = l - sqr[le].prefix; i < sqr[le].arr.size(); i++) {
            count += (sqr[le].arr[i] == a);
        }
    }
    if (r == sqr[ri].prefix+sqr[ri].arr.size()) {
        count += (sqr[ri].amount.count(a) ? sqr[ri].amount[a] : 0);
    } else {
        for (int i = 0; i <= r-sqr[ri].prefix; i++) {
            count += (sqr[ri].arr[i] == a);
        }
    }
    for(int i=le+1;i<ri;i++){
        count += (sqr[i].amount.count(a) ? sqr[i].amount[a] : 0);
    }
    }
    return count;
}

/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, n, q;
    cin >> T >> n>>q;
    maxblocksize = ceil(sqrt((double) (n + q)));
    int in;
    for (int i = 0; i < n; i++) {
        cin>>in;
        insert(in, i);
    }
    int lastans = 0;
    char a;
    int b, c;
    for (int i = 0; i < q; i++) {
        cin>>a;
        if (a == 'I') {
            cin >> b>>c;
            if (T) {
                b ^= lastans;
                c ^= lastans;
            }
            insert(c, b);
        } else if (a == 'D') {
            cin>>b;
            if (T) {
                b ^= lastans;
            }
            del(b);
        } else {
            cin >> b >> c>>in;
            if (T) {
                b ^= lastans;
                c ^= lastans;
                in ^= lastans;
            }
            lastans = start(in, b,c);
            printf("%d\n", lastans);
        }
    }
    return 0;
}
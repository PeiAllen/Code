/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 20, 2019, 11:20 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct pa {
    lli player, moves;

    pa(lli a = 0, lli b = 0) : player(a), moves(b) {
    }
};

struct tri {
    lli player, moves;
    string board;

    tri(lli a = 0, lli b = 0, string c = "") : player(a), moves(b), board(c) {
    }
};

string convert(string a) {
    if (a == "11") {
        return "b";
    }
    if (a == "10") {
        return "a";
    }
    return a;
}

/*
 * 
 */
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n, m, k, q;
    cin >> n >> m >> k>>q;
    unordered_map<string, pa> best;
    queue<tri> qu;
    string in;
    lli xdif[4] = {1, 0, 0, -1};
    lli ydif[4] = {0, 1, -1, 0};
    if (k!=2||q!=1) {
        for (lli i = 1; i <= k; i++) {
            string cur = "";
            for (lli j = 0; j < n; j++) {
                for (lli l = 0; l < m; l++) {
                    cin>>in;
                    cur = cur + convert(in);
                }
            }
            if (!best.count(cur)) {
                best[cur] = pa(i, 0);
                qu.push(tri(i, 0, cur));
            }
        }
        while (!qu.empty()) {
            tri cur = qu.front();
            qu.pop();
            char boar[n][m];
            lli zerox = 0;
            lli zeroy = 0;
            for (lli i = 0; i < n; i++) {
                for (lli j = 0; j < m; j++) {
                    boar[i][j] = cur.board[i * m + j];
                    if (boar[i][j] == '0') {
                        zerox = i;
                        zeroy = j;
                    }
                }
            }
            for (lli i = 0; i < 4; i++) {
                lli tempx = zerox + xdif[i];
                lli tempy = zeroy + ydif[i];
                if (tempx >= 0 && tempx < n && tempy >= 0 && tempy < m) {
                    swap(boar[zerox][zeroy], boar[tempx][tempy]);
                    string has = "";
                    for (lli j = 0; j < n; j++) {
                        for (lli l = 0; l < m; l++) {
                            has = has + boar[j][l];
                        }
                    }
                    if (!best.count(has)) {
                        best[has] = pa(cur.player, cur.moves + 1);
                        qu.push(tri(cur.player, cur.moves + 1, has));
                    }
                    swap(boar[zerox][zeroy], boar[tempx][tempy]);
                }
            }
        }
        for (lli i = 0; i < q; i++) {
            string cur = "";
            for (lli j = 0; j < n; j++) {
                for (lli l = 0; l < m; l++) {
                    cin>>in;
                    cur = cur + convert(in);
                }
            }
            pa temp = best[cur];
            printf("%lli %lli\n", temp.player, temp.moves);
        }
    } else {
        queue<tri> store;
        for (lli i = 1; i <= k; i++) {
            string cur = "";
            for (lli j = 0; j < n; j++) {
                for (lli l = 0; l < m; l++) {
                    cin>>in;
                    cur = cur + convert(in);
                }
            }
            store.push(tri(i, 0, cur));
        }
        string cur = "";
        for (lli j = 0; j < n; j++) {
            for (lli l = 0; l < m; l++) {
                cin>>in;
                cur = cur + convert(in);
            }
        }
        qu.push(tri(k+1,0,cur));
        best[cur]=pa(k+1,0);
        while(!store.empty()){
            tri te=store.front();
            store.pop();
            if(!best.count(te.board)){
                best[te.board] = pa(te.player, 0);
                qu.push(te);
            }
            else if(best[te.board].player==k+1){
                printf("%lli %lli\n",te.player,0);
                return 0;
            }
        }
        lli depth=LLONG_MAX;
        lli mi=LLONG_MAX;
        lli ansmove=LLONG_MAX;
        while (!qu.empty()) {
            tri cur = qu.front();
            qu.pop();
            if(cur.moves>depth){
                break;
            }
            char boar[n][m];
            lli zerox = 0;
            lli zeroy = 0;
            for (lli i = 0; i < n; i++) {
                for (lli j = 0; j < m; j++) {
                    boar[i][j] = cur.board[i * m + j];
                    if (boar[i][j] == '0') {
                        zerox = i;
                        zeroy = j;
                    }
                }
            }
            for (lli i = 0; i < 4; i++) {
                lli tempx = zerox + xdif[i];
                lli tempy = zeroy + ydif[i];
                if (tempx >= 0 && tempx < n && tempy >= 0 && tempy < m) {
                    swap(boar[zerox][zeroy], boar[tempx][tempy]);
                    string has = "";
                    for (lli j = 0; j < n; j++) {
                        for (lli l = 0; l < m; l++) {
                            has = has + boar[j][l];
                        }
                    }
                    if (!best.count(has)) {
                        if(cur.moves<depth){
                            best[has] = pa(cur.player, cur.moves + 1);
                            qu.push(tri(cur.player, cur.moves + 1, has));
                        }
                    }
                    else if(max(best[has].player,cur.player)==k+1&&min(best[has].player,cur.player)<=k){
                        depth=cur.moves;
                        if(ansmove>=cur.moves+1+best[has].moves){
                        mi=min(mi,min(best[has].player,cur.player));
                        ansmove=cur.moves+1+best[has].moves;
                        }
                    }
                    swap(boar[zerox][zeroy], boar[tempx][tempy]);
                }
            }
        }
        printf("%lli %lli\n",mi,ansmove);
    }
    return 0;
}
/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 20, 2019, 11:20 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

struct pa {
    int player, moves;

    pa(int a = 0, int b = 0) : player(a), moves(b) {
    }
};

struct tri {
    int player, moves;
    string board;

    tri(int a = 0, int b = 0, string c = "") : player(a), moves(b), board(c) {
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
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, k, q;
    cin >> n >> m >> k>>q;
    unordered_map<int, pa> best;
    queue<tri> qu;
    string in;
    for (int i = 1; i <= k; i++) {
        string cur = "";
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                cin>>in;
                cur = cur + convert(in);
            }
        }
        if (!best.count(cur)) {
            best[cur] = pa(i, 0);
            qu.push(tri(i, 0, cur));
        }
    }
    int xdif[4] = {1, 0, 0, -1};
    int ydif[4] = {0, 1, -1, 0};
    while (!qu.empty()) {
        tri cur = qu.front();
        qu.pop();
        char boar[n][m];
        int zerox = 0;
        int zeroy = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                boar[i][j] = cur.board[i * n + j];
                if (boar[i][j] == '0') {
                    zerox = i;
                    zeroy = j;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int tempx = zerox + xdif[i];
            int tempy = zeroy + ydif[i];
            if (tempx >= 0 && tempx < n && tempy >= 0 && tempy < m) {
                swap(boar[zerox][zeroy], boar[tempx][tempy]);
                string has = "";
                for (int j = 0; j < n; j++) {
                    for (int l = 0; l < m; l++) {
                        has = has + boar[j][l];
                    }
                }
                if(!best.count(has)){
                    best[has]=pa(cur.player,cur.moves+1);
                    qu.push(tri(cur.player,cur.moves+1,has));
                }
                swap(boar[zerox][zeroy], boar[tempx][tempy]);
            }
        }
    }
    for(int i=0;i<q;i++){
        string cur = "";
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                cin>>in;
                cur = cur + convert(in);
            }
        }
        pa temp=best[cur];
        printf("%d %d\n",temp.player,temp.moves);
    }
    return 0;
}



//#include "testlib.h"
#include "bits/stdc++.h"
#include <iostream>
#include <assert.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

const string C = "WR.";

int main(int argc, char *argv[]) {
//    registerGen(argc, argv, 1);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int t = 81;

    cout << (t) << '\n';
    for (auto i = 0; i < t; i++) {
        if(i+1==57){
            cout<<"wtfdude\n";
        }
        cout << (2) << ' ' << (2) << '\n';
        string s;
        int ci = i;
        for (auto j = 0; j < 4; j++) {
            s += C[ci % 3];
            ci /= 3;
        }
        int ctr = 0;
        for (auto j = 0; j < 2; j++) {
            for (auto k = 0; k < 2; k++){
                cout << s[ctr++];
            }
            cout << '\n';
        }
    }
}

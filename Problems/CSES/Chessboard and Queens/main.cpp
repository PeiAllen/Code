#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
bool bad[8][8];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> permu;
    char a;
    for(int i=0;i<8;i++){
        permu.push_back(i);
        for(int j=0;j<8;j++){
            cin>>a;
            if(a=='*')bad[i][j]=true;
        }
    }
    int ways=0;
    do{
        bool work=true;
        set<int> bada,badb;
        for(int i=0;i<8;i++){
            work&=!bad[i][permu[i]];
            bada.insert(i+permu[i]);
            badb.insert(i-permu[i]);
        }
        if(work&&sz(bada)==8&&sz(badb)==8)ways++;
    }while(next_permutation(permu.begin(),permu.end()));
    printf("%d\n",ways);
    return 0;
}
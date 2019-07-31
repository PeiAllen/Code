#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cur=3;
    set<int> mods;
    vector<int> mod;
    while(!mods.count(cur)){
    	mods.insert(cur);
    	mod.push_back(cur);
    	cur*=3;
    	cur%=1000;
    }
    printf("%d\n",mods.size());
    for(int i:mod)printf("%d\n",i);
    return 0;
}
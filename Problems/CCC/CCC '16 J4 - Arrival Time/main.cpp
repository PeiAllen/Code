#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    int time=stoi(a.substr(0,2))*60+stoi(a.substr(3,2));
    for(int dist=240;dist>0;time++){
        time%=(24*60);
        if((time>=7*60&&time<10*60)||(time>=15*60&&time<19*60))dist-=1;
        else dist-=2;
    }
    time%=(24*60);
    printf("%02d:%02d\n",time/60,time%60);
    return 0;
}
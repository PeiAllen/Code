#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
int arr[MAXN];
struct seg{
    int t[2*MAXN];
    void maketree(int ind, int le, int ri){
        if(le==ri){
            t[ind]=arr[le];
            return;
        }
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,c;
    cin>>n>>c;

    return 0;
}
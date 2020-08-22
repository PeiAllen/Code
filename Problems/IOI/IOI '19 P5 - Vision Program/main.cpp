#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
int cnt;
int mem[(int)2e6+1];
int add_not(int N){}
int add_and(std::vector<int> Ns){
    assert(sz(Ns));
    mem[cnt]=1;
    for(auto x:Ns){
        mem[cnt]&=mem[x];
        assert(x>=0&&x<cnt);
    }
    return cnt++;
}
int add_or(std::vector<int> Ns){
    assert(sz(Ns));
    for(auto x:Ns){
        mem[cnt]|=mem[x];
        assert(x>=0&&x<cnt);
    }
    return cnt++;
}
int add_xor(std::vector<int> Ns){
    assert(sz(Ns));
    for(auto x:Ns){
        mem[cnt]^=mem[x];
        assert(x>=0&&x<cnt);
    }
    return cnt++;
}
int h,w,k,n;
vector<int> arr[2],parr[2],sarr[2];
int teans[2][2];
int cp(int x, int y){
    return (x+y)/2*w+(y-x)/2;
}
int check(int rot, int dist){
    vector<int> te;
    for(int i=0;i+dist<n;i++){
        te.push_back(add_and({parr[rot][i],sarr[rot][i+dist]}));
    }
    if(sz(te)==0){
        for(int i=0;i<h*w;i++)te.push_back(i);
        return add_xor(te);
    }
    return add_or(te);
}
void construct_network(int H, int W, int K){
    h=H,w=W,k=K;
    cnt=h*w;
    for(int rot=0;rot<=1;rot++) {
        int l = (rot?0:w - 1), r = (rot?0:w - 1);
        for (int i = (rot?0:-(w - 1)); i <= (rot?h-1+w-1:h - 1); i++) {
            vector<int> te;
            for (int j = l; j <= r; j += 2) {
                te.push_back(rot?cp(j,i):cp(i, j));
            }
            arr[rot].push_back(add_or(te));
            if (i >= (rot?w-1:-(w - 1) + (w - 1)))l += 1;
            else l -= 1;
            if (i >= (rot?h-1:-(w - 1) + (h - 1)))r -= 1;
            else r += 1;
        }
        n = sz(arr[rot]);
        parr[rot].push_back(add_or({arr[rot][0]}));
        for (int i = 1; i < n; i++) {
            parr[rot].push_back(add_or({parr[rot].back(), arr[rot][i]}));
        }
        sarr[rot].resize(n);
        sarr[rot][n - 1] = add_or({arr[rot].back()});
        for (int i = n - 2; i >= 0; i--) {
            sarr[rot][i]=add_or({sarr[rot][i + 1], arr[rot][i]});
        }
        teans[rot][0] = check(rot, k + 1), teans[rot][1] = check(rot, k);
    }
    int bad=add_or({teans[0][0],teans[1][0]}),good=add_or({teans[0][1],teans[1][1]});
    add_xor({bad,good});
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mem[0]=1,mem[1]=1;
    construct_network(2,3,1);
    printf("%d\n",mem[cnt-1]);
    return 0;
}
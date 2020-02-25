#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli mod=1e9+7;
pii arr[MAXN];
lli bit[11][MAXN];
lli precalc[11];
lli dp[11][11];
lli fix(lli a){
    while(a<0)a+=mod;
    return a%mod;
}
lli choose(int a, int b){
    if(a==b||b==0)return 1;
    if(dp[a][b]!=-1)return dp[a][b];
    return dp[a][b]=fix(choose(a-1,b-1)+choose(a-1,b));
}
vector<int> coord;
void update(int ind, int loc, lli am){
    for(;loc<=sz(coord);loc+=loc&-loc){
        bit[ind][loc]=fix(bit[ind][loc]+am);
    }
}
lli query(int ind, int loc){
    lli sum=0;
    for(;loc>0;loc-=loc&-loc){
        sum=fix(sum+bit[ind][loc]);
    }
    return sum;
}
lli fastpow(lli a,lli b){
    lli ans=1;
    for(lli i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
//    freopen("help.in", "r", stdin);
//    freopen("help.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    set<int> ends;
    precalc[0]=1;
    for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)dp[i][j]=-1;
    for(int i=1;i<=k;i++){
        precalc[i]=precalc[i-1]*2%mod;
    }
    ends.insert(0);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        ends.insert(arr[i].second);
    }
    sort(arr,arr+n);
    lli anst=0;
    for(int i=0;i<(1<<n);i++){
        lli am=0;
        int last=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                if(arr[j].first>last){
                    am++;
                }
                last=max(arr[j].second,last);
            }
        }
        anst=fix(anst+fastpow(am,k));
    }
    printf("%lli\n",anst);
    for(int x:ends)coord.push_back(x);
    update(k,1,1);
    lli ans=0;
    for(int i=0;i<n;i++){
        int cur=(lower_bound(coord.begin(),coord.end(),arr[i].first)-coord.begin())+1;
        int en=(lower_bound(coord.begin(),coord.end(),arr[i].second)-coord.begin())+1;
        lli te;
        for(int j=sz(coord);j>=cur;j--){
            te=fix(query(0,j)-query(0,j-1));//right query
            ans=fix(ans+te);
            update(0,max(j,en),te);//right ans update
            for(int l=1;l<=k;l++) {
                update(l,max(j,en),fix(query(l,j)-query(l,j-1)));//right move update
            }
        }
        for(int j=0;j<=k;j++){
            te=fix(choose(k,j)*query(j,cur-1));//left query
            ans=fix(ans+te);
        }
        for(int j=k;j>=0;j--){
            for(int l=0;l<=k-j;l++) {
                update(j, en, fix(choose(k-j,l)*query(k-l,cur-1)));//left move update
            }
        }
    }
    printf("%lli\n",ans);
    return 0;
}
/*
3 2
1 2
2 3
3 4

4 2
1 2
2 3
3 4
4 5

4 2
1 4
2 3
6 7
1 7

7 2
1 2
3 5
1 2
3 10
7 12
3 100
20 30

5 2
1 2
3 5
1 2
3 10
7 12

6 2
1 2
3 5
1 2
3 10
7 12
20 30

4 2
1 2
3 4
5 6
7 8
 */
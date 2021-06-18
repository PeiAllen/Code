#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
vector<int> diag[2*MN];
vector<int> opdiag[2*MN];
vector<pair<pii,pii>> toelim[2*MN];
vector<pair<pii,pii>> toelimright[MN];
vector<pair<pii,pii>> toelimup[MN];
int bit[MN],n;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
vector<pair<pii,int>> lup[MN+2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k,a,b;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        diag[a+b-2].push_back(a);
        opdiag[a-b+n].push_back(a);
    }
    vector<pair<pii,pii>> updates;
    for(int i=0;i<=n+n-2;i++){
        sort(diag[i].begin(),diag[i].end());
        int last=-2,size=0;
        for(auto x:diag[i]){
            if(x==last+1)size++;
            else{
                if(last!=-2) {
                    updates.push_back({{(i - (last - size + 1) + 2==n?1:last - size + 1), last},{(last==n?1:i - last + 2),i - (last - size + 1) + 2}});
                    toelim[i + 1].push_back(updates.back());
                }
                size=1;
            }
            last=x;
        }
        if(last!=-2) {
            updates.push_back({{(i - (last - size + 1) + 2==n?1:last - size + 1), last},{(last==n?1:i - last + 2),    i - (last - size + 1) + 2}});
            toelim[i + 1].push_back(updates.back());
        }
    }
    for(int i=1;i<=n+n-1;i++){
        sort(opdiag[i].begin(),opdiag[i].end());
        int last=-2,size=0;
        for(auto x:opdiag[i]){
            if(x==last+1)size++;
            else{
                if(last!=-2) {
                    if(last-i+n==n) {
                        updates.push_back({{1,last},{last-size+1-i+n,n}});
                        toelimup[last-size+1].push_back(updates.back());
                    }
                    else if(last==n){
                        updates.push_back({{last-size+1,n},{1,last-i+n}});
                        toelimright[last-size+1-i+n].push_back(updates.back());
                    }
                }
                size=1;
            }
            last=x;
        }
        if(last!=-2) {
            if(last-i+n==n) {
                updates.push_back({{1,last},{last-size+1-i+n,n}});
                toelimup[last-size+1].push_back(updates.back());
            }
            else if(last==n){
                updates.push_back({{last-size+1,n},{1,last-i+n}});
                toelimright[last-size+1-i+n].push_back(updates.back());
            }
        }
    }
    for(auto x:updates){
        lup[x.first.first].push_back({x.second,1});
        lup[x.first.second+1].push_back({x.second,-1});
    }
    int xloc=1;
    for(auto x:lup[1])update(x.first.first,x.second),update(x.first.second+1,-x.second);
    for(auto x:toelim[1]){
        if(x.first.first<=xloc)update(x.second.first,-1),update(x.second.second+1,1);
        else lup[x.first.first].push_back({x.second,-1});
        if(x.first.second+1<=xloc)update(x.second.first,1),update(x.second.second+1,-1);
        else lup[x.first.second+1].push_back({x.second,1});
    }
    for(auto x:toelimup[xloc]){
        if(x.first.first<=xloc)update(x.second.first,-1),update(x.second.second+1,1);
        else lup[x.first.first].push_back({x.second,-1});
        if(x.first.second+1<=xloc)update(x.second.first,1),update(x.second.second+1,-1);
        else lup[x.first.second+1].push_back({x.second,1});
    }
    for(auto x:toelimright[1]){
        if(x.first.first<=xloc)update(x.second.first,-1),update(x.second.second+1,1);
        else lup[x.first.first].push_back({x.second,-1});
        if(x.first.second+1<=xloc)update(x.second.first,1),update(x.second.second+1,-1);
        else lup[x.first.second+1].push_back({x.second,1});
    }
    if(query(1)){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for(int i=1;i<=n+n-2;i++){
        for(auto x:toelim[i]){
            if(x.first.first<=xloc)update(x.second.first,-1),update(x.second.second+1,1);
            else lup[x.first.first].push_back({x.second,-1});
            if(x.first.second+1<=xloc)update(x.second.first,1),update(x.second.second+1,-1);
            else lup[x.first.second+1].push_back({x.second,1});
        }
        if(i-xloc+2>n||query(i-xloc+2)){
            xloc++;
            printf("U");
            for(auto x:lup[xloc])update(x.first.first,x.second),update(x.first.second+1,-x.second);
            for(auto x:toelimup[xloc]){
                if(x.first.first<=xloc)update(x.second.first,-1),update(x.second.second+1,1);
                else lup[x.first.first].push_back({x.second,-1});
                if(x.first.second+1<=xloc)update(x.second.first,1),update(x.second.second+1,-1);
                else lup[x.first.second+1].push_back({x.second,1});
            }
            if(query(i-xloc+2)!=0){
                printf("fds\n");
//                assert(0);
                return 0;
            }
        }
        else{
            printf("R");
            for(auto x:toelimright[i-xloc+2]){
                if(x.first.first<=xloc)update(x.second.first,-1),update(x.second.second+1,1);
                else lup[x.first.first].push_back({x.second,-1});
                if(x.first.second+1<=xloc)update(x.second.first,1),update(x.second.second+1,-1);
                else lup[x.first.second+1].push_back({x.second,1});
            }
            if(query(i-xloc+2)!=0){
                printf("fds\n");
//                assert(0);
                return 0;
            }
        }
    }
    printf("\n");
    return 0;
}